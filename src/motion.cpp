//
// Created by 91418 on 2023/4/26.
//
#include <valarray>
#include "MOTION.h"

MOTION::MOTION() {
    cout << "MOTION TARGET CREATED!" << endl;
}

vector<float> MOTION::joint2position(vector<float> &joint_data) {
    return vector<float>();
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

    return joint_data;
}

vector<vector<float>> MOTION::matrix_multiple(vector<vector<float>> &a, vector<vector<float>> &b) {
//check
    if (a[0].size() != b.size())
        return vector<vector<float>> (0);
   int row = a.size(),col = b[0].size();
   vector<float> zer(col,0);
   vector<vector<float>> res(row,zer);
   for(int i =0;i<row;++i){
       for(int  j=0;j<col;++j){
           float temp=0;
           for(int k=0;k<col;++k){
               temp+=a[i][k]*b[k][j];
           }
           res[i][j]=temp;
       }
   }
    return res;
}
