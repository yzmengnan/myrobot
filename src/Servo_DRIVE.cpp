/*
 * @Author: YangQ
 * @Date: 2023-02-27 15:57:49
 * @LastEditors: YangQ
 * @LastEditTime: 2023-03-08 11:10:28
 * @FilePath: \Demo0\SRC\Servo_Driver.cpp
 * @Description:
 *
 * Copyright (c) 2023 by YangQ, All Rights Reserved.
 */
#include "Servo_DRIVE.h"

Servo_Drive::Servo_Drive(ads &myads) {
    pmyads = &myads;
}

auto Servo_Drive::Servo_On(std::vector<DTS> &sdata, std::vector<DFS> &gdata) -> int {
    bool state = true;
    for (int trial_time = 0; trial_time < 3; trial_time++) {
        error_code = pmyads->get(gdata);
        if (error_code < 0)
            return error_code;
        for (DFS child_servo: gdata) {
            state = ((child_servo.Status_Word &= 0x40) == 0x40); // 状态字按位与0x40后等于0x40 表示，此时伺服处于初始化完成状态
        }
        if (state) {
            std::cout << "All Servos Ready!" << std::endl;
        }

        for (DTS &child_servo: sdata) {
            child_servo.Control_Word = 0x0006;
        }

        error_code = pmyads->set(sdata);
        if(error_code<0){
            return error_code;
        }
        Sleep(10);
        error_code = pmyads->get(gdata);
        if (error_code)
            return error_code;

        for (DFS child_servo: gdata) {
            state = ((child_servo.Status_Word &= 0x21) == 0x21);
        }
        if (state) {
            std::cout << "All Servos Ready to switch on!" << std::endl;
        }
        for (DTS &child_servo: sdata) {
            child_servo.Control_Word = 0x0007;
        }
        error_code = pmyads->set(sdata);
        if(error_code<0){
            return error_code;
        }
        Sleep(10);
        error_code = pmyads->get(gdata);
        if (error_code)
            return error_code;
        for (DFS child_servo: gdata) {
            state = ((child_servo.Status_Word &= 0x23) == 0x23);
        }
        if (state) {
            std::cout << "All Servos Switched on!" << std::endl;
        }

        for (DTS &child_servo: sdata) {
            child_servo.Control_Word = 0x000F;
        }
        error_code = pmyads->set(sdata);
        Sleep(100);
        if(error_code<0){
            return error_code;
        }
        error_code = pmyads->get(gdata);
        if (error_code)
            return error_code;
        for (DFS child_servo: gdata) {
            state = ((child_servo.Status_Word &= 0x37) == 0x37);
        }
        if (state) {
            std::cout << "All Servos Operation enabled!" << std::endl;
            return 0;
        } else {
            std::cout << "Servo Enable trying, time_counts:" << trial_time + 1 << std::endl;
            std::this_thread::sleep_for(std::chrono::seconds(1));
        }
    }
    std::cout << "Servo Enable Failure......" << std::endl;
    error_code = -1001;
    return error_code;
}

auto Servo_Drive::Servo_Off(std::vector<DTS> &sdata) -> int {
    for (auto &child_servo: sdata) {
        child_servo.Control_Word = 0;
    }
    error_code = pmyads->set(sdata);
    if (error_code < 0) {

        std::cout << "Servo Operation disabled failure !!" << std::endl;
        return error_code;
    }
    std::cout << "All Servos Operation disabled!" << std::endl;
    return 0;
}

auto Servo_Drive::Servo_PTP_Basic(std::vector<DTS> &sdata, std::vector<DFS> &gdata, std::string &&ciflag) -> int {
    bool servo_state = true;
    if (pp_ready_flag == 0) {
        //设置PP工作模式
        for (auto &child_servo: sdata) {
            child_servo.Mode_of_Operation = 1;
            child_servo.Max_Velocity=2500;
        }
        error_code = pmyads->set(sdata);
        if (error_code < 0) {
            return error_code;
        }
        error_code = pmyads->get(gdata);
        if (error_code < 0) {
            return error_code;
        }
        //检查伺服是否为PP工作模式
        for (auto child_servo: gdata) {
            if (child_servo.Mode_of_Operation_disp != 1) {
                servo_state = false;
            }
        }
    }
    if (!servo_state) {
        std::cout << "Servo Operation Mode Change Failure!" << std::endl;
        error_code = -3000;
        return error_code;
    } else
        pp_ready_flag = 1;
    // PTP with CIOFF
    if (ciflag == CIOFF) {
        th_mutex.lock();
        error_code = pmyads->set(sdata); // 更新607Ah（Target Position）的值
        th_mutex.unlock();
        if (error_code < 0) {
            return error_code;
        }
        for (auto &child_servo: sdata)
            child_servo.Control_Word |= 0x10;
        // 检查伺服是否收到目标点，否则，循环发送控制字的bit4为1；
        th_mutex.lock();
        error_code = pmyads->set(sdata);
        th_mutex.unlock();
        // 开启线程th1，设置延迟最大20ms即退出
        if (error_code < 0) {
            return error_code;
        }
        //重置标志位指针
        *servo_time_lag_flag = 1;
        std::thread th1(mt::tc, servo_time_lag_flag, 20);
        th1.detach();
        while (servo_state && *servo_time_lag_flag) {
            int servo_get_number = 0;
            // 获取伺服状态字
            th_mutex.lock();
            error_code = pmyads->get(gdata);
            th_mutex.unlock();
            if (error_code < 0) {
                return error_code;
            }
            for (auto child_servo: gdata) {
                if (child_servo.Status_Word & 0x1000)
                    servo_get_number++;
            }
            if (servo_get_number == Servo_number) {
                servo_state = false;
            } else
                std::this_thread::sleep_for(std::chrono::milliseconds(1));
        }
        // 如果是伺服均收到新的坐标位置，更新控制字，准备下一次位置更新
        if (!servo_state) {
            for (auto &child_servo: sdata) {
                child_servo.Control_Word &= 0xffef;
            }
            th_mutex.lock();
            error_code = pmyads->set(sdata);
            th_mutex.unlock();
            return error_code;
        }
            // 否则，则是*servo_time_lag_flag=0退出 由th1最大延时后，伺服依旧没有响应
        else {
            std::cout << "Servo lag!" << std::endl;
            error_code = -3001;
            return error_code;
        }
    }

        // 轨迹点连续，用于连续点动
    else if (ciflag == CION) {
        std::cout << "ptp_continue" << std::endl;
        return error_code;
    } else {
        error_code = -3002;
        return error_code;
    }
}

auto Servo_Drive::Servo_PTP_Basic_isSync(std::vector<DTS> &sdata, std::vector<DFS> &gdata, std::string &&ciflag,
                                         int rpm) -> int {
    error_code = pmyads->get(gdata);
    if (error_code < 0)
        return error_code;
    std::vector<float> rate;
    rate.reserve(Servo_number);
    for (int i = 0; i < gdata.size(); i++) {
        rate.push_back(dp::p2t(abs(gdata[i].Actual_Pos - sdata[i].Target_Pos), i));
    }
    float max_delta_p = *std::max_element(rate.begin(), rate.end());
    for (auto &child_rate: rate) {
        child_rate = child_rate / max_delta_p;
    }
    //rpm 是关节转速
    for (int i = 0; i < sdata.size(); i++) {
        sdata[i].Profile_Velocity = dp::t2p(rate[i] * rpm / 6.0 * 360, i);
    }
    error_code = pmyads->set(sdata);
    if (error_code < 0)
        return error_code;
    error_code = Servo_PTP_Basic(sdata, gdata, CIOFF);
    return error_code;
}

/**
 * @description: 根据Joint_theta直接运动到Position
 * @return {*}
 */
auto Servo_Drive::Servo_PTP_Joint_noSync(std::vector<float> Joint_theta, std::vector<DTS> &sdata,
                                         std::vector<DFS> &gdata) -> int {
    error_code = dp::j2s(std::move(Joint_theta), sdata);
    if (error_code < 0) {
        return error_code;
    }
    error_code = Servo_PTP_Basic(sdata, gdata, CIOFF);
    return error_code;
}

auto
Servo_Drive::Servo_PTP_Joint_isSync(std::vector<float> Joint_theta, std::vector<DTS> &sdata, std::vector<DFS> &gdata,
                                    int rpm) -> int {
    error_code = dp::j2s(std::move(Joint_theta), sdata);
    if (error_code < 0) {
        return error_code;
    }
    // 获取关节位置
    error_code = pmyads->get(gdata);
    if (error_code < 0)
        return error_code;
    std::vector<float> rate;
    rate.reserve(2);
    // 计算目标与当前相对位置差
    for (int i = 0; i < gdata.size(); i++) {
        rate.push_back(dp::p2t(abs(gdata[i].Actual_Pos - sdata[i].Target_Pos), i));
    }
    // 取出最大的差值
    float max_delta_p = *std::max_element(rate.begin(), rate.end());
    // 以最大的插值为分母，按比例对每个轴的速度均一
    for (auto &child_rate: rate) {
        child_rate = child_rate / max_delta_p;
    }
    for (int i = 0; i < sdata.size(); i++) {
        sdata[i].Profile_Velocity = dp::t2p(rate[i] / 6.0 * rpm, i);
    }
    // 发送关节速度信息
    error_code = pmyads->set(sdata);
    if (error_code < 0)
        return error_code;

    error_code = Servo_PTP_Basic(sdata, gdata, CIOFF);
    return error_code;
}

auto Servo_Drive::Servo_CSP(std::vector<DTS> &sdata, std::vector<DFS> &gdata,const string&filename) -> int {

    vector<vector<DFS>> Data_receive_buffer;
    pp_ready_flag=0;
    TimerCounter tc;
    ReadTxT txt;
    std::vector<std::vector<std::string>> local_data, ans;
    string path = filename;
    local_data = txt.read_from_file(ans, path);
    if (local_data.empty()) {
        std::cout << "Read File Error!" << std::endl;
        return -1;
    }
    int i = 0;
    for (auto &child_servo: sdata) {
        child_servo.Mode_of_Operation = 8;
        child_servo.Target_Pos =(std::int32_t) dp::t2p(stof(local_data[1][i])*180/3.1415926, i);
        child_servo.Max_Velocity = 2500;
        i++;
    }
    error_code = pmyads->set(sdata);
    this_thread::sleep_for(chrono::milliseconds(2000));
    while (true) {
        if (csp_cycle_flag) {
            tc.Start();
            local_data.erase(local_data.begin());//删除第一行
            if (local_data.empty()) {
                std::cout << "CSP MODE WORK DOWN!" << std::endl;
                break;
            } else {
                std::cout << "Target Position has sent!" << "Joint_Position:";
                for (int i = 0; i < Servo_number; i++) {
                    sdata[i].Target_Pos =(std::int32_t) dp::t2p(stof(local_data[0][i])*180/3.1415, i);
                    std::cout << stof(local_data[0][i]) << ",";
                }
                std::cout << std::endl;
                th_mutex.lock();
                error_code = pmyads->get(gdata);
                th_mutex.unlock();
                if(error_code<0){
                    return error_code;
                }
                std::cout << "Max Velocity has verified!" << "Axis_speed with rpm:";
                for (int i = 0; i < Servo_number; i++) {
                    //速度修正
                    //脉冲差除以8388608得到r/10ms *6000 得到rpm 再乘以跟踪误差比1/k（k>1)
                    sdata[i].Max_Velocity = int(
                            double(abs(gdata[i].Actual_Pos - sdata[i].Target_Pos) * 0.00006794929));
//                    std::cout << sdata[i].Max_Velocity << ",";
//                    std::cout << gdata[i].Actual_Vec << ",";
                }
                std::cout << std::endl;
                error_code = pmyads->set(sdata);
                csp_cycle_flag = 0;
                Data_receive_buffer.push_back(gdata);
            }
        }
        tc.Stop();
        if (tc.dbTime * 1000 > 10) {
            csp_cycle_flag = 1;
            std::cout << "Time cycle:" << tc.dbTime * 1000 << std::endl;
        }
    }
    this_thread::sleep_for(std::chrono::milliseconds(1000));
    for(auto&child_servo:sdata){
        child_servo.Mode_of_Operation=1;
    }
    data_record(Data_receive_buffer);
    error_code = pmyads->set(sdata);
    return error_code;
}
