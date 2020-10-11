//
// Created by tzur on 10/11/2020.

//Given a collection of distinct integers, return all possible permutations.
//
//Example:
//
//Input: [1,2,3]
//Output:
//[
//[1,2,3],
//[1,3,2],
//[2,1,3],
//[2,3,1],
//[3,1,2],
//[3,2,1]
//]
#include <vector>

using namespace std;

class Solution {
public:

    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> res;
        phelper(nums,0,nums.size() - 1,res);
        return res;

    }



    void phelper(vector<int>& nums,int l , int r,vector<vector<int>>& res)
    {
        if(l == r)
        {
            vector<int> tmp;
            for(auto p : nums)
            {
                tmp.push_back(p);
            }
            res.push_back(tmp);
            return;
        }
        for(int i = l; i <= r; i++)
        {
            swap(nums,l,i);

            phelper(nums,l+1,r,res);

            swap(nums,l,i);
        }

    }

    void swap(vector<int>& nums,int i , int j)
    {
        int temp = nums.at(i);
        nums.at(i) = nums.at(j);
        nums.at(j) = temp;
    }
};