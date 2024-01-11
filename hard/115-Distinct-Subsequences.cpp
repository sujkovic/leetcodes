//  make a recursive tree building function
//      keep track of sIndex, tIndex
//  at any index, scan all the characters in s left of sIndex, checking if theyre equal to t[tIndex]
//      if yes, perform a dfs call on that sIndex and tIndex + 1
//  return sum of all dfs calls made within that dfs call'

//  this makes it to 63/65 cases then TLE rip
//  Spent around 30 min on this
/*
class Solution {
public:
    int dfs(string &s, string &t, int sIndex, int tIndex, vector<vector<int>> &memo) {
        if (tIndex == t.length()) {
            return 1;
        }
        if (memo[sIndex][tIndex] != -1) {
            return memo[sIndex][tIndex];
        }
        int res = 0;
        for (int i = sIndex; i < s.length(); i++) {
            if (s[i] == t[tIndex]) {
                char curChar = '0' + i;
                res += dfs(s, t, i + 1, tIndex + 1, memo);
            }
        }
        memo[sIndex][tIndex] = res;
        return res;
    }
    int numDistinct(string s, string t) {
        int sLen = s.length();
        int tLen = t.length();
        vector<vector<int>> memo(sLen + 1, vector<int>(tLen + 1, -1));
        return dfs(s, t, 0, 0, memo);
    }
};
*/

//  DP tabulation 
//  ex.
//       . r a b b b i t
//     . 1 0 0 0 0 0 0 0       
//     r 0 1 1 1 1 1 1 1        
//     a 0 0 1 1 1 1 1 1         
//     b 0 0 0 1 2 3 3 3        
//     b 0 0 0 0 2 3 3 3          
//     i 0 0 0 0 0 0 3 3                
//     t 0 0 0 0 0 0 0 3           

//    b a b g b a g
//  b 1 1 2 2 3 3 3
//  a 0 1 1 1 1 4 4
//  g 0 0 0 1 1 1 5

//  ok went thru a bunch of examples i think i get it
//  the vertical word is our subproblem
//  as we iterate through the horizontal word at each level,
//      the above value represents the # solutions for the previous subproblem
//      so at the current one, we check if the cur char in each word is equal
//      if it is
//          cur res = left + up
//          because to the left is the number of ways we've found to solve our current subproblem so far
//          and on top is the # of ways to solve the previous problem up until the previous char
//      otherwise just set cur to wtv is to the left of it
//  return the last cell in matrix

//  Time - O(m * n) - double for loop of input strings size m and n
//  Space - O(m * n) - dp matrix of size m * n

//  Solved in 55 minutes
//      Spent the last 20 troubleshooting int overflow (had to use unsigned int) and double counting same chars
//          (looked at solution, had to change line 88 from dp[i][j + 1] + dp[i + 1][j] to dp[i][j] + dp[i + 1][j])
//      Still not 100% why that works tbh, but i literally just had to change a i + 1 to an i so i basically solved
//      this problem myself wooo

class Solution {
public:
    int numDistinct(string s, string t) {
        int sLen = s.length();
        int tLen = t.length();
        vector<vector<unsigned int>> dp(tLen + 1, vector<unsigned int>(sLen + 1, 0));
        for (int i = 0; i < sLen + 1; i++) {
            dp[0][i] = 1;
        }

        for (int i = 0; i < tLen; i++) {
            for (int j = 0; j < sLen; j++) {
                if (t[i] == s[j]) {
                    dp[i + 1][j + 1] = dp[i][j] + dp[i + 1][j];
                }
                else {
                    dp[i + 1][j + 1] = dp[i + 1][j];
                }
            }
        }

        return dp[tLen][sLen];
    }
};