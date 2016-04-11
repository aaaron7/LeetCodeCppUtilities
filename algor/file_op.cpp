//
//  file_op.cpp
//  algor
//
//  Created by aaaron7 on 16/4/9.
//  Copyright © 2016年 aaaron7. All rights reserved.
//

#include "file_op.hpp"

#include <unordered_set>
#include <unordered_map>
#include <fstream>
#include <sstream>

using namespace std;
std::vector<std::string> &split(const std::string &s, char delim, std::vector<std::string> &elems) {
    std::stringstream ss(s);
    std::string item;
    while (std::getline(ss, item, delim)) {
        elems.push_back(item);
    }
    return elems;
}

std::vector<std::string> split(const std::string &s, char delim) {
    std::vector<std::string> elems;
    split(s, delim, elems);
    return elems;
}

vector<vector<char>> loadData2D(string filename){
    ifstream exp(filename);

    char buffer[1000000];
    while(!exp.eof() && exp.is_open()){
        exp.getline(buffer, 1000000);
    }
    string result = buffer;
    result.erase(result.begin());
    result.erase(result.end() - 1);


    vector<vector<char>> re;

    vector<string> temp = split(result, ',');
    for (int i = 0; i< temp.size(); i++) {
        cout<<temp[i]<<endl;
        temp[i].erase(temp[i].begin());
        temp[i].erase(temp[i].end() - 1);
        vector<char> sub;
        for (int j = 0; j < temp[i].length(); j++) {
            sub.push_back(temp[i][j]);
        }
        re.push_back(sub);
    }
    return re;
}

void test(){
    ifstream exp("testdata");

    char buffer[1000000];
    while(!exp.eof() && exp.is_open()){
        exp.getline(buffer, 1000000);
    }
    string result = buffer;
    result.erase(result.begin());
    result.erase(result.end() - 1);

    vector<string> temp = split(result, ',');
    for (int i = 0; i< temp.size(); i++) {
        cout<<temp[i]<<endl;
        temp[i].erase(temp[i].begin());
        temp[i].erase(temp[i].end() - 1);
        vector<char> sub;
        for (int j = 0; j < temp[i].length(); j++) {
            sub.push_back(temp[i][j]);
        }
        //        re.push_back(sub);
    }
}