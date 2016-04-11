//
//  big_number_op.cpp
//  algor
//
//  Created by aaaron7 on 16/4/10.
//  Copyright © 2016年 aaaron7. All rights reserved.
//

#include "big_number_op.hpp"
using namespace std;

class BigNumberSolution {
public:
    string multiply(string num1, string num2) {
        string finalResult;

        if (num1 == "" || num2 == ""){
            return "";
        }

        for (long i = num2.length() - 1; i>=0; i--) {
            int curDigit = num2[i] - '0';
            int carry = 0;
            string curResult;
            for (long j = num1.length() - 1; j >= 0; j--) {
                int upperDigit = num1[j] - '0';
                int result = curDigit * upperDigit + carry;
                carry = result / 10;
                int digitResult = result% 10;
                curResult.insert(curResult.begin(), digitResult + '0');
            }
            if (carry != 0){
                curResult.insert(curResult.begin(), carry + '0');
            }

            for (int k = 0; k < (num2.length() - 1) - i; k ++) {
                curResult.push_back('0');
            }
            finalResult = add(finalResult, curResult);
        }

        while (*finalResult.begin() == '0' && finalResult.length() > 1) {
            finalResult.erase(finalResult.begin());

        }
        return finalResult;
    }

    string add(string num1,string num2){
        int carry = 0;
        string result;
        for (long i = 0;i < num1.length(); i++) {
            int a = num1[num1.length() - 1 - i] - '0';

            if ((int)num2.length() - 1 - i < 0 ){
                break;
            }
            int b = num2[num2.length() - 1 - i] - '0';
            int n = a + b + carry;
            carry = n / 10;
            int digit = n % 10;
            result.insert(result.begin(), digit + '0');
        }

        for (long  j = (long)num2.length() - (long)num1.length() - 1; j >= 0; j --) {
            int digit = num2[j] - '0';
            int n = digit + carry;
            carry = n / 10;
            digit = n % 10;
            result.insert(result.begin(), digit + '0');
        }

        if (carry != 0){
            result.insert(result.begin(), carry + '0');
        }
        
        return result;
    }

    string addBinary(string a, string b) {
        int carry = 0;
        string result;
        string num1 = a;
        string num2 = b;

        if (num1 == "" || num2 == ""){
            return "";
        }

        for (long i = 0;i < num1.length(); i++) {
            int a = num1[num1.length() - 1 - i] - '0';

            if ((int)num2.length() - 1 - i < 0 ){
                break;
            }
            int b = num2[num2.length() - 1 - i] - '0';
            int n = a + b + carry;
            carry = n >> 1;
            int digit = n % 2;
            result.insert(result.begin(), digit + '0');
        }

        for (long  j = (long)num2.length() - (long)num1.length() - 1; j >= 0; j --) {
            int digit = num2[j] - '0';
            int n = digit + carry;
            carry = n >> 1;
            digit = n % 2;
            result.insert(result.begin(), digit + '0');
        }

        for (long  j = (long)num1.length() - (long)num2.length() - 1; j >= 0; j --) {
            int digit = num1[j] - '0';
            int n = digit + carry;
            carry = n >> 1;
            digit = n % 2;
            result.insert(result.begin(), digit + '0');
        }

        if (carry != 0){
            result.insert(result.begin(), carry + '0');
        }
        
        return result;
    }
};