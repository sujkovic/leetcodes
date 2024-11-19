//  brute force go down every possible path
//  dfs
//      if out of bounds return 0
//      if at finish return 1
//      return dfs(row + 1, col) + dfs(row, col + 1)

//  Finished in 4 min, TLE
//  Time - O(2^(m + n))
//  Space - O(m + n)

/*
class Solution {
public:
    int dfs(int &rows, int &cols, int row, int col) {
        if (row == rows || col == cols) {
            return 0;
        }
        if (row == rows - 1 && col == cols - 1) {
            return 1;
        }

        return dfs(rows, cols, row + 1, col) + dfs(rows, cols, row, col + 1);
    }
    int uniquePaths(int m, int n) {
        return dfs(m, n, 0, 0);
    }
};
*/

//  Optimize with memoization to m * n
//  Solved this pat in 3 min

/*
class Solution {
public:
    int dfs(vector<vector<int>> & cache, int &rows, int &cols, int row, int col) {
        if (row == rows || col == cols) {
            return 0;
        }
        if (row == rows - 1 && col == cols - 1) {
            return 1;
        }
        if (cache[row][col] != -1) {
            return cache[row][col];
        }

        cache[row][col] = dfs(cache, rows, cols, row + 1, col) + dfs(cache, rows, cols, row, col + 1);
        return cache[row][col];
    }
    int uniquePaths(int m, int n) {
        vector<vector<int>> cache(m, vector<int>(n, -1));
        return dfs(cache, m, n, 0, 0);
    }
};
*/

//  DP approach
//  looking at last example the solution at any point seems to just be 
//      solution at 1 up + solution at 1 left

//  ex
//  0 0 0 0
//  0 0 0 0
//  0 0 0 0

//  10 6 3 1
//  4 3 2 1
//  1 1 1 0

//  ok worked through that until it made sense, basically set all row = 0, col = 0 to 1
//  except for the original one, its 0
//  then the answer at each is just the answer at up 1 + the answer at left 1
//  probably gonna code from the top left tho so reversed

//  Solved this one in 9 min
//  Time - O(m * n)
//  Space - O(m * n)

/*
class Solution {
public:
    int uniquePaths(int m, int n) {
        vector<vector<int>> dp(m, vector<int>(n, 0));

        for (int row = 0; row < m; row++) {
            for (int col = 0; col < n; col++) {
                if (row == 0 || col == 0) {
                    dp[row][col] = 1;
                }
                else {
                    dp[row][col] = dp[row - 1][col] + dp[row][col - 1];
                }
            }
        }

        return dp[m - 1][n - 1];
    }
};
*/

//  Can optimize further by making the space O(n) since we only need the last row
//  and can keep a variable for the element to the left

//  Solved this part in 3 min
//      Just had to change curRow init to 1 instead of 0 for the case of
//      rows > 1, col = 1
//  Time - O(m * n)
//  Space - O(n)

class Solution {
public:
    int uniquePaths(int m, int n) {
        vector<int> prevRow(n, 1);

        for (int row = 1; row < m; row++) {
            vector<int> curRow(n, 1);
            int leftOne = 1;

            for (int col = 1; col < n; col++) {
                curRow[col] = prevRow[col] + leftOne;
                leftOne = curRow[col];
            }

            prevRow = curRow;
        }

        return prevRow[n - 1];
    }
};

//  Total 20 min