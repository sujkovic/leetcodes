//  First, init a matrix where water cells are -1, all else is 0
//  keep a distance variable for the current bfs radius, to set cells to
//  then, like in rotting oranges, do a bfs from each water cell,
//      look at the adjacent cells, and if any is still zero, set it to cur bfs radius
//  at the end set the water cells to zero

//  0 1 1 1 1 1 0

//  Solved in 35 min
//      Went way too slow on this and kinda overcomplicated it i feel
//      Also pretty tired tho lmao
//  Time - O(m * n)
//  Space - O(m * n)

class Solution {
public:
    vector<vector<int>> directions = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};

    bool isValid(int &row, int &col, int &rows, int &cols, vector<vector<int>> &matrix) {
        return (row >= 0 && col >= 0 && row < rows && col < cols && matrix[row][col] == 0);
    }

    vector<vector<int>> initBfs(vector<vector<int>> &isWater, queue<pair<int, int>> &q) {
        int rows = isWater.size();
        int cols = isWater[0].size();
        vector<vector<int>> matrix(rows, vector<int>(cols, 0));

        for (int i = 0; i < isWater.size(); i++) {
            for (int j = 0; j < isWater[0].size(); j++) {
                if (isWater[i][j] == 1) {
                    matrix[i][j] = -1;
                    q.push({i, j});
                }
            }
        }

        return matrix;
    }

    vector<vector<int>> bfs(vector<vector<int>> &isWater) {
        queue<pair<int, int>> q;
        vector<vector<int>> matrix = initBfs(isWater, q);
        int rows = matrix.size();
        int cols = matrix[0].size();
        int radius = 0;

        while (!q.empty()) {
            radius++;
            int qSize = q.size();
            while (qSize) {
                //  Update adjacent cells
                for (int i = 0; i < directions.size(); i++) {  
                    int row = q.front().first + directions[i][0];
                    int col = q.front().second + directions[i][1];

                    if (isValid(row, col, rows, cols, matrix)) {
                        matrix[row][col] = radius;
                        q.push({row, col});
                    }
                }

                q.pop();
                qSize--;
            }
        }

        for (int row = 0; row < rows; row++) {
            for (int col = 0; col < cols; col++) {
                if (matrix[row][col] == -1) {
                    matrix[row][col] = 0;
                }
            }
        }

        return matrix;
    }

    vector<vector<int>> highestPeak(vector<vector<int>>& isWater) {
        return bfs(isWater);
    }
};