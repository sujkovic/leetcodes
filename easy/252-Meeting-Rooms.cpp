//  Solved October 2024
//  SOLVED ON NEETCODE

/**
 * Definition of Interval:
 * class Interval {
 * public:
 *     int start, end;
 *     Interval(int start, int end) {
 *         this->start = start;
 *         this->end = end;
 *     }
 * }
 */

class Solution
{
public:
    bool canAttendMeetings(vector<Interval> &intervals)
    {
        vector<pair<int, int>> vec;
        for (int i = 0; i < intervals.size(); i++)
        {
            vec.push_back({intervals[i].start, intervals[i].end});
        }
        sort(vec.begin(), vec.end());

        for (int i = 1; i < vec.size(); i++)
        {
            // cout << intervals[i].start << " " << intervals[i].end << endl;
            if ((vec[i].first > vec[i - 1].first && vec[i].first < vec[i - 1].second) ||
                (vec[i].first <= vec[i - 1].first && vec[i].second >= vec[i - 1].second))
            {
                return false;
            }
        }

        return true;
    }
};




//  Solved November 2024

//  basically asking are there any overlapping intervals
//  aka given an interval a - b and c - d
//      overlaps if a <= c < b
//  ^ sort the input and just check for that condition every int[i], int[i - 1]

//  Solved in 4 min, accepted on first compile
//  Time - O(nlogn)
//  Space - O(1)

class Solution {
public:
    bool canAttendMeetings(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end());

        for (int i = 1; i < intervals.size(); i++) {
            if (intervals[i - 1][0] <= intervals[i][0] && intervals[i][0] < intervals[i - 1][1]) {
                return false;
            }
        }

        return true;
    }
};