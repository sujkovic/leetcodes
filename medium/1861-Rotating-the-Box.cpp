//  First rotate the box clockwise
//  initialize a vec newBox of n, m
//  for each row in box, set the corresponding column in new box equal to it
//  Then we can take care of the falling logic
//  Starting at the bottom of each column
//  loop through the column going up
//      if we reach a stone, call dropStone on it

//  dropStone
//      set the stones cell to empty
//      while curCell is not out of bounds, another stone, or a wall
//          move down one
//      set the cell above our current cell as the stone

//  Solved in 23 min (half of that was me not realizing i was calling dropStone with the original box :|)
//      Also messed up the logic in dropstone and was changing col instead of row
//      Also rotated counterclockwise i think (like rows in the rotatedBox were backwards)
//  Time - O(m * n)
//  Space - O(1)


class Solution {
public:
    void dropStone(vector<vector<char>> &rotatedBox, int row, int col) {
        rotatedBox[row][col] = '.';

        while (row < rotatedBox.size() && rotatedBox[row][col] != '*' && rotatedBox[row][col] != '#') {
            row++;
        }

        rotatedBox[row - 1][col] = '#';
    }
    vector<vector<char>> rotateTheBox(vector<vector<char>>& box) {
        vector<vector<char>> rotatedBox;

        //  Rotate the box
        for (int col = 0; col < box[0].size(); col++) {
            vector<char> curCol;
            for (int row = box.size() - 1; row >= 0; row--) {
                curCol.push_back(box[row][col]);
            }
            rotatedBox.push_back(curCol);
        }

        //  Drop stones
        int rows = rotatedBox.size();
        int cols = rotatedBox[0].size();

        for (int col = 0; col < cols; col++) {
            for (int row = rows - 1; row >= 0; row--) {
                if (rotatedBox[row][col] == '#') {
                    dropStone(rotatedBox, row, col);
                }
            }
        }

        return rotatedBox;
    }
};