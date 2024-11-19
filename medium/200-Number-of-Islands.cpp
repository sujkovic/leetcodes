//  loop through the grid
//      for each cell that has a 1
//          perform a dfs from that cell and add 1 to result
//  dfs
//      if we're out of bounds, return
//      set current cell to a zero to indicate we've visited it 
//      dfs on the adjacent cells

//  Time - O(m * n)
//  Space - O(m * n) - worst case recursive call stack, the entire matrix

class Solution {
public:
    vector<vector<int>> directions = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};

    void dfs(vector<vector<char>> &grid, int row, int col) {
        cout << row << " " << col << endl;
        if (row < 0 || col < 0 || row >= grid.size() || col >= grid[0].size() || grid[row][col] == '0') {
            return;
        }

        grid[row][col] = '0';

        for (int direction = 0; direction < directions.size(); direction++) {
            dfs(grid, row + directions[direction][0], col + directions[direction][1]);
        }
    }

    int numIslands(vector<vector<char>>& grid) {
        int rows = grid.size();
        int cols = grid[0].size();
        int islands = 0;

        for (int row = 0; row < rows; row++) {
            for (int col = 0; col < cols; col++) {
                if (grid[row][col] == '1') {
                    dfs(grid, row, col);
                    islands++;
                }
            }
        }
        
        return islands;
    }
};