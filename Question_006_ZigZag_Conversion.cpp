//
// Created by tzur on 8/14/2020.
//
//The string "PAYPALISHIRING" is written in a zigzag pattern on a given number of rows like this: (you may want to display this pattern in a fixed font for better legibility)
//
//P   A   H   N
//A P L S I I G
//Y   I   R
//And then read line by line: "PAHNAPLSIIGYIR"
//
//Write the code that will take a string and make this conversion given a number of rows:
//
//string convert(string s, int numRows);
//Example 1:
//
//Input: s = "PAYPALISHIRING", numRows = 3
//Output: "PAHNAPLSIIGYIR"
//Example 2:
//
//Input: s = "PAYPALISHIRING", numRows = 4
//Output: "PINALSIGYAHRPI"
//Explanation:
//
//P     I    N
//A   L S  I G
//Y A   H R
//P     I




#include <iostream>
#include "string"

using namespace std;

class Solution {
public:
    string convert(string s, int numRows) {
        if(!s.size() || numRows == 1){return s;}
        string myVec[numRows];
        int x = 1;
        int dir = 1;
        for(int i = 0; i < s.size() ; i ++)
        {
            myVec[x-1] = myVec[x-1] + s[i];
            if( x == 1 && myVec[0].size() != 1 || x == numRows) // changing direction
            {
                dir = (dir + 1)%2;
            }
            x = (dir) ? x + 1 : x - 1 ;
        }
        string ret = "";
        for(int j = 0; j < numRows ; j++)
        {
            ret += myVec[j];
        }
        return ret;
    }
};
