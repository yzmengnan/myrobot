/*
 * @Author: YangQ
 * @Date: 2023-03-07 16:27:40
 * @LastEditors: YangQ
 * @LastEditTime: 2023-03-07 16:48:48
 * @FilePath: \Demo0\INC\ReadTxt.hpp
 * @Description:
 *
 * Copyright (c) 2023 by YangQ, All Rights Reserved.
 */
#pragma once

#include <fstream>
#include <iostream>
#include <sstream>
#include <vector>

using namespace std;

class ReadTxT {
public:
    auto read_from_file(vector<vector<string>> &ans, string &filename) -> vector<vector<string>> & {
        ifstream infile(filename);
        if (!infile) {
            cout << "Wrong with opening file!" << endl;
            return ans;
        }
        string thelines;
        vector<string> lines;
        while (getline(infile, thelines)) {
            lines.push_back(thelines);
        }
        infile.close();
        for (auto &line: lines) {
            for (char &chardata: line) {
                if (chardata == ',') {
                    chardata = ' ';
                }
            }
        }
        for (auto &theline: lines) {
            vector<string> res;
            istringstream line(theline);
            string word;
            while (line >> word) {
                res.push_back(word);
            }
            ans.push_back(res);
        }
        return ans;
    }
};
