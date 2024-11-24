//  definitely going to be a bfs since we're looking for shortest path
//  can either bfs from each empty cell and look for the nearest gate
//      or bfs from each gate, filling in empty cells and updating their mins
//  either way we'll need to keep track of visited cells within each bfs call
//  ok i think from the gates would be more efficient, since if you reach a cell
//  where its min value is less than our current "depth" in the bfs, just dont explore it
//  i think this might bring the time comp down from m^2 * n^2 to m * n

//  first, get a list of all the gate indices
//  then, for each gate, do a bfs from it 

//  bfs 
//      queue<pair<int, int>>    (row, col)
//      visited set
//      int depth
//      push gate to queue
//      while queue not empty
//          int queueSize
//          while queueSize
//              add cur cell to visited
//              for direction in directions
//                  row, col = queue.front + direction
//                  if in bounds and not a wall/gate and not visited
//                      set its value to depth and add it to queue
//              pop front of queue
//              queueSize--
//         depth++

//  Solved in 38 min and TLE rip
//      Had like 3 typos but other than that compiled perfectly
//  I think this is O(m^2 & n^2) time
//  O(m * n) space

//  Ok checked the neetcode video, all you have to do to get O(mn) time 
//  is before you start the bfs, add ALL gates to the queue, so that 
//  we are simultaneously doing a bfs from each gate 
//  and this way if we encounter a gate thats already been updated, skip it
//  also this way we dont even need visited

//  + 4 min for the optimization
//  Time - O(m * n)
//  Space - O(m * n)   - max queue size

class Solution {
public:
    vector<vector<int>> directions = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};

    bool isValidCell(vector<vector<int>> &rooms, int &row, int &col, int rows, int cols) {
        return (row >= 0 && col >= 0 && row < rows && col < cols && rooms[row][col] > 0 && rooms[row][col] == INT_MAX);
    }

    void bfs(vector<vector<int>> &rooms, vector<vector<int>> gates) {
        queue<vector<int>> queue;
        int depth = 1;

        for (int gate = 0; gate < gates.size(); gate++) {
            queue.push({gates[gate][0], gates[gate][1]});
        }

        while (!queue.empty()) {
            int queueSize = queue.size();

            while (queueSize) {

                for (int dir = 0; dir < directions.size(); dir++) {
                    int row = queue.front()[0] + directions[dir][0];
                    int col = queue.front()[1] + directions[dir][1];

                    if (isValidCell(rooms, row, col, rooms.size(), rooms[0].size())) {
                        rooms[row][col] = depth;
                        queue.push({row, col});
                        
                    }
                }

                queue.pop();
                queueSize--;
            }

            depth++;
        }
    }

    void wallsAndGates(vector<vector<int>>& rooms) {
        vector<vector<int>> gates;

        //  Get a list of all gates indices
        for (int i = 0; i < rooms.size(); i++) {
            for (int j = 0; j < rooms[0].size(); j++) {
                if (rooms[i][j] == 0) {
                    gates.push_back({i, j});
                }
            }
        }

        //  Perform a BFS from each gate to update min dists to rooms
        bfs(rooms, gates);
    }
};