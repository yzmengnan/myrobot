/*
 * @Author: YangQ
 * @Date: 2023-03-07 11:15:05
 * @LastEditors: YangQ
 * @LastEditTime: 2023-03-08 21:34:24
 * @FilePath: \Demo0\INC\Mysocket.h
 * @Description:
 *
 * Copyright (c) 2023 by YangQ, All Rights Reserved.
 */

#ifndef __MYSOCKET__
#define __MYSOCKET__
// #pragma ONCE
#undef UNICODE

#define WIN32_LEAN_AND_MEAN

// #include "conio.h"
#include <array>
#include <iostream>
#include <mutex>
#include <vector>
#include <winsock2.h>
#include "windows.h"
#include <ws2tcpip.h>
#include <thread>
//
#include "ADS.h"
#include "Data_Define.h"
#include "Data_Process.h"

#define DEFAULT_BUFLEN 1024
#define DEFAULT_PORT "1115"

extern std::mutex th_mutex;
extern ads myads;
extern std::atomic_int s_err;
extern std::atomic_int run_flag;

class Mysocket {
public:
    Recv recvdata;
    Ssend ssenddata;

    Mysocket() = default;

    int iResult = 1;

    auto build_socket() -> int;

    void mysocket_send(ads myads);

    void mysocket_recv(std::vector<DTS> &sdata);

    void mysocket_recv2(std::vector<DTS> &sdata);

private:
    SOCKET mysocket;
};

#endif