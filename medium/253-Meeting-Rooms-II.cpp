//  Solved October 2024

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



//  Solved November 2024


//  0                       30
//      5   10
//               15  20
//  ^                           1 room at this point
//      ^                       2 rooms at this point
//          ^                   1 room
//               ^              2 rooms
//                   ^          1 room
//                          ^   0 rooms

//  so evey time we encounter a start index, we add a room
//  and every time we encounter an end index, we remove a room
//  so we can make two lists, one of start times, and one of end times, sort both
//  actually what if we just make one list of both start times and end times together
//      differentiate between them by making it a list of pair<time, isStart/isEnd>

//  Solved in 7 and a half min (only compile error was [1] instead of .second for pair)
//  I'm so proud of this solution this is so beautifully clean and i thought the idea to 
//  do 1/-1 for start/end so we can just do curRooms += it is so sick (and all on my own :D)
//  Time - O(nlogn)
//  Space - O(n)

class Solution {
public:
    int minMeetingRooms(vector<vector<int>>& intervals) {
        vector<pair<int, int>> times;

        for (int i = 0; i < intervals.size(); i++) {
            times.push_back({intervals[i][0], 1});   //  1 means start time
            times.push_back({intervals[i][1], -1});   //  -1 means end time
        }

        sort(times.begin(), times.end());
        int curRooms = 0;
        int roomsNeeded = 0;

        for (int i = 0; i < times.size(); i++) {
            curRooms += times[i].second;
            roomsNeeded = max(roomsNeeded, curRooms);
        }

        return roomsNeeded;
    }
};