//  make a map of reachable numbers for each number with knight moves
//  make a decision tree function that explores every possible path
//      params should be cur number, should return sum of recursive calls

//  Time - O(n)
//      decision tree would be k^n where k is num digits, but we memoize so time goes down to n*k, and k is constant so its just n

//  Space - O(n)
//      Recursive call stack is n, memo is n

//  Took about an hour
//      Basically done in 20, but accidentally put 'i' instead of 'map[curNum][i]' on line 42 and spent 45 minutes debugging until I realized :D
//      Also checked discussion second for a sec just to see how they handled memoizing cause I couldn't come up with it

class Solution
{
public:
    int mod = 1e9 + 7;
    void initMap(vector<vector<int>> &map)
    {
        map = {{4, 6},
               {6, 8},
               {7, 9},
               {4, 8},
               {0, 3, 9},
               {},
               {0, 1, 7},
               {2, 6},
               {1, 3},
               {2, 4}};
    }
    long decisionTree(vector<vector<int>> &map, vector<vector<int>> &memo, int curNum, int remaining)
    {
        if (remaining == 1)
        {
            return 1;
        }
        if (memo[remaining][curNum])
        {
            return memo[remaining][curNum];
        }

        int total = 0;
        for (int i = 0; i < map[curNum].size(); i++)
        {
            total = (total + decisionTree(map, memo, map[curNum][i], remaining - 1)) % mod;
        }

        memo[remaining][curNum] = total;
        return memo[remaining][curNum];
    }
    int knightDialer(int n)
    {
        vector<vector<int>> map;
        vector<vector<int>> memo(n + 1, vector(10, 0));
        initMap(map);
        int total = 0;

        for (int i = 0; i < 10; i++)
        {
            total = (total + decisionTree(map, memo, i, n)) % mod;
        }

        return total;
    }
};