//  make a new results matrix
//  loop through og matrix
//  at each cell in the og matrix
//      perform the smoothing calculation 
//      set that corresponding result in res to the result of the calculation
//  return results

//  Time - O(m * n) - Loop through matrix of size m * n
//  Space - O(1) - No new data structs, only the result 

//  Solved in 12 minutes

class Solution {
public:
    int calcAvg(vector<vector<int>>& img, int &row, int &col) {
        int sum = 0;
        int numValidCells = 0;
        for (int i = row - 1; i <= row + 1; i++) {
            for (int j = col - 1; j <= col + 1; j++) {

                if (i >= 0 && i < img.size() && j >= 0 && j < img[0].size()) {
                    numValidCells++;
                    sum += img[i][j];
                }
            }
        }

        return floor(sum / numValidCells);
    }

    vector<vector<int>> imageSmoother(vector<vector<int>>& img) {
        int rows = img.size();
        int cols = img[0].size();
        vector<vector<int>> res(rows, vector<int>(cols, 0));
        for (int row = 0; row < rows; row++) {
            for (int col = 0; col < cols; col++) {
                res[row][col] = calcAvg(img, row, col);
            }
        }
        
        return res;
    }
};