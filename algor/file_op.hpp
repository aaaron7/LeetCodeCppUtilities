//
//  file_op.hpp
//  algor
//
//  Created by aaaron7 on 16/4/9.
//  Copyright © 2016年 aaaron7. All rights reserved.
//

#ifndef file_op_hpp
#define file_op_hpp
#include <iostream>
#include <string>
#include <stdio.h>
#include <vector>
using namespace std;
std::vector<std::string> split(const std::string &s, char delim);
std::vector<std::string> &split(const std::string &s, char delim, std::vector<std::string> &elems);
vector<vector<char>> loadData2D(string filename);
#endif /* file_op_hpp */
