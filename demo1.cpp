
#include "Mysocket.h"
#include <iostream>
#include <mutex>
#include <thread>
#include <vector>

// MYdemo headers
#include "ADS.h"
#include "Servo_DRIVE.h"
#include "TimerCounter.h"
#include "MOTION.h"

// Gloabl varible
std::atomic_int s_err(1);
std::atomic_int run_flag(0);//0：无使能，1：使能，2：PP连续运动，3：CSP运动
std::mutex th_mutex;

void test();

ads myads;
std::string filename = "./Data/pathdata_0327_origin.txt";

auto main() -> int {
    test();
    sd myservo(myads);
    myThreadfuc mt;
    std::vector<DTS> sdata(Servo_number);
    std::vector<DFS> gdata(Servo_number);
    std::vector<float> Joint(Servo_number);
    Mysocket server;
    server.build_socket();
    // bool *s_t_flag = new bool(true);
    // std::thread s_t(mt::status_print, s_t_flag, 10);
    // s_t.detach();

    //下位机接收线程，获取上位机指令
    std::thread socket_get(&Mysocket::mysocket_recv2, &server, std::ref(sdata));
    socket_get.detach();

    //下位机发送线程，发送下位机状态等数据
    std::thread socket_send(&Mysocket::mysocket_send, &server, std::ref(myads));
    socket_send.detach();

    //下位机驱动线程，根据指令执行
    std::thread drive(&myThreadfuc::DRIVE, &mt, std::ref(run_flag), std::ref(sdata), std::ref(gdata),
                      std::ref(myservo));
    drive.detach();

    //主线程堵塞，遇错退出
    while (TRUE) {
        if (s_err <= 0) {
            std::cout << "System Error:" << s_err << std::endl;
            run_flag = 0;
            break;
        }
    }
    myservo.Servo_Off(sdata);
    return 0;
}

void test() {
    std::vector<std::vector<float>> a ={{2,1,0},{1,1,1},{3,0,5}};
    std::vector<std::vector<float>> b ={{2,1,0},{1,1,1},{0,0,0}};
    std::vector<float> position = {1.497, 0.08026, 0, 0, 0, 0};
    std::vector<float>res = MOTION::position2joint(position);
    std::vector<std::vector<float>> res2 = MOTION::matrix_multiple(a,b);
    MOTION::matrix_transform(a);
    for(auto &child :res)
        std::cout<<child<<",";
    std::cout<<std::endl;
    for(auto &i:a){
        for(auto &j:i)
            std::cout<<j<<",";
        std::cout<<std::endl;
    }
    for(auto &i:res2){
        for(auto &j:i)
            std::cout<<j<<",";
        std::cout<<std::endl;
    }
    std::cout<<std::endl;
}