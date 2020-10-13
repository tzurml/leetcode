//
// Created by tzurm on 10/13/2020.
//
//Given a collection of intervals, merge all overlapping intervals.
//
//Example 1:
//
//Input: intervals = [[1,3],[2,6],[8,10],[15,18]]
//Output: [[1,6],[8,10],[15,18]]
//Explanation: Since intervals [1,3] and [2,6] overlaps, merge them into [1,6].
//
//Example 2:
//
//Input: intervals = [[1,4],[4,5]]
//Output: [[1,5]]
//Explanation: Intervals [1,4] and [4,5] are considered overlapping.

#include "vector"
#include "iostream"
#include "algorithm"

using namespace std;

class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        if(!intervals.size()) return intervals;
        vector<vector<int>> ret;
        int index;
        sort(intervals.begin(),intervals.end());
        int start_val, end_val = intervals[0][1];
        for(int i=0; i < intervals.size();i++)
        {
            start_val = intervals[i][0];
            end_val = intervals[i][1];
            while(i < intervals.size() - 1 && intervals[i+1][0] <= end_val )
            {
                if(start_val > intervals[i+1][0]) start_val = intervals[i+1][0];
                end_val = (end_val > intervals[i+1][1]) ? end_val : intervals[i+1][1];
                i++;
            }
            vector<int> tmp = {start_val, end_val};
            ret.push_back(tmp);
        }
        return ret;
    }
};


int main()
{
    Solution s;
    vector<int> t1 = {1,4};
    vector<int> t2 = {0,4};
//    vector<int> t3 = {8,10};
//    vector<int> t4 = {15,18};
    vector<vector<int>> tmp = {t1,t2};
    auto x = s.merge(tmp);
    for(auto c : x) cout << c[0] << " " << c[1] << endl ;
}