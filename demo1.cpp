
#include <iostream>
#include <mutex>
#include <thread>
#include <vector>
// MYdemo headers
#include "Mysocket.h"
#include "ADS.h"
#include "ReadTXT.hpp"
#include "Servo_Driver.h"
#include "TimerCounter.h"
// DIO headers

// Gloabl varible
std::atomic_int s_err(1);

std::atomic_int run_flag(0);//0,默认，1：PP控制启动，2：PP连续运动，3：CSP运动

std::mutex th_mutex;

ads myads;

auto main() -> int {
//    ReadTxT txt;
//    std::vector<std::vector<std::string>> local_data, ans;
//    string path = R"(C:\Users\LR\OneDrive\Demo0\Data\test_data.txt)";
//    local_data = txt.read_from_file(ans, path);
    // std::cout << stof(local_data[2][1]);
    //
    sd myservo(myads);
    myThreadfuc mt;
    Mysocket server;
    server.build_socket();
    std::vector<DTS> sdata(Servo_number);
    std::vector<DFS> gdata(Servo_number);
    std::vector<float> Joint(Servo_number);

//    bool *s_t_flag = new bool(true);
    // std::thread s_t(mt::status_print, s_t_flag, 10);
    // s_t.detach();

    std::thread socket_get(&Mysocket::mysocket_recv2, &server, std::ref(sdata));
    socket_get.detach();
//
    std::thread drive(&myThreadfuc::DRIVE, &mt, std::ref(run_flag), std::ref(sdata), std::ref(gdata), myservo);
    drive.detach();
    std::thread socket_send(&Mysocket::mysocket_send, &server, std::ref(myads));
    socket_send.detach();
    while (TRUE) {
        if (s_err <= 0) {
            std::cout << "System Error:" << s_err << std::endl;
            run_flag = 0;
            break;
        }
    }
    myservo.Servo_Off(sdata, gdata);
    return 0;
}