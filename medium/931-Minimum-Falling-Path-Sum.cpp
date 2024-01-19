//      Recursive       //

//  this seems like dp, do a dfs from each cell at the top of the matrix
//  in each dfs call, can either go down, down and left, or down and right
//  return the minimum of each call
//  base cases are gonna be if we're out of bounds left/right return int max or wtv the max is
//          and if we hit the bottom row, return the current sum

//  Time - O(3^n) - Decision tree of height n where n is the # rows, and at each point we can make 3 decisions (left down, down, right down)
//  Space - O(n) - recursive call stack

//  Finished in 8 minutes (TLE)


//  For memo, cache the current index 


//  Time - O(m * n) - go through all cells in input matrix
//  Space - O(m * n) - memo size

//  Solved in 11 minutes (3min memo)
/*
class Solution {
public:
    int dfs(vector<vector<int>> &matrix, vector<vector<int>> &memo, int row, int col) {
        if (col < 0 || col >= matrix[0].size()) {
            return INT_MAX;
        }
        if (row == matrix.size()) {
            return 0;
        }
        if (memo[row][col] != INT_MAX) {
            return memo[row][col];
        }

        int left = dfs(matrix, memo, row + 1, col - 1);
        int middle = dfs(matrix, memo, row + 1, col);
        int right = dfs(matrix, memo, row + 1, col + 1);
        
        memo[row][col] = matrix[row][col] + min(left, min(middle, right));
        return memo[row][col];
    }
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int res = INT_MAX;
        vector<vector<int>> memo(matrix.size(), vector<int>(matrix[0].size(), INT_MAX));

        for (int i = 0; i < matrix[0].size(); i++) {
            res = min(res, dfs(matrix, memo, 0, i));
        }

        return res;
    }
};
*/

//      Iterative DP    //

//  Recurrence relation is just the cur min is the cur cel + the min of the 3 cells above it 
//  Was gonna code it with entire cache but you only need the prev row

//  Time - O(m * n) - go thru input matrix
//  Space - O(n) - where n is the size of rows in matrix, since you only need to store one row at a time

//  Solved in 10 minutes

class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int res = INT_MAX;
        vector<int> memo;
        for (int i = 0; i < matrix[0].size(); i++) {
            memo.push_back(matrix[0][i]);
        }

        for (int i = 1; i < matrix.size(); i++) {
            vector<int> curRow;
            for (int j = 0; j < matrix[0].size(); j++) {
                int cur = matrix[i][j];

                if (j == 0) {
                    cur += min(memo[j], memo[j + 1]);
                }
                else if (j == matrix[0].size() - 1) {
                    cur += min(memo[j - 1], memo[j]);
                }
                else {
                    cur += min(memo[j - 1], min(memo[j], memo[j + 1]));
                }

                curRow.push_back(cur);
            }

            memo = curRow;
        }

        for (int i = 0; i < matrix[0].size(); i++) {
            res = min(res, memo[i]);
        }

        return res;
    }
};