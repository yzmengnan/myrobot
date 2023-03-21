//
// Created by LR on 2023/3/15.
//

#include "Data_Record.h"
void data_record(vector<vector<DFS>> &data) {
    ofstream outfile;
    outfile.open("./Data/data_record.txt", ios::out | ios::trunc);
    for (int i = 0; i < data.size(); i++) {
        string temp;
        for(auto child:data[i]){
            temp+=std::to_string(child.Actual_Vec/8388608.0*60);
            temp+=",";
        }
        outfile<<temp<<std::endl;
//        outfile << "NO." << i << " " << double(data[i][0].Actual_Vec / 8388608.0 * 60) << ',' << double(data[i][1].Actual_Vec / 8388608.0 * 60)<< ','
//                << double(data[i][2].Actual_Vec / 8388608.0 * 60) << ','<< double(data[i][3].Actual_Vec / 8388608.0 * 60)<< ','
//                << double(data[i][4].Actual_Vec / 8388608.0 * 60)<< ',' << double(data[i][5].Actual_Vec / 8388608.0 * 60)<< ','
//                <<double(data[i][6].Actual_Vec / 8388608.0 * 60)<< ','<<double(data[i][7].Actual_Vec / 8388608.0 * 60)<< ','
//                <<double(data[i][8].Actual_Vec / 8388608.0 * 60)
//                << endl;
    }
    outfile.close();
}