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

float R_reductor[9]={35.6154*20/5,35.6154*12/5,171*5/3,34.8604*10/5.2381,161*5/3,36.578947*5/3,0.5,20,0.5};
int pulse_offset[9]={-513848,-331982,11630709,-382944720,-506320482,42662099,0,0,0};


auto dp::p2t(INT32 pulse,int& i ) -> float {
    return float(double(pulse+pulse_offset[i]) / R_pulse_of_encoder / R_reductor[i] * 360);
}

auto dp::t2p(double theta,int& i) -> INT32 {
    return (INT32) double((theta / 360 * R_reductor[i] * R_pulse_of_encoder))-pulse_offset[i];
}

auto dp::j2s(std::vector<float> Joint_theta, std::vector<DTS> &sdata) -> int {
    if (sdata.size() != Joint_theta.size())
        return -2001;
    else {
        for (int i = 0; i < Joint_theta.size(); i++) {
            sdata[i].Target_Pos = t2p(Joint_theta[i],i);
        }
        return 0;
    }
}

auto dp::sreal_2j(std::vector<DFS> gdata) -> std::vector<float> {
    std::vector<DFS> temp = std::move(gdata);
    std::vector<float> Joint_theta;
    Joint_theta.reserve(temp.size());
    int i =0;
    for (DFS child_servo: temp) {
        Joint_theta.push_back(p2t(child_servo.Actual_Pos,i));
        i++;
    }
    return Joint_theta;
}

auto dp::starget_2j(std::vector<DTS> sdata) -> std::vector<float> {
    std::vector<DTS> temp = std::move(sdata);
    std::vector<float> Joint_theta;
    Joint_theta.reserve(temp.size());
    int i =0;
    for (DTS child_servo: temp) {
        Joint_theta.push_back(p2t(child_servo.Target_Pos,i));
        i++;
    }
    return Joint_theta;
}