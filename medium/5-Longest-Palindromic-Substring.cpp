//  brute force, try every possible substring
//  for int i = 0 to s length - 1 in s
//      for int j = i + 1 to s length - 1 in s
//          int left = i, right = j
//          isPalindrome = true
//          while left <= right
//              if s[left] != s[right]
//                  isPalindrome = false
//          if isPalindrome
//              update longest palindrome length

//  Finished in 7 minutes, TLE
//  Time - O(n^3)
//  Space - O(1)

/*
class Solution {
public:
    string longestPalindrome(string s) {
        string longest = "";
        longest += s[0];

        for (int i = 0; i < s.length(); i++) {
            for (int j = i + 1; j < s.length(); j++) {
                bool isPalindrome = true;
                int left = i;
                int right = j;

                while (left < right) {
                    if (s[left] != s[right]) {
                        isPalindrome = false;
                    }
                    left++;
                    right--;
                }

                if (isPalindrome && j - i + 1 > longest.length()) {
                    longest = s.substr(i, j - i + 1);
                }
            }
        }

        return longest;
    }
};
*/





//  Optimize


//  b a b a d
//  L R
//  L   R
//  L     R

//  b a b a d
//  L       R
//  

//  b a b a d
//  2 cases of palindrome, odd length or even
//  let == 
//                                             b
//                          ba                                   bab
//               bab              baba                baba                   babad
//      baba        babad     babad     babad.  babad     babad.  


//  could try some sort of recursion and caching

//  15 min

/*
class Solution {
public:
    int dfs(string &s, string curString, int index) {
        if (index >= s.length()) {
            return 0;
        }

        

    }
    string longestPalindrome(string s) {
        int longest = 0;

        for (int i = 0; i < s.length(); i++) {
            longest = max(longest, dfs(s, "", i));
        }
    }
};
*/




//  Scratch the last one, building off my original solution, can decrease it from 
//  n^3 to n^2 by instead of checking to see if something is a palindrome from the outside,
//  do it from the inside
//      had to check neetcode vid for this hint

//  Solved in 7 min
//  Time - O(n^2)
//  Space - O(1)

class Solution {
public:
    string longestPalindrome(string s) {
        if (s.length() == 1) {
            return s;
        }
        string longest = "";

        for (int i = 0; i < s.length(); i++) {
            //  case one, odd length
            int left = i;
            int right = i + 1;

            while (left >= 0 && right < s.length()) {
                if (s[left] != s[right]) {
                    break;
                }
                else {
                    if (right - left + 1 > longest.length()) {
                        longest = s.substr(left, right - left + 1);
                    }
                }
                left--;
                right++;
            }

            //  case two, even length
            left = i;
            right = i;

            while (left >= 0 && right < s.length()) {
                if (s[left] != s[right]) {
                    break;
                }
                else {
                    if (right - left + 1 > longest.length()) {
                        longest = s.substr(left, right - left + 1);
                    }
                }
                left--;
                right++;
            }
        }

        return longest;
    }
};