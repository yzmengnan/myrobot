
#include <iostream>
#include <mutex>
#include <thread>
#include <vector>
#include "string.h"
// MYdemo headers
#include "ADS.h"
#include "ReadTXT.hpp"
#include "Servo_Driver.h"
#include "TimerCounter.h"
// Gloabl varible
std::atomic_int s_err(1);

std::atomic_int run_flag(0);//0：无使能，1：使能，2：PP连续运动，3：CSP运动

std::mutex th_mutex;

ads myads;

auto main() -> int {

//    Mysocket server;
//    server.build_socket();

    sd myservo(myads);
    myThreadfuc mt;

    std::vector<DTS> sdata(Servo_number);
    std::vector<DFS> gdata(Servo_number);
    std::vector<float> Joint(Servo_number);


    ReadTxT txt;
    std::vector<std::vector<std::string>> local_data, ans;
    string path = R"(C:\Users\LR\OneDrive\Demo0\Data\test_data.txt)";
    local_data = txt.read_from_file(ans, path);
    std::cout << stof(local_data[2][1]);
    TimerCounter tc;


    myservo.Servo_On(sdata, gdata);
    for (auto &child_servo: sdata) {
        child_servo.Mode_of_Operation = 8;
        child_servo.Target_Pos=0;
        child_servo.Max_Velocity=500;
    }

    myads.set(sdata);
    Sleep(2000);
    int mark = 1;
    while (1) {
        if (mark) {
            tc.Start();
            local_data.erase(local_data.begin());//删除第一行
            if (local_data.empty()) {
                break;
            } else {
                for (int i = 0; i < Servo_number; i++) {
                    sdata[i].Target_Pos = dp::t2p(stof(local_data[0][i+1]), i);
                }
                s_err = myads.get(gdata);
                for (int i = 0; i < Servo_number; i++) {
                    sdata[i].Max_Velocity = int(
                            double(abs(gdata[i].Actual_Pos - sdata[i].Target_Pos) * 0.0000502324885));
                }
                s_err = myads.set(sdata);
                mark = 0;
            }
        }
        tc.Stop();
        if (tc.dbTime * 1000 > 10) {
            mark = 1;
            std::cout << "send!"<<sdata[0].Max_Velocity<<","<<sdata[1].Max_Velocity << std::endl;
        }
    }





//
////    bool *s_t_flag = new bool(true);
//    // std::thread s_t(mt::status_print, s_t_flag, 10);
//    // s_t.detach();
//
//    std::thread socket_get(&Mysocket::mysocket_recv2, &server, std::ref(sdata));
//    socket_get.detach();
////
//    std::thread drive(&myThreadfuc::DRIVE, &mt, std::ref(run_flag), std::ref(sdata), std::ref(gdata), myservo);
//    drive.detach();
//    std::thread socket_send(&Mysocket::mysocket_send, &server, std::ref(myads));
//    socket_send.detach();
//    while (TRUE) {
//        if (s_err <= 0) {
//            std::cout << "System Error:" << s_err << std::endl;
//            run_flag = 0;
//            break;
//        }
//    }
//    myservo.Servo_Off(sdata, gdata);
//    return 0;
}