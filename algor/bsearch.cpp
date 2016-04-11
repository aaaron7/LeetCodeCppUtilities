//
//  bsearch.cpp
//  algor
//
//  Created by aaaron7 on 16/4/10.
//  Copyright © 2016年 aaaron7. All rights reserved.
//

#include "bsearch.hpp"
using namespace std;
class BSearchSolution {
public:
    bool searchMatrixSimple(vector<vector<int>>& matrix, int target,int row) {
        int begin = 0;
        int end = 0;
        if (matrix.size() <= 0){
            return false;
        }
        begin = 0;
        end = matrix[row].size() - 1;
        while(begin<end){

            if (matrix[row][begin] == target || matrix[row][end] == target){
                return true;
            }

            int middle = begin + ((end-begin) /2);
            if (middle == begin){
                return false;

            }

            if(matrix[row][middle] > target){
                end = middle;
            }else if(matrix[row][middle] < target){
                begin = middle;
            }else{
                return true;
            }
        }

        return false;
    }

    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        for (int i = 0; i < matrix.size() ; i++) {
            if (matrix[i][0] == target || matrix[i][matrix[i].size() - 1] == target){
                return true;
            }

            if(matrix[i][0] < target && matrix[i][matrix[i].size() - 1] > target ){
                if (searchMatrixSimple(matrix, target, i)){
                    return true;
                }
            }
        }
        
        return false;
    }
};