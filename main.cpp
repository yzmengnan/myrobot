/*
 * @Author: YangQ
 * @Date: 2023-02-27 10:32:44
 * @LastEditors: YangQ
 * @LastEditTime: 2023-03-08 21:30:52
 * @FilePath: \Demo0\main.cpp
 * @Description:
 *
 * Copyright (c) 2023 by YangQ, All Rights Reserved.
 */
#include <iostream>
#include <mutex>
#include <thread>
#include <vector>
#include <winsock2.h>
// MYdemo headers
#include "ADS.h"
#include "Data_Process.h"
#include "Mysocket.h"
#include "ReadTXT.hpp"
#include "Servo_Driver.h"
#include "TimerCounter.h"
//#include "variable.h"
// DIO headers

// Gloabl varible
std::atomic_int s_err(1);

std::atomic_int run_flag(1);//0,默认，1：PP控制启动，2：PP连续运动，3：CSP运动

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

//    s_err = myservo.Servo_On(sdata, gdata);

    bool *s_t_flag = new bool(true);
    // std::thread s_t(mt::status_print, s_t_flag, 10);
    // s_t.detach();

    std::thread socket_get(&Mysocket::mysocket_recv2, &server, std::ref(sdata));
    socket_get.detach();

    std::thread drive(&myThreadfuc::DRIVE, &mt, std::ref(run_flag), std::ref(sdata), std::ref(gdata), myservo);
    drive.detach();
//    std::thread socket_send(&Mysocket::mysocket_send, &server);
//    socket_send.detach();
    /*
    while (true) {
        // 调用关节角
        Joint = dp::starget_2j(sdata);
        s_err = myservo.Servo_PTP_Joint_isSync(Joint, sdata, gdata, 100);
        // 或者
        //  s_err = myservo.Servo_PTP_Basic_isSync(sdata, gdata, CIOFF, 100);
        if (s_err < 0) {
            std::cout << "System Error! Check Error Code: " << s_err << std::endl;
            break;
        }
        s_err = server.iResult;
        if (s_err <= 0) {
            std::cout << "System Error! Check Error Code: " << s_err << std::endl;
            break;
        }
    }
    s_err = myservo.Servo_Off(sdata, gdata);
     */
    while (1) {
        if(s_err<=0){
            std::cout<<"System Error:"<<s_err<<std::endl;
            run_flag=0;
            break;
        }
    }
    return 0;
}