//  sort both vectors
//  loop through g backwards, starting with the greatest value thats <= the max value in s
//      count # of values that work
//  return the count

//  Solved in 22 minutes, had to look at solution
//      thought you could just find a starting index in array s, but you could have a gap of invalid values in there for big inputs, so need to pass through both at the same time with separate pointers

//  Time - O(max(nlogn, mlogm))
//      sort and loop through once
//  Space - O(1)
//      if we assume sorting doesnt use space

class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        sort(g.begin(), g.end());
        sort(s.begin(), s.end());
        int count = 0;
        int i = 0;
        int j = 0;

        while (i < g.size() && j < s.size()) {
            if (s[j] >= g[i]) {
                count++;
                i++;
            }
            j++;
        }
        return count;
    }
};