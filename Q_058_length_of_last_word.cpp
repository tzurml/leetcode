//
// Created by tzurm on 10/15/2020.
//
//Given a string s consists of upper/lower-case alphabets and empty space characters ' ', return the length of last word (last word means the last appearing word if we loop from left to right) in the string.
//
//If the last word does not exist, return 0.
//
//Note: A word is defined as a maximal substring consisting of non-space characters only.
//
//Example:
//
//Input: "Hello World"
//Output: 5


#include "string"

using namespace std;


class Solution {
public:
    int lengthOfLastWord(string s) {
        if (s.empty()) { return 0; }
        int i = s.size() - 1;
        int counter = 0, ind = 1;
        while (i >= 0) {
            if (s[i] == ' ' && ind) i--;
            else if (s[i] == ' ' && !ind) break;
            else {
                ind = 0;
                counter++;
                i--;
            }
        }
        return counter;
    }
};