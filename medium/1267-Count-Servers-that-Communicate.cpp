//  im gonna split the problem into just get all the rows / columns that have 2+ servers
//  then go through those columns, adding the indices of all servers to a set
//  then return the size of the set

//  Solved in 12 min
//      only error was i was at the end doing grid[i][j] instead of grid[serverRows[i]][j] and same for cols
//  Time - O(m * n * log(max(n, m)))
//      since ordered sets are logarithmic lookup/insert
//  Space - O(n * m)

/*
class Solution {
public:
    int countServers(vector<vector<int>>& grid) {
        vector<int> serverRows;
        vector<int> serverCols;
        set<pair<int, int>> serverSet;

        //  check rows
        for (int i = 0; i < grid.size(); i++) {
            int numServers = 0;

            for (int j = 0; j < grid[0].size(); j++) {
                numServers += grid[i][j];
            }

            if (numServers >= 2) {
                serverRows.push_back(i);
            }
        }

        //  check cols
        for (int i = 0; i < grid[0].size(); i++) {
            int numServers = 0;

            for (int j = 0; j < grid.size(); j++) {
                numServers += grid[j][i];
            }

            if (numServers >= 2) {
                serverCols.push_back(i);
            }
        }

        //  build set
        for (int i = 0; i < serverRows.size(); i++) {
            for (int j = 0; j < grid[0].size(); j++) {
                if (grid[serverRows[i]][j] == 1) {
                    serverSet.insert({serverRows[i], j});
                }
            }
        }

        for (int i = 0; i < serverCols.size(); i++) {
            for (int j = 0; j < grid.size(); j++) {
                if (grid[j][serverCols[i]] == 1) {
                    serverSet.insert({j, serverCols[i]});
                }
            }
        }

        return serverSet.size();
    }
};
*/

//  + 5 min 
//  Time - O(m * n)
//  Basically treated the grid as a 1d array and used that as the index for the set to make it O(1)
//  since c++ unordered set doesnt support pairs

class Solution {
public:
    int countServers(vector<vector<int>>& grid) {
        vector<int> serverRows;
        vector<int> serverCols;
        unordered_set<int> serverSet;

        //  check rows
        for (int i = 0; i < grid.size(); i++) {
            int numServers = 0;

            for (int j = 0; j < grid[0].size(); j++) {
                numServers += grid[i][j];
            }

            if (numServers >= 2) {
                serverRows.push_back(i);
            }
        }

        //  check cols
        for (int i = 0; i < grid[0].size(); i++) {
            int numServers = 0;

            for (int j = 0; j < grid.size(); j++) {
                numServers += grid[j][i];
            }

            if (numServers >= 2) {
                serverCols.push_back(i);
            }
        }

        //  build set
        for (int i = 0; i < serverRows.size(); i++) {
            for (int j = 0; j < grid[0].size(); j++) {
                if (grid[serverRows[i]][j] == 1) {
                    int customIndex = (serverRows[i] * grid[0].size()) + j;
                    serverSet.insert(customIndex);
                }
            }
        }

        for (int i = 0; i < serverCols.size(); i++) {
            for (int j = 0; j < grid.size(); j++) {
                if (grid[j][serverCols[i]] == 1) {
                    int customIndex = (j * grid[0].size()) + serverCols[i];
                    serverSet.insert(customIndex);
                }
            }
        }

        return serverSet.size();
    }
};