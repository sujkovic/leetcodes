//  Solved October, 2023

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
/*
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
*/
//  Solved November, 2024

//  a b c a b c b b
//  l r
//  l   r
//    l   r
//      l   r
//        l   r
//            l r
//                l r

//  im thinking keep a set of visited characters, left/right ptr, result, bestResult
//  if s[right] not visited, result++, update best result, right++
//  if s[right] visited
//      while s[left] is not the duplicate char
//          pop cur char from visited
//          left++
//      left++

//  Solved in 25 min
//      can probably clean this up, also spent 10 min debugging forgetting to
//      insert the first character into the set before the loop
//  O(n) both

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        if (s.empty()) {
            return 0;
        }
        unordered_set<char> visited;
        visited.insert(s[0]);
        int left = 0;
        int right = 1;
        int curLength = 1;
        int longestSubstring = 1;

        while (right < s.length()) {
            if (visited.find(s[right]) == visited.end()) {
                visited.insert(s[right]);
                curLength++;
                right++;
            }
            else {
                while (left < right) {
                    if (s[left] == s[right]) {
                        curLength--;
                        left++;
                        break;
                    }
                    visited.erase(s[left]);
                    left++;
                }
                right++;
                curLength = right - left;
            }
            
            longestSubstring = max(longestSubstring, curLength);
        }

        return longestSubstring;
    }
};