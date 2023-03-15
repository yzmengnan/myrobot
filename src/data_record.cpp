//
// Created by LR on 2023/3/15.
//

#include "data_record.h"
void data_record(vector<vector<DFS>>& data){
    ofstream outfile;
    outfile.open("./Data/data_record.txt", ios::out | ios::trunc);
    for (int i = 0; i < data.size(); i++) {
        outfile << "NO." << i << " " << double(data[i][0].Actual_Vec /8388608.0*60)<< ',' << double(data[i][1].Actual_Vec /8388608.0*60)<< endl;
    }
    outfile.close();
}