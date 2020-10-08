//
// Created by tzur on 8/6/2020.
//

#include "Question_1.h"
#include <vector>

using namespace std;



//  Given an array of integers, return indices of the two numbers such that they add up to a specific target.
//
//  You may assume that each input would have exactly one solution, and you may not use the same element twice.
//
//  Example:
//
//  Given nums = [2, 7, 11, 15], target = 9,
//
//  Because nums[0] + nums[1] = 2 + 7 = 9,
//  return [0, 1].




class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> ret;
        int s = nums.size();
        int ind = 0;
        while(ind < (s-1))
        {
            for(int j = ind+1 ; j < s ; j++)
            {
                if(nums[j] + nums[ind] == target)
                {
                    ret.push_back(ind);
                    ret.push_back(j);
                    return ret;
                }
            }
            ind++;
        }
        return ret;
    }
};
