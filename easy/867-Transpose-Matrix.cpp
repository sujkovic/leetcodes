//  brute force would be just iterate through matrix row by row, 
//  pushing each row to the column of a new matrix. 
//  Technically is same complexity as modifying in place since result 
//  doesnt count for space complexity, so i guess ill just do the easier one

//  Time - O(m * n) - iterate through m*n matrix twice
//  Space - O(1) - No new data structs other than the result which doesnt count

//  Solved in 6 minutes

class Solution {
public:
    vector<vector<int>> transpose(vector<vector<int>>& matrix) {
        int rows = matrix.size();
        int cols = matrix[0].size();
        vector<vector<int>> result(cols, vector<int>(rows, 0));
        for (int row = 0; row < rows; row++) {
            for (int col = 0; col < cols; col++) {
                result[col][row] = matrix[row][col];
            }
        }
        return result;
    }
};