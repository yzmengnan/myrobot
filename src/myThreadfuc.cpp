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

void mt::tc(int *const flag, int breakout_value) {
    // std::cout << "Timer counting" << std::endl;
    std::this_thread::sleep_for(std::chrono::milliseconds(breakout_value));
    *flag = 0;
}

void mt::status_print(bool *flag, const int cycletime) {
    std::vector<DFS> gdata(2);
    while (s_err >= 0 && flag) {
        std::this_thread::sleep_for(std::chrono::milliseconds(cycletime));
        // Sleep(cycletime);
        // th_mutex.lock();
        s_err = myads.get(gdata);
        if (s_err < 0) {
            std::cout << "status_print get data error!" << std::endl;
        }
        // th_mutex.unlock();
        int joint_number = 0;
        for (DFS child_servo: gdata) {
            std::cout << "Joint" << joint_number << " " << dp::p2t(child_servo.Actual_Pos) << ",  ";
            joint_number++;
        }
        std::cout << std::endl;
        // std::cout << "status_print,ok!" << std::endl;
    }
}