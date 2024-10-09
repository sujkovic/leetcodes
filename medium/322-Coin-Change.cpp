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