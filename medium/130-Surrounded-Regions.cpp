//  i think you would need to do an original pass through to find all the regions
//  so for each cell in the matrix, if its a 'O', do a dfs from it 
//      set all the O's in that region to S
//  Then, just loop through the matrix and set all 'S' to 'X'
//  This way we preserve all the edge O's
//  
//  I'm realizing we also need to check if a region touches the border ever
//  so i think we would need to do 2 separate dfs's
//  bool checkIfEdgeRegion
//      if out of bounds
//          return false
//      if edge and O
//          return true
//      dfs neighbors, if any true return true
//  bool setRegion(region type)
//      if out of bounds or cur cell not an O
//          return
//      set cur cell to region type
//      dfs neighbors

//  so loop thru matrix
//      if checkifEdgeRegion is true
//          setregion accordingly

//  then just go through the matrix setting r's to x and e's to o

//  ^ 10 min
/*
class Solution {
public:
    vector<vector<int>> directions = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};

    bool getIsEdgeRegion(vector<vector<char>> &board, int row, int col) {
        cout << row << " " << col << endl;
        if (row < 0 || col < 0 || row >= board.size() || col >= board[0].size() 
            || board[row][col] == 'X') {
                return false;
            }
        if ((row == 0 || col == 0 || row == board.size() - 1 || col == board.size() - 1) 
            && board[row][col] == 'O') {
                return true;
            }

        bool res = false;
        for (int i = 0; i < 4; i++) {
            res = res || getIsEdgeRegion(board, row + directions[i][0], col + directions[i][1]);
        }
        
        return res;
    }

    void setRegion(vector<vector<char>> &board, int row, int col, char regionType) {
        if (row < 0 || col < 0 || row >= board.size() || col >= board[0].size() 
            || board[row][col] != 'O') {
                return;
            }
        
        board[row][col] = regionType;
        for (int i = 0; i < 4; i++) {
            setRegion(board, row + directions[i][0], col + directions[i][1], regionType);
        }
    }

    void solve(vector<vector<char>>& board) {
        int rows = board.size();
        int cols = board[0].size();

        for (int row = 0; row < rows; row++) {
            for (int col = 0; col < cols; col++) {
                if (board[row][col] == 'O') {
                    bool isEdgeRegion = getIsEdgeRegion(board, row, col);
                    if (isEdgeRegion) {
                        setRegion(board, row, col, 'E');
                    }
                    else {
                        setRegion(board, row, col, 'R');
                    }
                }
            }
        }

        for (int row = 0; row < rows; row++) {
            for (int col = 0; col < cols; col++) {
                if (board[row][col] == 'E') {
                    board[row][col] = 'O';
                }
                if (board[row][col] == 'R') {
                    board[row][col] = 'R';
                }
            }
        }
    }
};
*/
//  "finished" in 25 min just to realize the check if function infinte loops cuz no visit check
//  nvm i can just ditch the check function and handle the check in a separate loop

//  Solved in 43 min
//  Time - O(m * n)
//  Space - O(m * n)
//      ^ i think worst case call stack could be size m*n but not 100% sure on this


class Solution {
public:
    vector<vector<int>> directions = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};

    void setRegion(vector<vector<char>> &board, int row, int col, char regionType) {
        if (row < 0 || col < 0 || row >= board.size() || col >= board[0].size() 
            || board[row][col] != 'O') {
                return;
            }
        
        board[row][col] = regionType;
        for (int i = 0; i < 4; i++) {
            setRegion(board, row + directions[i][0], col + directions[i][1], regionType);
        }
    }

    void solve(vector<vector<char>>& board) {
        int rows = board.size();
        int cols = board[0].size();

        //  First, set edge regions
        for (int row = 0; row < rows; row++) {  //  left and right
            if (board[row][0] == 'O') {
                setRegion(board, row, 0, 'E');
            }
            if (board[row][cols - 1] == 'O') {
                setRegion(board, row, cols - 1, 'E');
            }
        }

        for (int col = 0; col < cols; col++) {  //  top and bottom
            if (board[0][col] == 'O') {
                setRegion(board, 0, col, 'E');
            }
            if (board[rows - 1][col] == 'O') {
                setRegion(board, rows - 1, col, 'E');
            }
        }

        //  Then, set surrounded regions
        for (int row = 1; row < rows - 1; row++) {
            for (int col = 1; col < cols - 1; col++) {
                if (board[row][col] == 'O') {
                    setRegion(board, row, col, 'R');
                }
            }
        }

        //  Finally, update the result to keep only edge regions as O, and the rest as X
        for (int row = 0; row < rows; row++) {
            for (int col = 0; col < cols; col++) {
                if (board[row][col] == 'E') {
                    board[row][col] = 'O';
                }
                if (board[row][col] == 'R') {
                    board[row][col] = 'X';
                }
            }
        }
    }
};
