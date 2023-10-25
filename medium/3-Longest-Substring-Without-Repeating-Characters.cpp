//  init left to 0, right to 1, best to 1, curBest to 1
//  loop through s
//      bool dupExists = false
//      int dupIndex = -1;
//      loop from left to right, say with int j
//          if s[j] == s[right]
//              dupExists = true
//              dupIndex = j
//      if dupExists
//          left = dupIndex
//          curBest = 1
//      else
//          curBest++
//          best = max(curBest, best)
//      right++


//  let n = s.length()
//  Time Complexity - O(n^2), loop through s once, and on each iteration
//      loop from left to right, worst case entire array is unique 
//      Actually it might be O(n) since the amount of possible symbols is 
//          something like 50ish, which would be O(n * 50), not really sure tho
//  Space Complexity - O(1), no data structures used just a few ints
//  Solved in 20 minutes

//  Can optimize time complexity by using hashmap to check for dups

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        if (s.length() == 0) {
            return 0;
        }
        int left = 0;
        int right = 1;
        int best = 1;
        int curBest = 1;
        while (right < s.length()) {
            int dupIndex = -1;
            for (int i = left; i < right; i++) {
                if (s[i] == s[right]) {
                    dupIndex = i;
                }
            }
            if (dupIndex != -1) {
                curBest = curBest - (dupIndex - left);
                left = dupIndex + 1;
                //  check back here, might make left = right
            }
            else {
                curBest++;
                best = max(curBest, best);
            }
            right++;
        }
        return best;
    }
};