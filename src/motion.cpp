//
// Created by 91418 on 2023/4/26.
//
#include <valarray>
#include "MOTION.h"

MOTION::MOTION() {
    cout << "MOTION TARGET CREATED!" << endl;
}

vector<float> MOTION::joint2position(vector<float> &joint_data) {
    vector<vector<float>> T01 = {{cos(joint_data[0]), -sin(joint_data[0]), 0, 0},
                                 {sin(joint_data[0]), cos(joint_data[0]),  0, 0},
                                 {0,                  0,                   1, 0},
                                 {0,                  0,                   0, 1}};

    vector<vector<float>> T12 = {{cos(joint_data[1]), -sin(joint_data[1]), 0,  0},
                                 {0,                  0,                   -1, -1.002},
                                 {sin(joint_data[1]), cos(joint_data[1]),  0,  0},
                                 {0,                  0,                   0,  1}};
    vector<vector<float>> T23 = {{cos(joint_data[2]),  -sin(joint_data[2]), 0, 0},
                                 {0,                   0,                   1, 0},
                                 {-sin(joint_data[2]), -cos(joint_data[2]), 0, 0},
                                 {0,                   0,                   0, 1}};
    vector<vector<float>> T34 = {{cos(joint_data[3]), -sin(joint_data[3]), 0,  0},
                                 {0,                  0,                   -1, -1.1155},
                                 {sin(joint_data[3]), cos(joint_data[3]),  0,  0},
                                 {0,                  0,                   0,  1}};
    vector<vector<float>> T45 = {{cos(joint_data[4]), -sin(joint_data[4]), 0,  0},
                                 {0,                  0,                   -1, 0},
                                 {sin(joint_data[4]), cos(joint_data[4]),  0,  0},
                                 {0,                  0,                   0,  1}};
    vector<vector<float>> T56 = {{cos(joint_data[5]),  -sin(joint_data[5]), 0, 0},
                                 {0,                   0,                   1, 0},
                                 {-sin(joint_data[3]), -cos(joint_data[3]), 0, 0},
                                 {0,                   0,                   0, 1}};
    vector<vector<float>>res = matrix_multiple(T01,T12);
    res = matrix_multiple(res,T23);
    res = matrix_multiple(res,T34);
    res = matrix_multiple(res,T45);
    res = matrix_multiple(res,T56);
    vector<float>position(6,0);
    position[0] = res[0][3];
    position[1] = res[1][3];
    position[2] = res[2][3];
    return position;
}

vector<float> MOTION::position2joint(vector<float> &position_data) {
    vector<float> joint_data(6, 0);
    const float d4 = 1.1155, d2 = 1.002;
    const auto r = (pow(position_data[0], 2) + pow(position_data[1], 2) + pow(position_data[2], 2));
    joint_data[2] = (float) acos((r - d4 * d4 - d2 * d2) / 2.235462);
    joint_data[1] = (float) asin(position_data[2] / d4 / sin(joint_data[2]));
    const auto gama = (float) atan2(position_data[1], position_data[0]);
    const auto gama2 = (float) atan2(-d4 * cos(joint_data[2]) - d2, cos(joint_data[1]) * d4 * sin(joint_data[2]));
    joint_data[0] = gama - gama2;
    float c1 = cos(joint_data[0]), c2 = cos(joint_data[1]), c3 = cos(joint_data[2]), s1 = sin(joint_data[0]), s2 = sin(
            joint_data[1]), s3 = sin(joint_data[2]);
    vector<vector<float>> R03 = {{c1 * c2 * c3 - s1 * s3, -c3 * s1 - c1 * c2 * s3, -c1 * s2},
                                 {c2 * s3 + c2 * c3 * s1, c1 * c3 - c2 * s1 * s3,  -s1 * s2},
                                 {c3 * s2,                -s2 * s3,                c2}};
    vector<vector<float>> Rz_alpha = {{cos(position_data[3]), -sin(position_data[3]), 0},
                                      {sin(position_data[3]), cos(position_data[3]),  0},
                                      {0,                     0,                      1}};
    vector<vector<float>> Ry_beta = {{cos(position_data[4]),  0, sin(position_data[4])},
                                     {0,                      1, 0},
                                     {-sin(position_data[4]), 0, cos(position_data[4])}};
    vector<vector<float>> Rx_gama = {{1, 0,                     0},
                                     {0, cos(position_data[5]), -sin(position_data[5])},
                                     {0, sin(position_data[5]), cos(position_data[5])}};
    vector<vector<float>> res = MOTION::matrix_multiple(Rz_alpha, Ry_beta);
    res = MOTION::matrix_multiple(res, Rx_gama);
    MOTION::matrix_transform(R03);
    vector<vector<float>> R36 = MOTION::matrix_multiple(R03, res);
    joint_data[4] = acos(fminf(fmaxf(-R36[1][2],-0.995),0.995));
    joint_data[5] = asin(fminf(fmaxf(R36[1][1],-0.995),0.995) / sin(joint_data[4]));
    joint_data[3] = asin(fminf(fmaxf(-R36[2][2],-0.995),0.995) / sin(joint_data[4]));
    return joint_data;
}

vector<vector<float>> MOTION::matrix_multiple(vector<vector<float>> &a, vector<vector<float>> &b) {
//check
    if (a[0].size() != b.size())
        return vector<vector<float>>(0);
    int row = a.size(), col = b[0].size();
    vector<float> zer(col, 0);
    vector<vector<float>> res(row, zer);
    for (int i = 0; i < row; ++i) {
        for (int j = 0; j < col; ++j) {
            float temp = 0;
            for (int k = 0; k < col; ++k) {
                temp += a[i][k] * b[k][j];
            }
            res[i][j] = temp;
        }
    }
    return res;
}

void MOTION::matrix_transform(vector<vector<float>> &a) {

    vector<float> row_zeros(a[0].size(), 0);
    vector<float> col_zeros(a.size(), 0);
    vector<vector<float>> res(row_zeros.size(), col_zeros);
    for (int i = 0; i < row_zeros.size(); ++i) {
        for (int j = 0; j < col_zeros.size(); ++j) {
            res[i][j] = a[j][i];
        }
    }
    a = res;
}
