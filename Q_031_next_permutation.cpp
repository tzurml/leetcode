//
// Created by tzur on 10/7/2020.
//





#include "iostream"
#include "algorithm"
#include "vector"

using namespace std;

class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int end = nums.size() - 1;

        while(end > 0 && nums[end] <= nums[end -1]) end--;
        if(end <= 0)
        {
            reverse(nums.begin(),nums.end());
            return;
        }
        end--;
        int min = nums[end+1] , ind = end + 1;
        for(int i = end+1; i < nums.size() ; ++i)
        {
            if(nums[i] < min && nums[i] > nums[end])
            {
                min = nums[i];
                ind = i;
            }
        }

        int tmp = nums[ind];
        nums[ind] = nums[end];
        nums[end] = tmp;
        sort(nums.begin() + end + 1 ,nums.end());
    }
};





