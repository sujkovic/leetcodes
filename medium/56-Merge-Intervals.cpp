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