/*
 * @Author: YangQ
 * @Date: 2023-03-01 19:48:27
 * @LastEditors: YangQ
 * @LastEditTime: 2023-03-08 21:35:45
 * @FilePath: \Demo0\INC\variable.h
 * @Description:
 *
 * Copyright (c) 2023 by YangQ, All Rights Reserved.
 */
#pragma once
#include <atomic>
#include <mutex>
extern std::mutex threadmutex;
extern std::atomic_int s_err;
