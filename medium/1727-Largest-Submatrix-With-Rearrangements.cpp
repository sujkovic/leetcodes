//  Spent like an hour and a half on this with no luck, came back a few days later after the neetcode video dropped shoutout neetcode for explaining it super well

//  Keep a running count of consecutive ones within each column
//  Loop through the rows of the matrix
//      For each element in current row
//          If the above number at our current position is not 0, set cur to that number + 1
//          If our current number is zero, do nothing
//      Now, COPY the current row to a new vector and sort it
//      Now we have a nice format where we can find our biggest rectangle seen so far
//      Making a copy bc can only move entire columns at a time, not individual elements
//      Update cur best 
//  return best

//  Time - O(m * nlogn)
//      Loop through m rows, sort each row of size n
//  Space - O(n)
//      Size of the copy row we use every iteration

//  Solved in 15 minutse on second try

class Solution {
public:
    int largestSubmatrix(vector<vector<int>>& matrix) {
        int rows = matrix.size();
        int cols = matrix[0].size();
        int result = 0;

        for (int row = 0; row < rows; row++) {
            //  Update number of consecutive ones
            if (row != 0) {
                for (int col = 0; col < cols; col++) {
                    if (matrix[row][col] != 0) {
                        matrix[row][col] = matrix[row - 1][col] + 1;
                    }
                }
            }
            //  Check for new best submatrix
            vector<int> curRow = matrix[row];
            sort(curRow.rbegin(), curRow.rend());

            for (int col = 0; col < cols; col++) {
                result = max(result, (curRow[col] * (col + 1)));
            }
        }

        return result;
    }
};