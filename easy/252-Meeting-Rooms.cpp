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
