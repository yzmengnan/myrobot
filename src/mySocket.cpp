#include "Mysocket.h"

auto Mysocket::build_socket() -> int {
    WSADATA wsaData;

    auto ListenSocket = INVALID_SOCKET;
    auto ClientSocket = INVALID_SOCKET;

    struct addrinfo *result = nullptr;
    struct addrinfo hints{};
    int iResult_local;
    [[maybe_unused]] int iSendResult;

    // Initialize Winsock
    iResult_local = WSAStartup(MAKEWORD(2, 2), &wsaData);
    if (iResult_local != 0) {
        printf("WSAStartup failed with error: %d\n", iResult_local);
        return 1;
    }

    ZeroMemory(&hints, sizeof(hints));
    hints.ai_family = AF_INET;
    hints.ai_socktype = SOCK_STREAM;
    hints.ai_protocol = IPPROTO_TCP;
    hints.ai_flags = AI_PASSIVE;

    // Resolve the server address and port
    iResult_local = getaddrinfo(nullptr, DEFAULT_PORT, &hints, &result);
    if (iResult_local != 0) {
        printf("getaddrinfo failed with error: %d\n", iResult_local);
        WSACleanup();
        return 1;
    }

    // Create a SOCKET for the server to listen for client connections.
    ListenSocket = socket(result->ai_family, result->ai_socktype, result->ai_protocol);
    if (ListenSocket == INVALID_SOCKET) {
        printf("socket failed with error: %d\n", WSAGetLastError());
        freeaddrinfo(result);
        WSACleanup();
        return 1;
    }

    //  Set up the TCP listening socket
    iResult_local = bind(ListenSocket, result->ai_addr, (int) result->ai_addrlen);
    if (iResult_local == SOCKET_ERROR) {
        printf("bind failed with error: %d\n", WSAGetLastError());
        freeaddrinfo(result);
        closesocket(ListenSocket);
        WSACleanup();
        return 1;
    }

    freeaddrinfo(result);
    std::cout << "start listening!" << std::endl;
    iResult_local = listen(ListenSocket, SOMAXCONN);
    if (iResult_local == SOCKET_ERROR) {
        printf("listen failed with error: %d\n", WSAGetLastError());
        closesocket(ListenSocket);
        WSACleanup();
        return 1;
    }

    // Accept a client socket
    ClientSocket = accept(ListenSocket, nullptr, nullptr);
    if (ClientSocket == INVALID_SOCKET) {
        printf("accept failed with error: %d\n", WSAGetLastError());
        closesocket(ListenSocket);
        WSACleanup();
        return 1;
    }
    std::cout << "ListenSocket Success, Server Socket has been built!" << std::endl;
    // No longer need server socket
    closesocket(ListenSocket);
    mysocket = ClientSocket;
    return 0;
}

[[maybe_unused]] void Mysocket::mysocket_recv(std::vector<DTS> &sdata) {
    while (iResult > 0) {
        std::array<char, DEFAULT_BUFLEN> recvbuf{};
        iResult = recv(mysocket, &recvbuf.front(), DEFAULT_BUFLEN, 0);
        if (iResult > 0) {
            auto temp = (float *) &recvbuf.front();
            int iter = 0;
            th_mutex.lock();
            for (auto &child_servo: sdata) {
                child_servo.Target_Pos = dp::t2p(temp[iter], iter);
                iter++;
            }
            th_mutex.unlock();
            std::cout << temp[0] << "," << temp[1] << std::endl;
        }
    }
    iResult = -1;
}

void Mysocket::mysocket_recv2(std::vector<DTS> &sdata) {
    std::array<char, DEFAULT_BUFLEN> recvbuf{};
    while (iResult > 0) {
        iResult = recv(mysocket, &recvbuf.front(), DEFAULT_BUFLEN, 0);
        if (iResult > 0) {
            recvdata.Head_check = (int *) &recvbuf.front() + recvdata.Head_check_location;
            recvdata.Command = (int *) &recvbuf.front() + recvdata.Command_location;
            recvdata.Joint_Position_set = (float *) &recvbuf.front() + recvdata.Joint_Position_set_location;
            recvdata.Joint_Velocity_set = (float *) &recvbuf.front() + recvdata.Joint_Velocity_set_location;
            recvdata.Cartesian_Position = (float *) &recvbuf.front() + recvdata.Cartesian_Position_location;
            recvdata.Cartesian_Velocity_set = (float *) &recvbuf.front() + recvdata.Cartesian_Velocity_set_location;
            recvdata.Tail_check = (int *) &recvbuf.front() + recvdata.Tail_check_location;
            std::vector<float> jointdata(recvdata.Joint_Position_set, recvdata.Joint_Position_set + Servo_number);
            if (*recvdata.Command & 0b10) //BIT1为1，则上使能
            {
                run_flag = 1;
                //Bit2为1，表示PP运动，仅在此状态下，更新sdata以满足PP需要
                if (*recvdata.Command & 0b100) {
                    run_flag = 2;
                    th_mutex.lock();
                    dp::j2s(jointdata, sdata);
                    th_mutex.unlock();
                }
                    //BIT3为1，则CSP模式，runflag为3
                //csp模式，暂定使用下位机离线数据
                else if (*recvdata.Command & 0b1000) {
                    run_flag = 3;
                }
            } else {
                run_flag = 0;
            }
//            std::cout << "Receive Socket data:" << "Head_Check:" << recvdata.Head_check[0] << ",Command:"
//                      << recvdata.Command[0];
//            for (int i = 0; i < Servo_number; i++) {
//                std::cout << recvdata.Joint_Position_set[i] << ",";
//            }
//            std::cout << std::endl;
        }
    }
    std::cout << "Socket Communication Error:" << iResult << std::endl;
    s_err = -1;
}

//待修改，需要完善服务器数据报文
void Mysocket::mysocket_send(ads &myads_local) {
    std::vector<DFS> gdata(Servo_number);
    std::vector<float> temp(Servo_number);
    std::vector<float> position(Servo_number);
    std::vector<uint8_t *> senddata(gdata.size());
    while (iResult > 0) {
        myads_local.get(gdata);// Servo Data has been collected!
        temp = dp::sreal_2j(gdata); // temp equals joint data
        position = MOTION::joint2position(temp);// C_position data
        for (int i = 0; i < gdata.size(); i++) {
            senddata[i] = (uint8_t *) &temp[i];
        }
        std::this_thread::sleep_for(std::chrono::milliseconds(50));
        iResult = send(mysocket, (char *) senddata.front(), 4 * Servo_number, 0);
    }
    iResult = -1;
}
