//
// Created by tzur on 9/22/2020.
//

//Given an array nums of n integers, are there elements a, b, c in nums such that a + b + c = 0? Find all unique triplets in the array which gives the sum of zero.
//
//Notice that the solution set must not contain duplicate triplets.
//
//
//
//Example 1:
//
//Input: nums = [-1,0,1,2,-1,-4]
//Output: [[-1,-1,2],[-1,0,1]]
//Example 2:
//
//Input: nums = []
//Output: []
//Example 3:
//
//Input: nums = [0]
//Output: []
//
//
//Constraints:
//
//0 <= nums.length <= 3000
//-105 <= nums[i] <= 105

#include "vector"
#include "algorithm"
using namespace std;

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int size = nums.size();
        vector<vector<int>> ret;

        for(int i=0; i < size; i++)
        {
            if(i>0)
            {
                if(nums[i]==nums[i-1])
                    continue;
            }

            int low = i+1, high = size-1;
            while(low<high)
            {
                if(nums[low]+nums[high] < (-1*nums[i]) )
                {
                    low++;
                }
                else if( nums[low] + nums[high] > -1*nums[i])
                {
                    high--;
                }
                else
                {

                    ret.push_back({nums[i],nums[low],nums[high]});

                    while(low+1 < size && nums[low]==nums[low+1])
                    {
                        low++;
                    }

                    while( high-1 >= 0 && nums[high]==nums[high-1])
                    {
                        high--;
                    }

                    low++; high--;
                }
            }
        }
        return ret;
    }
};
