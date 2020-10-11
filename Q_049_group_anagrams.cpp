//
// Created by tzur on 10/11/2020.
//

//Given an array of strings strs, group the anagrams together.
// You can return the answer in any order.
//
//An Anagram is a word or phrase formed by rearranging the letters of a different word or phrase,
// typically using all the original letters exactly once.
//
//Example 1:
//
//Input: strs = ["eat","tea","tan","ate","nat","bat"]
//Output: [["bat"],["nat","tan"],["ate","eat","tea"]]
//Example 2:
//
//Input: strs = [""]
//Output: [[""]]
//Example 3:
//
//Input: strs = ["a"]
//Output: [["a"]]

#include "vector"
#include "algorithm"
#include "string"
#include "map"

using namespace std;

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> res;
        map<vector<char>,vector<string>> myMap;
        for(auto x : strs)
        {
            vector<char> letters;
            for(auto c : x)
            {
                letters.push_back(c);
            }
            sort(letters.begin(),letters.end());
            myMap[letters].push_back(x);
        }
        for(auto element : myMap)
        {
            res.push_back(element.second);
        }
        return res;

    }
};