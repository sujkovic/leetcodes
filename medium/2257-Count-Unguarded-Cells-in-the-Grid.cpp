//  first, initialize an empty matrix of chars with '.'
//  then, fill in all guards and walls into the matrix with 'g' and 'w'
//  then, iterate through the matrix again, this time filling out all 
//      the cells viewable by guards with an 'x'
//  then, iterate through the matrix one last time, returning the # of '.' cells

//  for handling updating viewable cells:
//  for row in rows
//      for col in cols
//          updateGuardView(matrix, row, col)

//  vector<vector<int>> directions = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}}

//  updateGuardView(matrix, row, col)
//      for (direction in directions)
//          cell += direction
//              while (in bounds and cell != wall)
//                  set cell to viewable

//  Solved in 21 min
//      Thought this problem was pretty fun lol
//  Time - O(m * n)
//  Space - O(m * n)

class Solution {
public:
    vector<vector<int>> directions = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};

    void updateGuardView(vector<vector<char>> &grid, int row, int col) {
        for (int i = 0; i < directions.size(); i++) {
            int curRow = row;
            int curCol = col;
            curRow += directions[i][0];
            curCol += directions[i][1];

            while (curRow >= 0 && curCol >= 0 && curRow < grid.size() && curCol < grid[0].size() 
                && grid[curRow][curCol] != 'w' && grid[curRow][curCol] != 'g') {
                    grid[curRow][curCol] = 'x';
                    curRow += directions[i][0];
                    curCol += directions[i][1];
            }
        }
    }

    int countUnguarded(int m, int n, vector<vector<int>>& guards, vector<vector<int>>& walls) {
        vector<vector<char>> grid(m, vector<char>(n, '.'));
        int unguardedCells = 0;

        for (int i = 0; i < guards.size(); i++) {
            grid[guards[i][0]][guards[i][1]] = 'g';
        }

        for (int i = 0; i < walls.size(); i++) {
            grid[walls[i][0]][walls[i][1]] = 'w';
        }

        for (int i = 0; i < guards.size(); i++) {
            updateGuardView(grid, guards[i][0], guards[i][1]);
        }

        for (int row = 0; row < m; row++) {
            for (int col = 0; col < n; col++) {
                if (grid[row][col] == '.') {
                    unguardedCells++;
                }
            }
        }

        return unguardedCells;
    }
};