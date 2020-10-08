//
// Created by tzur on 9/25/2020.
//
//Given a string s containing just the characters '(', ')', '{', '}', '[' and ']', determine if the input string is valid.
//
//An input string is valid if:
//
//Open brackets must be closed by the same type of brackets.
//Open brackets must be closed in the correct order.
//
//
//Example 1:
//
//Input: s = "()"
//Output: true
//Example 2:
//
//Input: s = "()[]{}"
//Output: true
//Example 3:
//
//Input: s = "(]"
//Output: false
//Example 4:
//
//Input: s = "([)]"
//Output: false
//Example 5:
//
//Input: s = "{[]}"
//Output: true

#include "string"
#include "vector"
#include "stack"
#include "map"
using namespace std;


class Solution {
public:
    map<char,char> m = {{'}','{'},{')','('},{']','['}};
    bool isValid(string s) {
        stack<char> stk;
        for(auto c : s)
        {
            if( c == '(' || c == '{' || c == '[' )
            {
                stk.push(c);
            }
            else
            {
                if(stk.empty()){return false;}
                char tmp = stk.top();
                stk.pop();
                if(m[c] != tmp){return false;}
            }
        }
        return stk.empty();
    }
};
