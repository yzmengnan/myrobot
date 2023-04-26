//
// Created by 91418 on 2023/4/26.
//

#ifndef DEMO1_MOTION_H
#define DEMO1_MOTION_H

#include "vector"
#include <iostream>

using namespace std;

class MOTION {
public:
    MOTION();

    ~MOTION() = default;

    static vector<float> joint2position(vector<float> &joint_data);

    static vector<float> position2joint(vector<float> &position_data);

    static vector<vector<float>> matrix_multiple(vector<vector<float>> &a, vector<vector<float>> &b);
    static void matrix_transform(vector<vector<float>>& a);
};


#endif //DEMO1_MOTION_H
