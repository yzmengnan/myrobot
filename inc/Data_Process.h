/*
 * @Author: YangQ
 * @Date: 2023-02-28 13:02:05
 * @LastEditors: YangQ
 * @LastEditTime: 2023-03-01 23:18:54
 * @FilePath: \vsDemo\INC\Data_Process.h
 * @Description:
 *
 * Copyright (c) 2023 by YangQ, All Rights Reserved.
 */
#pragma once

#include "Data_Define.h"
#include <iostream>
#include <vector>
#include <windows.h>


#define R_pulse_of_encoder 0x7fffff
extern int R_reductor[];
using dp = class Data_Process {
public:
    /**
     * @description: pulse of encoder to theta, no data process
     * @param {INT32} pulse
     * @return {*}
     */
    static auto p2t(INT32 pulse,int& i) -> float;

    /**
     * @description:  theta to pulse of encoder, no data process
     * @param {double} revolution
     * @return {*}
     */
    static auto t2p(double theta,int &i) -> INT32;

    /**
     * @description:  Joint_theta up to servo
     * @param {vector<float>} Joint_theta
     * @return {*}
     */
    static auto j2s(std::vector<float> Joint_theta, std::vector<DTS> &sdata) -> int;

    /**
     * @description: 从当前数据获取关节角,获取关节角操作不对数据做处理
     * @return {*}
     */
    static auto sreal_2j(std::vector<DFS> gdata) -> std::vector<float>;

    /**
     * @description: 从目标数据获取关节角，获取关节角操作不对数据做处理
     * @return {*}
     */
    static auto starget_2j(std::vector<DTS> sdata) -> std::vector<float>;
};
