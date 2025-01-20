//  make two maps of int : int
//      first will be row # : # of filled cells
//      second will be col # : # of filled cells
//  and make a map of int : pair<int, int> of # in arr : (row, col) in mat
//  loop through mat, filling in the third map 
//  then, loop through arr, for each iteration:
//      increment the count at the row and col of the cur #'s location in mat
//  if the cur row or col hits the size of row/col, return it


//  Solved in 13 min
//      done in 10, spent 3 min cuz had to reverse the if statement == cols / rows
//      tried this morning and blanked out so tried again later and realized what to do right away
//      was also super tired earlier
//  Time - O(n)
//  Space - O(n)

class Solution {
public:
    int firstCompleteIndex(vector<int>& arr, vector<vector<int>>& mat) {
        int rows = mat.size();
        int cols = mat[0].size();
        unordered_map<int, pair<int, int>> matMap;
        unordered_map<int, int> rowMap;
        unordered_map<int, int> colMap;

        //  Fill in matMap
        for (int row = 0; row < rows; row++) {
            for (int col = 0; col < cols; col++) {
                matMap[mat[row][col]] = {row, col};
            }
        }

        //  Now loop through arr, populating the row and col maps
        for (int i = 0; i < arr.size(); i++) {
            int curRow = matMap[arr[i]].first;
            int curCol = matMap[arr[i]].second;
            cout << curRow << ", " << curCol << endl;

            rowMap[curRow]++;
            colMap[curCol]++;

            if (rowMap[curRow] == cols || colMap[curCol] == rows) {
                return i;
            }
        }

        return -1;
    }
};

//  1 4 5 2 6 3

//  4 3 5
//  1 2 6