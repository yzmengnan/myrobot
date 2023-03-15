/*
 * @Author: YangQ
 * @Date: 2023-02-27 15:24:59
 * @LastEditors: YangQ
 * @LastEditTime: 2023-03-08 21:37:30
 * @FilePath: \Demo0\INC\Servo_Driver.h
 * @Description:
 *
 * Copyright (c) 2023 by YangQ, All Rights Reserved.
 */

#ifndef __SERVO_DRIVE__
#define __SERVO_DRIVE__

#include "ADS.h"
#include "Data_Define.h"
#include "Data_Process.h"
#include "myThreadfuc.h"
#include <chrono>
#include <iostream>
#include <string>
#include <synchapi.h>
#include <thread>
#include <vector>
#include "TimerCounter.h"
#include "ReadTXT.hpp"
#define CION "change_immediately On"
#define CIOFF "change_immediately Off"

extern std::mutex th_mutex;

using sd = class Servo_Drive {
public:
    Servo_Drive(ads &myads);

    auto Servo_On(std::vector<DTS> &sdata, std::vector<DFS> &gdata) -> int;

    auto Servo_Off(std::vector<DTS> &sdata, std::vector<DFS> &gdata) -> int;

    /**
     * @description: PP运动驱动程序
     * @param {string} flag:CIOn,CIOFF
     * @return {*}
     */
    auto Servo_PTP_Basic(std::vector<DTS> &sdata, std::vector<DFS> &gdata, std::string &&ciflag) -> int;

    auto Servo_PTP_Basic_isSync(std::vector<DTS> &sdata, std::vector<DFS> &gdata, std::string &&ciflag, int rpm) -> int;

    /**
     * @description: 关节空间角PTP
     * @param {vector<float>} Joint_theta
     * @return {*}
     */
    auto
    Servo_PTP_Joint_noSync(std::vector<float> Joint_theta, std::vector<DTS> &sdata, std::vector<DFS> &gdata) -> int;

    auto Servo_PTP_Joint_isSync(std::vector<float> Joint_theta, std::vector<DTS> &sdata, std::vector<DFS> &gdata,
                                int maxrpm) -> int;

    auto Servo_CSP(std::vector<DTS> &sdata,std::vector<DFS>&gdata,const string&filename)->int;

private:
    int pp_ready_flag=0; //=1表示pp就位，=0表示未就位
    ads *pmyads = nullptr;
    int *const servo_time_lag_flag = new int(1);
    int csp_cycle_flag=1;
    int error_code = 0;
};

#endif