//              DFS + Memo          //

//  dfs function
//  starting at 0, can either take 1 step or 2 steps
//  return the sum of dfs(1 step) + dfs(2 step)
//  base case is when we hit the top

//  to memoize, cache the current step that we're at

//  Time - O(n)
//  Space - O(n)

//  Solved in 5 min
/*
class Solution {
public:
    int dfs(int n, int cur, vector<int> &memo) {
        if (cur == n) {
            return 1;
        }
        if (cur > n) {
            return 0;
        }
        if (memo[cur]) {
            return memo[cur];
        }
        memo[cur] = dfs(n, cur + 1, memo) + dfs(n, cur + 2, memo);
        return memo[cur];
    }
    int climbStairs(int n) {
        vector<int> memo(n, 0);
        return dfs(n, 0, memo);
    }
};
*/

//              DP          //

//  From the dfs, we see that at any point, the result is n-1 + n-2
//  so we can basically build a dp vec of answers starting from 0, and return last

//  Same time/space as last
//  Solved in 9 min, had weird bug with the case of n = 1 and my loop starting at 3

/*
class Solution {
public:
    int climbStairs(int n) {
        vector<int> dp(n + 1, 0);
        dp[1] = 1;
        dp[0] = 1;

        for (int i = 2; i <= n; i++) {
            dp[i] = dp[i - 1] + dp[i - 2];
        }

        return dp[n];
    }
};
*/

//          DP + Space Optimized            //

//  since you only ever need the last 2 values, can just use 2 variables

//  Time - O(n)
//  Space - O(1)

//  Solved in 3 min

class Solution {
public:
    int climbStairs(int n) {
        int oneBack = 1;
        int twoBack = 1;

        for (int i = 2; i <= n; i++) {
            int temp = oneBack;
            oneBack = oneBack + twoBack;
            twoBack = temp;
        }

        return oneBack;
    }
};