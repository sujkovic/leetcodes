//  constraints //
//  1 <= ranges.length <= 50
//  pairs are in format <smaller, greater>
//  1 <= left <= right <= 50

//  thoughts    //
//  increment right by 1
//  sort ranges array
//  iterate through it, moving left ptr if its in cur range to end of it + 1
//  if our left is ever >= right, return true
//  else return false
//  Time: O(nlogn) - sort is nlogn, iterating is n
//  Space: O(1) - no new memory


class Solution {
public:
    bool isCovered(vector<vector<int>>& ranges, int left, int right) {
        sort(ranges.begin(), ranges.end());
        for (int i = 0; i < ranges.size(); i++) {
            if ((left >= ranges[i][0]) && left <= ranges[i][1]) {
                left = ranges[i][1];
            }
            if (left >= right) {
                return true;
            }
        }
        return false;
    }
};