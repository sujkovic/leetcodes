//  keep int res, increment it as you go through string s
//  loop through string s
//      if s[i] == i, check if s[i + 1] == V or X
//          handle special case, increment i again cause were skipping one
//      same thing for the other special cases
//      else just add cur to res
//  return res

//  let n = s.length()
//  Time Complexity - O(n) - iterate through s once
//  Space Complexity - O(1) - only declaring a few int variables
//  Solved in 10 minutes

class Solution {
public:
    int romanToInt(string s) {
        int res = 0;
        int end = s.length() - 1;
        for (int i = 0; i < s.length(); i++) {
            //  6 special cases
            if (s[i] == 'I' && i < end && s[i + 1] == 'V') {
                res += 4;
                i++;
                continue;
            }
            else if (s[i] == 'I' && i < end && s[i + 1] == 'X') {
                res += 9;
                i++;
                continue;
            }
            else if (s[i] == 'X' && i < end && s[i + 1] == 'L') {
                res += 40;
                i++;
                continue;
            }
            else if (s[i] == 'X' && i < end && s[i + 1] == 'C') {
                res += 90;
                i++;
                continue;
            }
            else if (s[i] == 'C' && i < end && s[i + 1] == 'D') {
                res += 400;
                i++;
                continue;
            }
            else if (s[i] == 'C' && i < end && s[i + 1] == 'M') {
                res += 900;
                i++;
                continue;
            }
            //  normal cases
            if (s[i] == 'I') {
                res += 1;
            }
            else if (s[i] == 'V') {
                res += 5;
            }
            else if (s[i] == 'X') {
                res += 10;
            }
            else if (s[i] == 'L') {
                res += 50;
            }
            else if (s[i] == 'C') {
                res += 100;
            }
            else if (s[i] == 'D') {
                res += 500;
            }
            else if (s[i] == 'M') {
                res += 1000;
            }
        }
        return res;
    }
};