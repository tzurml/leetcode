//
// Created by tzur on 10/12/2020.
//
//Given an integer array nums, find the contiguous subarray (containing at least one number)
// which has the largest sum and return its sum.
//
//Follow up: If you have figured out the O(n) solution, try coding another
// solution using the divide and conquer approach, which is more subtle.
//Example 1:
//
//Input: nums = [-2,1,-3,4,-1,2,1,-5,4]
//Output: 6
//Explanation: [4,-1,2,1] has the largest sum = 6.
//Example 2:
//
//Input: nums = [1]
//Output: 1

#include <vector>
#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        if(nums.size() == 1) return nums[0];
        return helper(0, nums.size() - 1,nums);

    }

    int helper(int l, int r,vector<int>& nums)
    {
        if (r < l) return INT_MIN;

        int m = l + (r - l) / 2, x1 = 0, x2 = 0;

        int l_max = helper(l,m-1,nums);
        int r_max = helper(m+1,r,nums);
        int sum = 0;
        for (int i = m - 1; i >= l; i--) {
            sum += nums[i];
            x1 = max(sum, x1);
        }
        sum = 0;
        for (int i = m + 1; i <= r; i++) {
            sum += nums[i];
            x2 = max(sum, x2);
        }
        return max(max(l_max, r_max) , x1 + x2 + nums[m]);
    }
};