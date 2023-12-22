//  add all the x coords to a new vec
//  sort the vec
//  iterate thru vec, returnng biggest difference between 2 consecutive points

//  Time - O(nlogn) - Iterate thru array of size n and sort it
//  Space - O(n) - new vec, but could also just use the existing vec i just realized

//  Solved in under 4 minutse bruh how is this a medium lmao

class Solution {
public:
    int maxWidthOfVerticalArea(vector<vector<int>>& points) {
        vector<int> vec;
        int res = 0;

        for (int i = 0; i < points.size(); i++) {
            vec.push_back(points[i][0]);
        }

        sort(vec.begin(), vec.end());
        for (int i = 1; i < vec.size(); i++) {
            res = max(res, vec[i] - vec[i - 1]);
        }

        return res;
    }
};