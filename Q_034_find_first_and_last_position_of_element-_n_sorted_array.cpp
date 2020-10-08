//
// Created by tzur on 10/8/2020.
//
//Given an array of integers nums sorted in ascending order, find the starting and ending position of a given target value.
//
//If target is not found in the array, return [-1, -1].
//
//Follow up: Could you write an algorithm with O(log n) runtime complexity?
//
//Example 1:
//
//Input: nums = [5,7,7,8,8,10], target = 8
//Output: [3,4]
//Example 2:
//
//Input: nums = [5,7,7,8,8,10], target = 6
//Output: [-1,-1]
//Example 3:
//
//Input: nums = [], target = 0
//Output: [-1,-1]


#include "vector"

using namespace std;


class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int> ret = {-1,-1};
        int index = find_num_log_n(nums,target);
        if (index == -1) return ret;

        int start = index, end = index;

        while(start >= 0 && nums[start] == target) start--;
        while(end < nums.size() && nums[end] == target) end++;
        ret = {start+1,end-1};
        return ret;

    }

    int find_num_log_n(vector<int>& nums, int target)
    {
        int left = 0, right = nums.size() - 1;

        if (nums.size() == 0) return -1;

        if (nums[left] == target) return left;

        if (nums[right] == target) return right;

        while (left <= right)
        {
            int mid = (left + right) / 2;

            if (nums[mid] == target) return mid;

            if (target <= nums[mid]) right = mid - 1;
            else left = mid + 1;
        }
        return -1;
    }
};