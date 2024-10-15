//  SOLVED ON NEETCODE.IO, NOT LEETCODE

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

//  0                  40
//    5  10
//          15  20

// 0  5  15
// 10 20 40

//  0 -> 5 -> 10 -> 15 -> 20 -> 40
//  s    s    e     s     e     e
//  1    2    1     2     1     0

//  solved in ~20 min, a day after watching the neetcode explanation

class Solution
{
public:
    int minMeetingRooms(vector<Interval> &intervals)
    {
        vector<int> startTimes;
        vector<int> endTimes;
        int rooms = 0;
        int res = 0;

        for (int i = 0; i < intervals.size(); i++)
        {
            startTimes.push_back(intervals[i].start);
            endTimes.push_back(intervals[i].end);
        }

        sort(startTimes.begin(), startTimes.end());
        sort(endTimes.begin(), endTimes.end());

        int startTimesIt = 0;
        int endTimesIt = 0;

        while (endTimesIt < endTimes.size())
        {
            if ((startTimesIt < startTimes.size()) && (startTimes[startTimesIt] < endTimes[endTimesIt]))
            {
                rooms++;
                res = max(res, rooms);
                startTimesIt++;
            }
            else
            {
                rooms--;
                endTimesIt++;
            }
        }

        return res;
    }
};
