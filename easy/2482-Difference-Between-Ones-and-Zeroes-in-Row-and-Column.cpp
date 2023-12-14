//  Make four vectors for keeping track of ones/zeroes in each row/col
//  Fill those vecs in with two passes of the grid
//  Go through grid again, evaluating the diff of each index now that we can look up all the parts of the equation in constant time

//  Time - O(m * n) - Loop through m x n grid three times
//  Space - O(m + n) - Sizes of helper vecs

//  Solved in 12 minutes

class Solution {
public:
    vector<vector<int>> onesMinusZeros(vector<vector<int>>& grid) {
        int rows = grid.size();
        int cols = grid[0].size();
        vector<int> onesRow(rows, 0);
        vector<int> onesCol(cols, 0);
        vector<vector<int>> result(rows, vector<int>(cols, 0));

        for (int row = 0; row < rows; row++) {
            int numOnes = 0;
            for (int col = 0; col < cols; col++) {
                numOnes += grid[row][col];
            }
            onesRow[row] = numOnes;
        }

        for (int col = 0; col < cols; col++) {
            int numOnes = 0;
            for (int row = 0; row < rows; row++) {
                numOnes += grid[row][col];
            }
            onesCol[col] = numOnes;
        }

        for (int row = 0; row < rows; row++) {
            for (int col = 0; col < cols; col++) {
                int zeroesRow = rows - onesRow[row];
                int zeroesCol = cols - onesCol[col];
                result[row][col] = onesRow[row] + onesCol[col] - zeroesRow - zeroesCol;
            }
        }

        return result;
    }
};