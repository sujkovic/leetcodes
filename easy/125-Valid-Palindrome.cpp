//  race a car
//  l        r
//   l      r
//    l    r
//     l r      -> false

//  while l < r
//      while (s[l] is not alpha && l < r)
//          l++
//      while (s[r] is not alpha && l < r) 
//          r++
//      if (s[l] != s[r])
//          return false
//  return true

//  Solved in 12 min
//  Time - O(n) 
//  Space - O(1)

class Solution {
public:
    bool isPalindrome(string s) {
        int left = 0;
        int right = s.length() - 1;

        while (left < right) {
            while (!isalnum(s[left]) && left < right) {
                left++;
            }
            while (!isalnum(s[right]) && left < right) {
                right--;
            }
            if (tolower(s[left]) != tolower(s[right])) {
                return false;
            }
            left++;
            right--;
        }

        return true;
    }
};