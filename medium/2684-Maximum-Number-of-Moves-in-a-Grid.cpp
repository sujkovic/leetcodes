//  brute force would be call a dfs on each cell in the first column
//  dfs:
//      up 1 right 1
//      right 1
//      down 1 right 1
//          check if in bounds and > cur before you call them ^
//      return the max of the 3 calls

//  Finished in 20 min, TLE
//      Im surprised it got through 810/814 test cases tho

/*
class Solution {
public:
    int dfs(vector<vector<int>> &grid, int row, int col) {
        //cout << row << " " << col << endl;
        int upRight = 0;
        int right = 0;
        int downRight = 0;

        if (row > 0 && col < grid[0].size() - 1 && grid[row - 1][col + 1] > grid[row][col]) {
            upRight = dfs(grid, row - 1, col + 1) + 1;
        }
        if (col < grid[0].size() - 1 && grid[row][col + 1] > grid[row][col]) {
            right = dfs(grid, row, col + 1) + 1;
        }
        if (row < grid.size() - 1 && col < grid[0].size() - 1 && grid[row + 1][col + 1] > grid[row][col]) {
            downRight = dfs(grid, row + 1, col + 1) + 1;
        }

        return max(right, max(upRight, downRight));
    }
    int maxMoves(vector<vector<int>>& grid) {
        int result = 0;
        for (int i = 0; i < grid.size(); i++) {
            result = max(result, dfs(grid, i, 0));
        }

        return result;
    }
};
*/

//  can memoize by keeping another grid for the results of the dfs calls
//  if that cell isnt null, return it. and at the end of the func set it

//  Solved in 2 min
//  O(m * n) space and time

class Solution
{
public:
    int dfs(vector<vector<int>> &grid, int row, int col, vector<vector<int>> &memo)
    {
        if (memo[row][col])
        {
            return memo[row][col];
        }
        int upRight = 0;
        int right = 0;
        int downRight = 0;

        if (row > 0 && col < grid[0].size() - 1 && grid[row - 1][col + 1] > grid[row][col])
        {
            upRight = dfs(grid, row - 1, col + 1, memo) + 1;
        }
        if (col < grid[0].size() - 1 && grid[row][col + 1] > grid[row][col])
        {
            right = dfs(grid, row, col + 1, memo) + 1;
        }
        if (row < grid.size() - 1 && col < grid[0].size() - 1 && grid[row + 1][col + 1] > grid[row][col])
        {
            downRight = dfs(grid, row + 1, col + 1, memo) + 1;
        }

        memo[row][col] = max(right, max(upRight, downRight));
        return memo[row][col];
    }
    int maxMoves(vector<vector<int>> &grid)
    {
        vector<vector<int>> memo(grid.size(), vector<int>(grid[0].size(), 0));
        int result = 0;
        for (int i = 0; i < grid.size(); i++)
        {
            result = max(result, dfs(grid, i, 0, memo));
        }

        return result;
    }
};