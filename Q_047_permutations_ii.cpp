//
// Created by tzur on 10/11/2020.
//
//Given a collection of numbers that might contain duplicates,
// return all possible unique permutations.
//
//Example:
//
//Input: [1,1,2]
//Output:
//[
//[1,1,2],
//[1,2,1],
//[2,1,1]
//]
#include <vector>
#include "algorithm"
using namespace std;

class Solution {
public:
    vector<vector<int>> res;
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        std::sort(nums.begin(),nums.end());
        phelper(nums,0,nums.size() - 1);
        return res;

    }



    void phelper(vector<int> nums,int l , int r)
    {
        if(l == r)
        {
            vector<int> tmp;
            for(auto p : nums)
            {
                tmp.push_back(p);
            }
            for(auto d : res)
            {
                if(d == tmp){return;}
            }
            res.push_back(tmp);
            return;
        }
        for(int i = l; i <= r; i++)
        {
            if(i + 1 <= r && nums.at(i) == nums.at(i + 1))
            {
                continue;
            }
            swap(nums,l,i);

            phelper(nums,l+1,r);

            swap(nums,l,i);
        }

    }

    void swap(vector<int>& nums,int i , int j)
    {
        if (nums.at(i) == nums.at(j)){return;}
        int temp = nums.at(i);
        nums.at(i) = nums.at(j);
        nums.at(j) = temp;
    }
};