//  2 pointer starting from both ends of the array
//  keep a vec of counts of the three characters
//  while left <= right
//      if (vec[s[left]] < k)
//          vec[s[left]]++
//          left++
//      else 
//          vec[s[right]]++
//          right--
//      if vec at all indicies >= k
//          return arrSize - (right - left) - 1
//  return -1

//  not sure if this'll work tho for the case where neither left/right is < k but we dont know which side is closer
//  wait could just do a pass from both sides and change which side we explore first?
//  yeah no still clipped
//  calling it here at 20 min gonna check the neetcode vid

/*
class Solution {
public:
    int takeCharacters(string s, int k) {
        if (k == 0) {
            return 0;
        }
        unordered_map<char, int> counts;
        int left = 0;
        int right = s.length() - 1;
        int minLeft = INT_MAX;
        int minRight = INT_MAX;

        while (left <= right) {
            if (counts[s[left]] < k) {
                counts[s[left]]++;
                left++;
            }
            else {
                counts[s[right]]++;
                right--;
            }
            if (counts['a'] >= k && counts['b'] >= k && counts['c'] >= k) {
                minLeft = min(minLeft, (int)s.length() - (right - left) - 1);
            }
        }

        while (left <= right) {
            if (counts[s[right]] < k) {
                counts[s[right]]++;
                right--;
            }
            else {
                counts[s[left]]++;
                left++;
            }
            if (counts['a'] >= k && counts['b'] >= k && counts['c'] >= k) {
                minLeft = min(minLeft, (int)s.length() - (right - left) - 1);
            }
        }

        if (minLeft == INT_MAX && minRight == INT_MAX) {
            return -1;
        }

        return min(minLeft, minRight);
    }
};
*/

//  ok so we basically want to invert how we're looking at the problem
//  so instead of trying to greedily find the minimum left/right subwindows that meet our constraints,
//  find the maximum middle subwindow that still meets our constraints
//  use sliding window, this way its not a greedy approach and every possibility is checked

//  a a b a a a a c a a b c
// lr
//  l r
//  l   r
//       lr
//        l r
//        l   r
//        l     r
//                 lr
//                  l r


//  first, get the count of each number
//  if any are less than k return -1 
//  left = 0, right = 0
//  while right < nums size
//      counts[s[right]]--
//      if counts[curChar < k]
//          while (left <= right)
//              counts[s[left]]++
//              left++
//      else
//          update res to min res, (arrSize - (right - left) - 1)
//      right++

//  Solved in 17 min
//      had an if/else in the while loop but had to get rid of it for edge cases
//      where we wanted to update the res but weren't
//  Time - O(n)
//  Space - O(1)

class Solution {
public:
    int takeCharacters(string s, int k) {
        unordered_map<char, int> counts;

        for (int i = 0; i < s.length(); i++) {
            counts[s[i]]++;
        }

        if (counts['a'] < k || counts['b'] < k || counts['c'] < k) {
            return -1;
        }

        int left = 0;
        int right = 0;
        int res = s.length();

        while (left < s.length()) {
            counts[s[right]]--;
            
            while (counts[s[right]] < k && left < s.length()) {
                counts[s[left]]++;
                left++;
            }
            
            res = min(res, (int)s.length() - (right - left) - 1);
            right++;
        }

        return res;
    }
};
