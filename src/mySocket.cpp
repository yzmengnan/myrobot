#include "Mysocket.h"

auto Mysocket::build_socket() -> int
{
    WSADATA wsaData;

    auto ListenSocket = INVALID_SOCKET;
    auto ClientSocket = INVALID_SOCKET;

    struct addrinfo* result = nullptr;
    struct addrinfo hints;
    int iResult;
    int iSendResult;

    // Initialize Winsock
    iResult = WSAStartup(MAKEWORD(2, 2), &wsaData);
    if (iResult != 0) {
        printf("WSAStartup failed with error: %d\n", iResult);
        return 1;
    }

    ZeroMemory(&hints, sizeof(hints));
    hints.ai_family = AF_INET;
    hints.ai_socktype = SOCK_STREAM;
    hints.ai_protocol = IPPROTO_TCP;
    hints.ai_flags = AI_PASSIVE;

    // Resolve the server address and port
    iResult = getaddrinfo(nullptr, DEFAULT_PORT, &hints, &result);
    if (iResult != 0) {
        printf("getaddrinfo failed with error: %d\n", iResult);
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
    iResult = bind(ListenSocket, result->ai_addr, (int)result->ai_addrlen);
    if (iResult == SOCKET_ERROR) {
        printf("bind failed with error: %d\n", WSAGetLastError());
        freeaddrinfo(result);
        closesocket(ListenSocket);
        WSACleanup();
        return 1;
    }

    freeaddrinfo(result);
    std::cout << "start listening!" << std::endl;
    iResult = listen(ListenSocket, SOMAXCONN);
    if (iResult == SOCKET_ERROR) {
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

void Mysocket::mysocket_recv(std::vector<DTS>& sdata)
{
    while (iResult > 0) {
        std::array<char, DEFAULT_BUFLEN> recvbuf;
        iResult = recv(mysocket, &recvbuf.front(), DEFAULT_BUFLEN, 0);
        if (iResult > 0) {
            auto temp = (float*)&recvbuf.front();
            int iter = 0;
            th_mutex.lock();
            for (auto& child_servo : sdata) {
                child_servo.Target_Pos = dp::t2p(temp[iter]);
                iter++;
            }
            th_mutex.unlock();
            std::cout << temp[0] << "," << temp[1] << std::endl;
        }
    }
    iResult = -1;
}
void Mysocket::mysocket_send()
{
    std::vector<DFS> gdata(2);
    std::vector<float> temp;
    std::vector<uint8_t*> senddata(gdata.size());
    while (iResult > 0) {
        myads.get(gdata);
        temp = dp::sreal_2j(gdata);
        for (int i = 0; i < gdata.size(); i++) {
            senddata[i] = (uint8_t*)&temp[i];
        }
        iResult = send(mysocket, (char*)senddata.front(), DEFAULT_BUFLEN, 0);
        Sleep(2);
    }
    iResult = -1;
}
