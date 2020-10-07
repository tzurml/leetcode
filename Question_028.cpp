//
// Created by tzur on 10/7/2020.
//Implement strStr().
//
//Return the index of the first occurrence of needle in haystack, or -1 if needle is not part of haystack.
//
//Clarification:
//
//What should we return when needle is an empty string? This is a great question to ask during an interview.
//
//For the purpose of this problem, we will return 0 when needle is an empty string. This is consistent to C's strstr() and Java's indexOf().
//
//Example 1:
//
//Input: haystack = "hello", needle = "ll"
//Output: 2
//Example 2:
//
//Input: haystack = "aaaaa", needle = "bba"
//Output: -1
//Example 3:
//
//Input: haystack = "", needle = ""
//Output: 0
//
//Constraints:
//
//0 <= haystack.length, needle.length <= 5 * 104
//haystack and needle consist of only lower-case English characters.



#include "string"
using namespace std;

class Solution {
public:
    int strStr(string haystack, string needle) {
        if(!needle.size()) return 0;

        int ind = -1 ,j = 0;
        for(int i = 0; i < haystack.size() ; i++)
        {
            for(j = i ; j - i < needle.size() ; j++)
            {
                if (j >= haystack.size()) return -1;

                if(haystack[j] != needle[j - i]) break;

                if (j - i == (needle.size() - 1)) return i;
            }
        }
        return -1;
    }
};