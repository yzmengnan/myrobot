/*
 * @Author: YangQ
 * @Date: 2023-02-28 16:43:54
 * @LastEditors: YangQ
 * @LastEditTime: 2023-03-08 11:10:46
 * @FilePath: \Demo0\SRC\myThreadfuc.cpp
 * @Description:
 *
 * Copyright (c) 2023 by YangQ, All Rights Reserved.
 */
#include "myThreadfuc.h"

void mt::tc(int *flag, int breakout_value) {
    // std::cout << "Timer counting" << std::endl;
    std::this_thread::sleep_for(std::chrono::milliseconds(breakout_value));
    *flag = 0;
}

[[maybe_unused]] void mt::status_print(const bool *flag, int cycletime, ads myads) {
    std::vector<DFS> gdata(Servo_number);
    while (s_err >= 0 && flag) {
        std::this_thread::sleep_for(std::chrono::milliseconds(cycletime));
        s_err = myads.get(gdata);
        if (s_err < 0) {
            std::cout << "status_print get data error!" << std::endl;
        }
        int joint_number = 0;
        for (DFS child_servo: gdata) {
            std::cout << "Joint" << joint_number << " " << dp::p2t(child_servo.Actual_Pos, joint_number) << ", ";
            joint_number++;
        }
        std::cout << std::endl;
        // std::cout << "status_print,ok!" << std::endl;
    }
}

void myThreadfuc::DRIVE(std::atomic_int &runflag, std::vector<DTS> &sdata, std::vector<DFS> &gdata, sd &myservo) {
    int servo_on_mark = 1;
    int servo_off_mark = 0;
    int servo_csp_flag = 0;
    while (true) {
        //        cout<<"Drive Working!"<<endl;
        //runflag只要大于等于1，即允许使能
        if (runflag && servo_on_mark) {
            error_code = myservo.Servo_On(sdata, gdata);
            servo_on_mark = 0;
            servo_off_mark = 1;
            servo_csp_flag = 1;//使能开启后，才允许启动CSP，且CSP会关闭该标志位，直至重新使能才会使该标志置1
        } else if (runflag == 0 && servo_off_mark) {
            error_code = myservo.Servo_Off(sdata);
            servo_off_mark = 0;
            servo_on_mark = 1;
        }
        // runflag==2 ，启动pp运行模式
        else if (runflag == 2) {
            error_code = myservo.Servo_PTP_Basic_isSync(sdata, gdata, CIOFF, 1);
            std::cout << "DRIVE MODE:" << runflag << std::endl;
//            std::cout << "Target_position:" << sdata[0].Target_Pos << "," << sdata[1].Target_Pos << std::endl;
            //检查是否因为此处延时导致PP lag现象
            std::this_thread::sleep_for(std::chrono::milliseconds(200));
        } else if (runflag == 3 && servo_csp_flag) {
            std::cout << "DRIVE MODE:" << runflag << std::endl;
            std::cout << "START CSP PROGRAM" << std::endl;
            error_code = myservo.Servo_CSP(sdata, gdata, filename);
            servo_csp_flag = 0;
        }
        if (error_code < 0) {
            cout << "Drive Break out! Error:" << error_code << endl;
            s_err = error_code;
            break;
        }
    }
}
