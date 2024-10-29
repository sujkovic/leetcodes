//  brute force - check sum of every square possible
//  maxSquare
//  for row in rows
//      for col in columns
//          //  at every cell, try every square with cur cell as top left
//          curRow = row
//          curCol = col
//          while curRow and curCol in bounds
//              check if current row all 1s
//              check if current col all 1s
//              if both all 1s
//                  maxSquare = max(maxSquare, (curRow - row) * (curCol - col))
//              else break

//  This should be O(n * m * max(n, m)) where n = rows m = cols and will most likely tle

//  Finished in 35 min (half of that was debugging only to realize the input was chars and i was comparing to a int 0 that never existed :|)
/*
class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        int rows = matrix.size();
        int cols = matrix[0].size();
        int maxSquare = 0;

        for (int row = 0; row < rows; row++) {
            for (int col = 0; col < cols; col++) {
                int curRow = row;
                int curCol = col;
                while (curRow < rows && curCol < cols) {
                    bool isCurSquareValid = true;
                    for (int i = row; i <= curRow; i++) {
                        if (matrix[i][curCol] == '0') {
                            isCurSquareValid = false;
                        }
                    }
                    for (int i = col; i <= curCol; i++) {
                        if (matrix[curRow][i] == '0') {
                            isCurSquareValid = false;
                        }
                    }

                    if (isCurSquareValid) {
                        maxSquare = max(maxSquare, (curRow - row + 1) * (curCol - col + 1));
                        curRow++;
                        curCol++;
                    }
                    else {
                        break;
                    }
                }
            }
        }

        return maxSquare;
    }
};
*/

//  DP version
//  if up 1 and left 1 are equal AND cur is NOT zero, add 1 to up/left

//  1 0 1 0 0
//  1 0 1 1 1
//  1 1 1 2 2
//  1 0 0 1 1

//  Spent like 30 minutes on it and was stil failing some test cases so
//  looked at solutions and did it next day in 15 min
//  i think my recurrence relation was wrong originally, i was just doing dp up and right not incl diag

//  Time and space O(m * n)

/*
class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        int rows = matrix.size();
        int cols = matrix[0].size();
        vector<vector<int>> dp(rows, vector<int>(cols, 0));
        int maxLength = 0;

        for (int row = 0; row < rows; row++) {
            for (int col = 0; col < cols; col++) {
                //  init first row and col
                if (row == 0 || col == 0 || matrix[row][col] == '0') {
                    if (matrix[row][col] == '1') {
                        dp[row][col] = 1;
                    }
                }
                else {
                    dp[row][col] = min(dp[row - 1][col - 1], min(dp[row - 1][col], dp[row][col - 1])) + 1;
                }

                maxLength = max(maxLength, dp[row][col]);
            }
        }

        return maxLength * maxLength;
    }
};
*/

//  Optimized space to O(m)
//  took like 4 minutes
//  and then you can optimie it to O(1) by just keeping 3 variables but ive spent enough hours on this problem im tapping out

class Solution
{
public:
    int maximalSquare(vector<vector<char>> &matrix)
    {
        int rows = matrix.size();
        int cols = matrix[0].size();
        vector<int> curRow(cols, 0);
        vector<int> prevRow(cols, 0);
        int maxLength = 0;

        for (int row = 0; row < rows; row++)
        {
            for (int col = 0; col < cols; col++)
            {
                //  init first row and col
                if (row == 0 || col == 0 || matrix[row][col] == '0')
                {
                    if (matrix[row][col] == '1')
                    {
                        curRow[col] = 1;
                    }
                }
                else
                {
                    curRow[col] = min(prevRow[col - 1], min(prevRow[col], curRow[col - 1])) + 1;
                }

                maxLength = max(maxLength, curRow[col]);
            }

            prevRow = curRow;
            curRow = vector<int>(cols, 0);
        }

        return maxLength * maxLength;
    }
};