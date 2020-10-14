//
// Created by tzurm on 10/14/2020.
//
//Given a set of non-overlapping intervals, insert a new interval into the intervals (merge if necessary).
//
//You may assume that the intervals were initially sorted according to their start times.
//
//
//
//Example 1:
//
//Input: intervals = [[1,3],[6,9]], newInterval = [2,5]
//Output: [[1,5],[6,9]]
//
//Example 2:
//
//Input: intervals = [[1,2],[3,5],[6,7],[8,10],[12,16]], newInterval = [4,8]
//Output: [[1,2],[3,10],[12,16]]
//Explanation: Because the new interval [4,8] overlaps with [3,5],[6,7],[8,10].
//
//Example 3:
//
//Input: intervals = [], newInterval = [5,7]
//Output: [[5,7]]
//
//Example 4:
//
//Input: intervals = [[1,5]], newInterval = [2,3]
//Output: [[1,5]]
//
//Example 5:
//
//Input: intervals = [[1,5]], newInterval = [2,7]
//Output: [[1,7]]


#include "vector"
#include "algorithm"
using namespace std;

class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        if(!intervals.size()){
            intervals.push_back(newInterval);
            return intervals;
        }
        vector<vector<int>> ret;
        int index;
        intervals.push_back(newInterval);
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