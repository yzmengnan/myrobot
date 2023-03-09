/*
 * @Author: YangQ
 * @Date: 2023-02-28 13:08:07
 * @LastEditors: YangQ
 * @LastEditTime: 2023-03-07 15:37:32
 * @FilePath: \Demo0\SRC\Data_Process.cpp
 * @Description:
 *
 * Copyright (c) 2023 by YangQ, All Rights Reserved.
 */

#include "Data_Process.h"

auto dp::p2t(INT32 pulse) -> float
{
    return float(double(pulse) / R_pulse_of_encoder / R_reductor * 360);
}
auto dp::t2p(double revolution) -> INT32
{
    return (INT32)(revolution / 360 * R_reductor * R_pulse_of_encoder);
}
auto dp::j2s(std::vector<float> Joint_theta, std::vector<DTS>& sdata) -> int
{
    if (sdata.size() != Joint_theta.size())
        return -2001;
    else {
        for (int i = 0; i < Joint_theta.size(); i++) {
            sdata[i].Target_Pos = t2p(Joint_theta[i]);
        }
        return 0;
    }
}
auto dp::sreal_2j(std::vector<DFS> gdata) -> std::vector<float>
{
    std::vector<DFS> temp = std::move(gdata);
    std::vector<float> Joint_theta;
    Joint_theta.reserve(temp.size());
    for (DFS child_servo : temp) {
        Joint_theta.push_back(p2t(child_servo.Actual_Pos));
    }
    return Joint_theta;
}

auto dp::starget_2j(std::vector<DTS> sdata) -> std::vector<float>
{
    std::vector<DTS> temp = std::move(sdata);
    std::vector<float> Joint_theta;
    Joint_theta.reserve(temp.size());
    for (DTS child_servo : temp) {
        Joint_theta.push_back(p2t(child_servo.Target_Pos));
    }
    return Joint_theta;
}