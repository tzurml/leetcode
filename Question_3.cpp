//
// Created by tzur on 8/9/2020.
//

//Given a string, find the length of the longest substring without repeating characters.
//
//Example 1:
//
//Input: "abcabcbb"
//Output: 3
//Explanation: The answer is "abc", with the length of 3.
//Example 2:
//
//Input: "bbbbb"
//Output: 1
//Explanation: The answer is "b", with the length of 1.
//Example 3:
//
//Input: "pwwkew"
//Output: 3
//Explanation: The answer is "wke", with the length of 3.
//Note that the answer must be a substring, "pwke" is a subsequence and not a substring.

#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        vector<int> arr(256,-1);
        int n = s.size();
        int j = 0,res = 0;
        for(int i = 0 ;  i < n ; i++)
        {
            j = max(j,arr[s[i]] + 1);
            res = max(res, i-j+1);
            arr[s[i]]=i;
        }
        return res;
    }
};