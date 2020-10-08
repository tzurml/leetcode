//
// Created by tzur on 8/10/2020.
//

//Given a string s, find the longest palindromic substring in s. You may assume that the maximum length of s is 1000.
//
//Example 1:
//
//Input: "babad"
//Output: "bab"
//Note: "aba" is also a valid answer.
//Example 2:
//
//Input: "cbbd"
//Output: "bb"


class Solution {
public:
    string longestPalindrome(string s) {
        if(s.size() <= 1){return s;}
        int len = s.size();
        int maxstr = 0;
        int max = 1;

        for(int i = 0 ; i < len ; i++)
        {

            int j = i;
            int k = i;

            while(j+1 < len && s[j] == s[j+1])
            {
                j++;
            }

            while(k - 1 >= 0 && j+1 < len && s[k-1] == s[j+1])
            {
                k--;
                j++;
            }
            if( j - k + 1 > max)
            {
                max = j - k + 1;
                maxstr = k;
            }
        }
        return s.substr(maxstr,max);
    }
};
