//  my first thought is make another graph, where we store the following information in each cell:
//      basically if you follow that cell to its end, the distance from the end of that cells path
//       and the bottom right of the matrix
//  so example 1 would look like
//   3  3  3  3
//  -1 -1 -1 -1
//   1  1  1  1
//  -1 -1 -1 -1
//  so then you could make a decision on where to go based on if following the path is better, or 
//  if just being greedy and changing your current arrow to another arrow adjacent to you is better
//  mm but the -1 isnt really correct need some sort of way to calculate the distance for those
//  nah this is ggs

//  Watched neetcode vid yesterday, can be solved with either dijkstras or 0/1 bfs
//  I'll watch the dijkstras vid on a similar problem later going to solve bfs for now
//  The idea is, start a bfs from the top left of the matrix
//  Then when you add to the queue, you want to do it in a specific matter -
//      if the cell you want to add is in the direction of the current arrow - 
//          add it to the left side of the queue, and add 0 to the cost
//      if its not in the direction of the current arrow
//          add it to the right side of the queue, and add 1 to the cost
//  this way for each bfs iteration, the queue is in "sorted" order, meaning 
//  we look at the lowest costs first 
//  and once we hit bottom right, return the cost attached to it
//  queue will also have to hold a 3 pair i guess vector


//  Compiled on first try at 27 min but failed case 48/69
//  1 right 2 left 3 down 4 up
//  1 3 3 3
//  2 2 1 2
//  4 3 3 4
//  3 2 2 3
//  3 2 1 3
//  4 1 4 3
//  3 3 1 2

//  Spent a pretty long time on this attempt idek maybe hour or two

/*
struct Cell {
    int row;
    int col;
    int cost;
    Cell(int row, int col, int cost) : row(row), col(col), cost(cost) {}
};

class Solution {
public:
    int bfs(vector<vector<int>>& grid) {
        int rows = grid.size();
        int cols = grid[0].size();
        deque<Cell> q;
        vector<vector<int>> visited(rows, vector<int>(cols, INT_MAX));
        q.push_back(Cell(0, 0, 0));
        visited[0][0] = 0;

        while (!q.empty()) {
            int qSize = q.size();

            while (qSize) {
                //  Look at the left of the deque
                Cell cell = q.back();
                visited[cell.row][cell.col] = cell.cost;
                q.pop_back();

                //  If we hit bottom right, return
                if (cell.row == rows - 1 && cell.col == cols - 1) {
                    return cell.cost;
                }

                //  Now look at the adjacent cells and add to queue if in bounds/not seen
                //  down
                if (cell.row + 1 < rows) {
                    if (grid[cell.row][cell.col] == 3 && cell.cost < visited[cell.row + 1][cell.col]) {
                        q.push_back(Cell(cell.row + 1, cell.col, cell.cost));
                    }
                    else {
                        if (cell.cost + 1 < visited[cell.row + 1][cell.col]) {
                            q.push_front(Cell(cell.row + 1, cell.col, cell.cost + 1));
                        }
                    }
                }
                //  left
                if (cell.col - 1 >= 0) {
                    if (grid[cell.row][cell.col] == 2 && cell.cost < visited[cell.row][cell.col - 1]) {
                        q.push_back(Cell(cell.row, cell.col - 1, cell.cost));
                    }
                    else {
                        if (cell.cost + 1 < visited[cell.row][cell.col - 1])
                        q.push_front(Cell(cell.row, cell.col - 1, cell.cost + 1));
                    }
                }
                //  right
                if (cell.col + 1 < cols) {
                    if (grid[cell.row][cell.col] == 1 && cell.cost < visited[cell.row][cell.col + 1]) {
                        q.push_back(Cell(cell.row, cell.col + 1, cell.cost));
                    }
                    else {
                        if (cell.cost < visited[cell.row][cell.col + 1]) {
                            q.push_front(Cell(cell.row, cell.col + 1, cell.cost + 1));
                        }
                    }
                }

                qSize--;
            }
        }

        return -1;
    }
    int minCost(vector<vector<int>>& grid) {
        return bfs(grid);
    }
};
*/

//  Completely redo this code later, using mincost array instead of map, and deque of just pairs
//  front = 0, back = 1


//  Solved in 30 min
//      the problem the entire time was that i didnt include the up case cause i thought it wouldnt matter........
//      so my above solution wouldve literally worked, not in its current state cause i broke it trying to fix it but from before
//      test case 48 was i guess somehow optimal by going up
//  Time - O(m * n)
//  Space - O(m * n)

class Solution {
public:
    vector<vector<int>> directions = {{1, 0}, {0, 1}, {0, -1}};

    int bfs(vector<vector<int>> &grid) {
        int rows = grid.size();
        int cols = grid[0].size();

        vector<vector<int>> costs(rows, vector<int>(cols, INT_MAX));
        deque<pair<int, int>> q;
        q.push_front({0, 0});
        costs[0][0] = 0;

        while (!q.empty()) {
            int row = q.front().first;
            int col = q.front().second;
            int curCost = costs[row][col];
            q.pop_front();

            // if we hit bottom right, return
            if (row == rows - 1 && col == cols - 1) {
                return costs[row][col];
            }

            //  move down
            if (row + 1 < rows) {
                if (grid[row][col] == 3 && curCost < costs[row + 1][col]) {
                    costs[row + 1][col] = curCost;
                    q.push_front({row + 1, col});
                }
                if (grid[row][col] != 3 && curCost + 1 < costs[row + 1][col]) {
                    costs[row + 1][col] = curCost + 1;
                    q.push_back({row + 1, col});
                }
            }

            //  move up
            if (row - 1 >= 0) {
                if (grid[row][col] == 4 && curCost < costs[row - 1][col]) {
                    costs[row - 1][col] = curCost;
                    q.push_front({row - 1, col});
                }
                if (grid[row][col] != 4 && curCost + 1 < costs[row - 1][col]) {
                    costs[row - 1][col] = curCost + 1;
                    q.push_back({row - 1, col});
                }
            }

            //  move left
            if (col - 1 >= 0) {
                if (grid[row][col] == 2 && curCost < costs[row][col - 1]) {
                    costs[row][col - 1] = curCost;
                    q.push_front({row, col - 1});
                }
                if (grid[row][col] != 2 && curCost + 1 < costs[row][col - 1]) {
                    costs[row][col - 1] = curCost + 1;
                    q.push_back({row, col - 1});
                }
            }

            //  move right
            if (col + 1 < cols) {
                if (grid[row][col] == 1 && curCost < costs[row][col + 1]) {
                    costs[row][col + 1] = curCost;
                    q.push_front({row, col + 1});
                }
                if (grid[row][col] != 1 && curCost + 1 < costs[row][col + 1]) {
                    costs[row][col + 1] = curCost + 1;
                    q.push_back({row, col + 1});
                }
            }
        }

        return -1;
    }

    int minCost(vector<vector<int>>& grid) {
        return bfs(grid);
    }
};
