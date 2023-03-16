/*
 * @Author: YangQ
 * @Date: 2023-02-28 16:41:33
 * @LastEditors: YangQ
 * @LastEditTime: 2023-03-08 21:34:27
 * @FilePath: \Demo0\INC\myThreadfuc.h
 * @Description:
 *
 * Copyright (c) 2023 by YangQ, All Rights Reserved.
 */
#pragma once
//#ifndef __MYTHREAD__
//#define __MYTHREAD__

#include "ADS.h"
#include "Data_Define.h"
#include "Data_Process.h"
#include "Servo_DRIVE.h"
#include <chrono>
#include <cstring>
#include <iostream>
#include <mutex>
#include <thread>
#include <vector>

extern std::mutex th_mutex;
extern std::atomic_int s_err;
extern std::atomic_int run_flag;
extern std::string filename;

class Servo_Drive;

using mt = class myThreadfuc {
public:
    static void tc(int *flag, int breakout_value);

    [[maybe_unused]] static void status_print(const bool *flag, int cycletime, ads myads);

    void DRIVE(std::atomic_int &runflag, std::vector<DTS> &sdata, std::vector<DFS> &gdata, Servo_Drive& mysd);


private:
    int error_code = 0;
};

//#endif