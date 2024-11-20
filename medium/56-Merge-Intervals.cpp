//  Solved October 2024

//  1  3
//   2    6
//        6     10
//                     15   18

//  1           10
//                     15   18

//  if prev.start <= cur.start <= prev.end
//      merge them
//  keep a "prev" interval so that when you have back to back to back merges it works

//  solved in 18 min
//  kept having to fix edge cases work on spotting that out earlier like straight pseudocode it first

class Solution
{
public:
    vector<vector<int>> merge(vector<vector<int>> &intervals)
    {
        vector<vector<int>> res;
        sort(intervals.begin(), intervals.end());
        vector<int> prev = {intervals[0][0], intervals[0][1]};

        for (int i = 1; i < intervals.size(); i++)
        {
            if ((prev[0] <= intervals[i][0]) && (intervals[i][0] <= prev[1]))
            {
                prev[1] = max(intervals[i][1], prev[1]);
            }
            else
            {
                res.push_back(prev);
                prev = {intervals[i][0], intervals[i][1]};
            }
        }

        res.push_back(prev);
        return res;
    }
};


//  Solved November 2024


//  1  3
//   2     6
//           8  10
//                      15   18
//  ^ want to merge 1-3 and 2-6 into 1-6

//  so given 2 intervals, a - b and c - d
//  they are overlapping if
//      a <= c <= b
//  then merge them by setting the new interval e - f to
//      e = min(a, c)     f = max(b, d)

//  we can sort intervals by the first index in ascending order
//  then iterate through intervals from i = 1 to intervalsSize - 1
//      use logic above 

//  Solved in 7 min accepted on first compile
//  Time - O(nlogn)
//  Space - O(sort)

class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end());
        vector<vector<int>> res;
        vector<int> prev = intervals[0];

        for (int i = 1; i < intervals.size(); i++) {
            if (prev[0] <= intervals[i][0] && intervals[i][0] <= prev[1]) {
                prev = {min(intervals[i][0], prev[0]), max(intervals[i][1], prev[1])};
            }
            else {
                res.push_back(prev);
                prev = intervals[i];
            }
        }

        res.push_back(prev);
        return res;
    }
};