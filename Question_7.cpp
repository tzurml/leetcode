//
// Created by tzur on 8/14/2020.
//


//Given a 32-bit signed integer, reverse digits of an integer.
//
//Example 1:
//
//Input: 123
//Output: 321
//Example 2:
//
//Input: -123
//Output: -321
//Example 3:
//
//Input: 120
//Output: 21
//Note:
//Assume we are dealing with an environment which could only store integers within
//the 32-bit signed integer range: [−231,  231 − 1]. For the purpose of this problem,
//assume that your function returns 0 when the reversed integer overflows.


#include <iostream>
#include "string"
#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    int reverse(int x) {

        long tmp = 0;
        long val = abs(x);
        while(val)
        {
            tmp *= 10;
            tmp += val%10; // last digit
            val = val/10;   //reduce
        }
        long ret = (x > 0) ? tmp : -tmp; // negative/positive
        if( ret > INT_MAX ||   ret < INT_MIN)
        {
            return 0;
        }
        return ret;
    }
};

