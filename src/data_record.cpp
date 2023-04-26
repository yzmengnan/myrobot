//
// Created by LR on 2023/3/15.
//

#include "Data_Record.h"
#include "Data_Process.h"
void data_record(vector<vector<DFS>> &data) {
    ofstream outfile,outfile2,outfile3;
    outfile.open("./Data/data_record_0328_mul_v_2.txt", ios::out | ios::trunc);
    for (int i = 0; i < data.size(); i++) {
        string temp;
        for(auto child:data[i]){
            temp+=std::to_string(child.Actual_Vec/8388608.0*60);
            temp+=",";
        }
        outfile<<" "<<i<<","<<temp<<std::endl;
//        outfile << "NO." << i << " " << double(data[i][0].Actual_Vec / 8388608.0 * 60) << ',' << double(data[i][1].Actual_Vec / 8388608.0 * 60)<< ','
//                << double(data[i][2].Actual_Vec / 8388608.0 * 60) << ','<< double(data[i][3].Actual_Vec / 8388608.0 * 60)<< ','
//                << double(data[i][4].Actual_Vec / 8388608.0 * 60)<< ',' << double(data[i][5].Actual_Vec / 8388608.0 * 60)<< ','
//                <<double(data[i][6].Actual_Vec / 8388608.0 * 60)<< ','<<double(data[i][7].Actual_Vec / 8388608.0 * 60)<< ','
//                <<double(data[i][8].Actual_Vec / 8388608.0 * 60)
//                << endl;
    }
    outfile.close();
    outfile2.open("./Data/data_record_0328_mul_p_2.txt", ios::out | ios::trunc);
    for(int i =0;i<data.size();i++){
        string temp;
        for(int j =0;j<Servo_number;j++){
            temp+=std::to_string(dp::p2t(data[i][j].Actual_Pos,j));
            temp+=",";
        }
        outfile2<<" "<<i<<","<<temp<<std::endl;
    }
    outfile2.close();

    outfile3.open("./Data/data_record_0328_mul_t_2.txt", ios::out | ios::trunc);
    for(int i =0;i<data.size();i++){
        string temp;
        for(int j =0;j<Servo_number;j++){
            temp+=std::to_string(data[i][j].Actual_Torque);
            temp+=",";
        }
        outfile3<<" "<<i<<","<<temp<<std::endl;
    }
    outfile3.close();
}