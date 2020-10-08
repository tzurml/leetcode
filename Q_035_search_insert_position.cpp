//
// Created by tzur on 10/8/2020.
//
//Given a sorted array of distinct integers and a target value, return the index if the target is found. If not, return the index where it would be if it were inserted in order.
//Example 1:
//
//Input: nums = [1,3,5,6], target = 5
//Output: 2
//Example 2:
//
//Input: nums = [1,3,5,6], target = 2
//Output: 1
//Example 3:
//
//Input: nums = [1,3,5,6], target = 7
//Output: 4
//Example 4:
//
//Input: nums = [1,3,5,6], target = 0
//Output: 0
//Example 5:
//
//Input: nums = [1], target = 0
//Output: 0

#include "vector"
using namespace std;

class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
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
        return left;
    }
};