//
// Created by tzur on 9/22/2020.
//


//Given a string containing digits from 2-9 inclusive, return all possible letter combinations that the number could represent.
//
//A mapping of digit to letters (just like on the telephone buttons) is given below. Note that 1 does not map to any letters.
//
//Example:
//
//Input: "23"
//Output: ["ad", "ae", "af", "bd", "be", "bf", "cd", "ce", "cf"].
//Note:
//
//Although the above answer is in lexicographical order, your answer could be in any order you want.
//

#include "string"
#include "vector"
#include "map"

using namespace std;

class Solution {
public:
    void helper(map<string,string> myMap,string input,int i, vector<string>& res)
    {
        if(i >= input.size())
        {
            return;
        }
        if(!i)
        {
            string x1;
            x1.push_back(input[0]);
            for(auto a : myMap[x1])
            {
                string x2;
                x2.push_back(a);
                res.push_back(x2);
            }
            helper(myMap,input,1,res);
            return;
        }
        vector<string> tmp;
        for(int j = 0 ; j < res.size();j++)
        {
            string x3;
            x3.push_back(input[i]);
            for(auto c : myMap[x3])
            {
                tmp.push_back(res[j] + c);
            }
        }
        res = tmp;
        helper(myMap,input,i+1,res);
        return;
    }



    vector<string> letterCombinations(string digits) {
        map<string,string> myMap = { {"2" , "abc"} ,{"3" , "def"} ,{"4" , "ghi"} ,
                                     {"5","jkl"} ,{"6" , "mno"} ,{"7" , "pqrs"} ,
                                     {"8" , "tuv"} ,{"9","wxyz"}};
        vector<string> res;
        helper(myMap,digits,0,res);
        return res;

    }
};

