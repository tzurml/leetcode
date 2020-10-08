//
// Created by tzur on 10/5/2020.
//

//Given n pairs of parentheses, write a function to generate all combinations of well-formed parentheses.
//
//
//
//Example 1:
//
//Input: n = 3
//Output: ["((()))","(()())","(())()","()(())","()()()"]
//Example 2:
//
//Input: n = 1
//Output: ["()"]
//
//
//Constraints:
//
//1 <= n <= 8


#include "string"
#include "vector"

using namespace std;

class Solution {
public:
    vector<string> generateParenthesis(int n) {
        int op = n - 1, cl = n;
        vector<string> tmp, ret;
        string txt_start = "(" ;
        helper(ret,cl,op,txt_start);
        return ret;

    }


    void helper(vector<string>& ret, int close, int open,string& txt)
    {
        if(close == 1 && open == 0)
        {
            string txt_final = txt + ")";
            ret.push_back(txt_final);
        }

        if (open){
            string txt_open = txt + "(";
            helper(ret,close,open - 1,txt_open);
        }
        if (close > 1 && open < close)
        {
            string txt_close = txt + ")";
            helper(ret,close - 1,open,txt_close);
        }
    }

};


