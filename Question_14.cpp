//
// Created by tzur on 9/22/2020.
//
//Write a function to find the longest common prefix string amongst an array of strings.
//
//If there is no common prefix, return an empty string "".
//
//Example 1:
//
//Input: ["flower","flow","flight"]
//Output: "fl"
//Example 2:
//
//Input: ["dog","racecar","car"]
//Output: ""
//Explanation: There is no common prefix among the input strings.
//Note:
//
//All given inputs are in lowercase letters a-z.


#include "string"
#include "vector"

using namespace std;

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        if (!strs.size()){return "";}

        int max_len = strs[0].size();

        for(int i = 0; i < strs.size() ; i++)
        {
            int j = 0;
            string word = strs[i];
            while(j < word.size() && word[j] == strs[0][j] && j < strs[0].size())
            {
                j++;
            }
            max_len = min(j,max_len);
        }

        string ret = "";
        for(int m = 0; m < max_len ; m++)
        {
            ret = ret + strs[0][m];
        }
        return ret;



    }
};

