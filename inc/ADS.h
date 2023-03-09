/*
 * @Author: YangQ
 * @Date: 2023-02-27 10:57:27
 * @LastEditors: YangQ
 * @LastEditTime: 2023-03-08 21:31:15
 * @FilePath: \Demo0\INC\ADS.h
 * @Description:
 *
 * Copyright (c) 2023 by YangQ, All Rights Reserved.
 */

// #pragma once
#ifndef ADS_
#define ADS_


#include "ADDRESS_DEFINE.h"
#include "Data_Define.h"
#include "TcAdsDef.h"
#include "TcAdsAPI.h"
//

#include "variable.h"
#include <atomic>
#include <iostream>
#include <vector>

/**
 * @description: 定义关于ADS通讯的类
 * @return {*}
 */
class ADS_COMMUNICATION {
public:
    ADS_COMMUNICATION();

    auto set(std::vector<DTS>& sdata) -> int;
    auto get(std::vector<DFS>& gdata) -> int;
    static auto check_version() -> int;

private:
    long nPort, nErr;
    AmsAddr Addr;
    PAmsAddr pAddr = &Addr;
};
using ads = ADS_COMMUNICATION;

#endif