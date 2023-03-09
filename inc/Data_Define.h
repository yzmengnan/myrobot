/*
 * @Author: YangQ
 * @Date: 2023-02-27 11:02:58
 * @LastEditors: YangQ
 * @LastEditTime: 2023-03-08 21:31:50
 * @FilePath: \Demo0\INC\Data_Define.h
 * @Description:
 *
 * Copyright (c) 2023 by YangQ, All Rights Reserved.
 */
#pragma once
#include <Windows.h>

using DTS = struct Data_To_Servo {
    UINT16 Control_Word = 0;
    INT32 Target_Pos = 0;
    UINT32 Profile_Velocity = 0xffffffff;
    UINT32 Max_Velocity = 3000; // rpm
    INT8 Mode_of_Operation = 1;
};
using pDTS = DTS*;

using DFS = struct Data_From_Servo {
    UINT16 Status_Word = 0;
    INT8 Mode_of_Operation_disp = 0;
    INT32 Actual_Pos = 0;
    INT32 null = 0;
};
using pDFS = DFS*;