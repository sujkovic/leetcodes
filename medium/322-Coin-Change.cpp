//  Solved October, 2024

//  dfs
//  1 2 5

//                                                    11
//                     10                              9                                  6
//        9            8         5            8        7          4            5          4         1
//    8   7    4   7   6  3   4  3  0     7   6 3   6  5  2    3  2  -1     4  3  0    3  2  -1  0 -1  -4
//                                                                                             right here for zero
//                                                                                             amount = 0, numcoins = 3

//  gave up after 17 min, the soln was right but tle and
//      i could not figure out how to memoize it without skipping the minimum

/*
class Solution {
public:
    int dfs(vector<int> &coins, int amount, int numCoins, int &res, unordered_map<int, int> &memo) {
        cout << "Cur amount: " << amount << endl;
        if (amount == 0) {
            memo[amount] = numCoins;
            return numCoins;
        }
        if (amount < 0) {
            return amount;
        }
        if (memo.find(numCoins) != memo.end()) {
            return memo[numCoins];
        }

        int curRes = INT_MAX;
        for (int i = 0; i < coins.size(); i++) {
            cout << "coins[" << i << "]\n";
            if (amount - coins[i] >= 0) {
                curRes = min(curRes, dfs(coins, amount - coins[i], numCoins + 1, res, memo));
            }
        }

        memo[numCoins] = curRes;
        res = min(res, curRes);
        return res;
    }
    int coinChange(vector<int>& coins, int amount) {
        unordered_map<int, int> memo;
        int res = INT_MAX;
        dfs(coins, amount, 0, res, memo);
        return res;
    }
};
*/

//  1 2 5     11

//  0  1  2  3  4  5  6  7  8  9  10  11      coins
//  0  1  1  2  2  1  2  2  3  3  2   3       dp

//  at any point in the dp array, to get the current result -
//      loop thru all the coins, cur index - that coin
//      the lowest one + 1 is the result

class Solution
{
public:
    int coinChange(vector<int> &coins, int amount)
    {
        vector<int> dp(amount + 1, amount + 1);
        dp[0] = 0;

        for (int i = 1; i <= amount; i++)
        {
            for (int j = 0; j < coins.size(); j++)
            {
                if (i - coins[j] >= 0)
                {
                    dp[i] = min(dp[i - coins[j]] + 1, dp[i]);
                }
            }
        }

        if (dp[amount] > amount)
        {
            return -1;
        }
        return dp[amount];
    }
};


//  Solved January, 2025

//  Solution 1 - Recursive decision tree
//                                                        11
//                        6                                   9                                 10
//          1             4            5           4          7           8           5          8           9 
//   -4    -1    0     -1   2  3     0   3  4   ....
//             answer

//  base cases:
//      amount < 0 -> return INT_MAX
//      amount == 0 -> return numCoins used
//  then loop through the coins we have, calling dfs on each
//  return the smallest dfs result (aka smallest number of coins used) and add 1 if not int_max

//  Solved in 11 min
//  Time - O(c^a) where c = coins.size, a = amount
//      c is the branching factor at each decision, a is the height of the decision tree
//  Space - O(a)

/*
class Solution {
public:
    int dfs(vector<int> &coins, int amount) {
        if (amount < 0) {
            return INT_MAX;
        }
        if (amount == 0) {
            return 0;
        }

        int result = INT_MAX;

        for (int i = 0; i < coins.size(); i++) {
            int curResult = dfs(coins, amount - coins[i]);

            if (curResult != INT_MAX) {
                result = min(result, curResult + 1);
            }
        }

        return result;
    }
    int coinChange(vector<int>& coins, int amount) {
        int result = dfs(coins, amount);
        return result == INT_MAX ? -1 : result;
    }
};
*/

//  Solution 2 - Memoized recursive

//  Solved in 1 minute
//  Time - O(coinsSize * amount)
//  Space - O(amount)

/*
class Solution {
public:
    int dfs(vector<int> &coins, vector<int> &memo, int amount) {
        if (amount < 0) {
            return INT_MAX;
        }
        if (amount == 0) {
            return 0;
        }
        if (memo[amount] != -1) {
            return memo[amount];
        }

        int result = INT_MAX;

        for (int i = 0; i < coins.size(); i++) {
            int curResult = dfs(coins, memo, amount - coins[i]);

            if (curResult != INT_MAX) {
                result = min(result, curResult + 1);
            }
        }

        memo[amount] = result;
        return result;
    }
    int coinChange(vector<int>& coins, int amount) {
        vector<int> memo(amount + 1, -1);
        int result = dfs(coins, memo, amount);
        return result == INT_MAX ? -1 : result;
    }
};
*/

//  Solution 3 - DP


//  i
//  0 1 2 3 4 5 6 7 8 9 10 11  <- a
//  0 1 1 0 0 1 0 0 0 0 0  0
//  0 1 1 2 2 1 2 2 0 0 2          

//  ok scratch that, spent 7 min trying to think of this and went to the neetcode video
//  just had to watch like 5 seconds of him starting the dp part to remember how to do this

//  first, initialize the dp array to all zeroes, but put 1 where theres a coin for that amount
//  then just iterate from 0 to amount, the dp value at each index will be the following:
//      dp[i] = min(dp[i], dp[i - coins[0]] + 1, dp[i - coins[1]] + 1, ..... , dp[i - coins[n - 1]] + 1)
//  aka for a given subproblem, check every subproblem youve already solved from the cur amount - every possible coin

//  Solved in 16 min
//      did < amount instead of <=, init. dp to 0's instead of int_max, and forgot to check prev subproblem is not int_max before updating dp[i]
//      that debugging took around 6 min
//  Time - O(c * a)
//  Space - O(a)

/*
class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        if (amount == 0) {
            return 0;
        }

        vector<int> dp(amount + 1, INT_MAX);
        dp[0] = 1;

        //  init dp array with given coins
        for (int i = 0; i < coins.size(); i++) {
            if (coins[i] <= amount) {
                dp[coins[i]] = 1;
            }
        }

        for (int i = 1; i <= amount; i++) {
            for (int j = 0; j < coins.size(); j++) {
                if (i - coins[j] >= 0 && dp[i - coins[j]] != INT_MAX) {    //  check out of bounds
                    dp[i] = min(dp[i], dp[i - coins[j]] + 1);
                }
            }
        }

        return dp[amount] == INT_MAX ? -1 : dp[amount];
    }
};
*/

//  Just making the code a bit cleaner after looking at neetcode solution

class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        vector<int> dp(amount + 1, amount + 1);
        dp[0] = 0;

        for (int i = 1; i <= amount; i++) {
            for (int j = 0; j < coins.size(); j++) {
                if (i - coins[j] >= 0) {    //  check out of bounds
                    dp[i] = min(dp[i], dp[i - coins[j]] + 1);
                }
            }
        }

        return dp[amount] > amount ? -1 : dp[amount];
    }
};