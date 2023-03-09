/*
 * @Author: YangQ
 * @Date: 2023-02-27 11:15:58
 * @LastEditors: YangQ
 * @LastEditTime: 2023-03-08 10:31:15
 * @FilePath: \Demo0\SRC\Ads_Com.cpp`
 * @Description:
 *
 * Copyright (c) 2023 by YangQ, All Rights Reserved.
 */
#include "ADS.h"

/**
 * @description: 构造函数，生成pAddr用于通讯地址确认
 * @return {*}
 */
ADS_COMMUNICATION::ADS_COMMUNICATION()
{
    nPort = AdsPortOpen();
    nErr = AdsGetLocalAddress(pAddr);
    if (nErr) {
        // std::cout << "Error: Ads: Open port:" << nErr << std::endl;
    }
    pAddr->port = 851;
}

/**
 * @description: 发送数据
 * @return {*}
 */
auto ads::set(std::vector<DTS>& sdata) -> int
{

    nErr = AdsSyncWriteReq(pAddr, OUTPUT_BASE, OUTPUT_OFFSET, DTS_SIZE * sdata.size(), sdata.data());
    if (nErr) {
        std::cout << "Error: Ads send data :" << nErr << std::endl;
        return -101;
    }
    return 0;
}

/**
 * @description: 接受数据
 * @return {*}
 */
auto ads::get(std::vector<DFS>& gdata) -> int
{

    nErr = AdsSyncReadReq(pAddr, INPUT_BASE, INPUT_OFFSET, DFS_SIZE * gdata.size(), gdata.data());
    if (nErr) {
        std::cout << "Error: Ads get data :" << nErr << std::endl;
        return -102;
    }
    return 0;
}

/**
 * @description: ads版本确认
 * @return {*}
 */
auto ads::check_version() -> int
{
    long nTemp;
    AdsVersion* pDLLVersion;
    nTemp = AdsGetDllVersion();
    pDLLVersion = (AdsVersion*)&nTemp;
    std::cout << "Version: " << (int)pDLLVersion->version << '\n';
    std::cout << "Revision: " << (int)pDLLVersion->revision << '\n';
    std::cout << "Build: " << pDLLVersion->build << '\n';
    std::cout.flush();
    return 0;
}