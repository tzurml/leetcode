//
// Created by tzur on 8/17/2020.
//

//Determine whether an integer is a palindrome. An integer is a palindrome
// when it reads the same backward as forward.
//
//Example 1:
//
//Input: 121
//Output: true
//Example 2:
//
//Input: -121
//Output: false
//Explanation: From left to right, it reads -121. From right to left, it becomes 121-. Therefore it is not a palindrome.
//Example 3:
//
//Input: 10
//Output: false
//Explanation: Reads 01 from right to left. Therefore it is not a palindrome.


#include <iostream>
#include "string"

class Solution {
public:
    bool isPalindrome(int x) {
        std::string s = std::to_string(x);
        int j = s.size() - 1;
        for (int i = 0 ; i < s.size()/2; i++)
        {
            if(s[i] != s[j])
            {
                return false;
            }
            j--;
        }
        return true;
    }
};