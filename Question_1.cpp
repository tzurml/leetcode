//
// Created by tzur on 8/6/2020.
//

#include "Question_1.h"
#include <vector>

using namespace std;

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