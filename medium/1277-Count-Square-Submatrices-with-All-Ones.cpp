//  brute force - try every possible submatrix
//  for row in rows
//      for col in cols
//          try every possible square with current cell as top left
//          curRow = row
//          curCell = cell
//          while (curRow and curCell in bounds)
//              is the current square from row to curRow and col to curCol valid
//                  if so, increment result
//              increment curRow and curCol

//  Solved in 15 minutes (idk why leetcode accepts the bruteforce for this)
//  Time - O((m*n)^2)
//  Space - O(1)

/*
class Solution {
public:
    int countSquares(vector<vector<int>>& matrix) {
        int result = 0;
        int rows = matrix.size();
        int cols = matrix[0].size();

        for (int row = 0; row < rows; row++) {
            for (int col = 0; col < cols; col++) {
                int curRow = row;
                int curCol = col;

                while (curRow < rows && curCol < cols) {
                    bool isCurSquareValid = true;

                    for (int i = row; i <= curRow; i++) {
                        for (int j = col; j <= curCol; j++) {
                            if (matrix[i][j] == 0) {
                                isCurSquareValid = false;
                                break;
                            }
                        }
                    }

                    if (!isCurSquareValid) {
                        break;
                    }

                    curRow++;
                    curCol++;
                    result++;
                }
            }
        }

        return result;
    }
};
*/

//  DP Optimized

//  Given input matrix
//  0 1 1 1
//  1 1 1 1
//  0 1 1 1

//  Need to find a recurrence relation to cache results

//  0 1 1 1
//  1 1 2 2
//  0 1 2 3

//  Given cell x below in dp matrix
//  1 0
//  1 x
//  if x in the input matrix = 1
//      x in dp = min(1, 0, 1) + 1
//  if x is 0
//      x in dp = 0

//  the above gives you the biggest matrix you can make at any cell going up and left
//  so the result would be the sum of every cell in the dp matrix
//  (1 * 6) + (2 * 3) + (3 * 1) = 15

//  Solved in 15 min
//      had to check the neetcode vid
//      was doing it right originally then got confused and switched to a wrong approach

//  O(m * n) space and time

/*
class Solution {
public:
    int countSquares(vector<vector<int>>& matrix) {
        int result = 0;
        int rows = matrix.size();
        int cols = matrix[0].size();
        vector<vector<int>> dp(rows, vector<int>(cols, 0));

        for (int row = 0; row < rows; row++) {
            for (int col = 0; col < cols; col++) {
                if (row == 0 || col == 0 || matrix[row][col] == 0) {
                    dp[row][col] = matrix[row][col];
                }
                else {
                    dp[row][col] = min(dp[row - 1][col - 1], min(dp[row - 1][col], dp[row][col - 1])) + 1;
                }

                result += dp[row][col];
            }
        }

        return result;
    }
};
*/

//  Optimize memory to O(m)
//  2 min

/*
class Solution {
public:
    int countSquares(vector<vector<int>>& matrix) {
        int result = 0;
        int rows = matrix.size();
        int cols = matrix[0].size();
        vector<int> curRow(cols, 0);
        vector<int> prevRow(cols, 0);

        for (int row = 0; row < rows; row++) {
            for (int col = 0; col < cols; col++) {
                if (row == 0 || col == 0 || matrix[row][col] == 0) {
                    curRow[col] = matrix[row][col];
                }
                else {
                    curRow[col] = min(prevRow[col - 1], min(prevRow[col], curRow[col - 1])) + 1;
                }

                result += curRow[col];
            }
            prevRow = curRow;
            curRow = vector<int>(cols, 0);
        }

        return result;
    }
};
*/

//  Optimize to O(1) memory by just overwriting the input matrix and using it as a dp cache
//  2 min

class Solution
{
public:
    int countSquares(vector<vector<int>> &matrix)
    {
        int result = 0;
        int rows = matrix.size();
        int cols = matrix[0].size();

        for (int row = 0; row < rows; row++)
        {
            for (int col = 0; col < cols; col++)
            {
                if (!(row == 0 || col == 0 || matrix[row][col] == 0))
                {
                    matrix[row][col] = min(matrix[row - 1][col - 1], min(matrix[row - 1][col], matrix[row][col - 1])) + 1;
                }

                result += matrix[row][col];
            }
        }

        return result;
    }
};
