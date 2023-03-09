/*
 * @Author: YangQ
 * @Date: 2023-03-08 09:46:45
 * @LastEditors: YangQ
 * @LastEditTime: 2023-03-08 21:37:55
 * @FilePath: \Demo0\INC\TimerCounter.h
 * @Description:
 *
 * Copyright (c) 2023 by YangQ, All Rights Reserved.
 */
#ifndef __TC__
#define __TC__
//#pragma once
#include <iostream>
#include <windows.h>

class TimerCounter {
public:
    TimerCounter(); // 构造函数
    ~TimerCounter() = default; // 析构函数
private:
    LARGE_INTEGER startCount; // 记录开始时间

    LARGE_INTEGER endCount; // 记录结束时间

    LARGE_INTEGER freq; // 本机CPU时钟频率
public:
    double dbTime; // 程序运行的时间保存在这里

public:
    void Start(); // 被测程序开始点处开始计时
    void Stop(); // 被测程序结束点处结束计时
};


#endif