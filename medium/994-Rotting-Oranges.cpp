//  Loop through the grid initially to find all rotting oranges
//      add them all to a queue<pair<int, int>> (where pair is the cell)
//      and also check if there are any good ones that are alone, if yes return -1
//  Then, while queue isnt empty
//      add any adj good oranges to the queue and pop the cur, setting it to 0
//  keep track of # of queue iterations

//  33 min

class Solution
{
public:
    int bfs(vector<vector<int>> &grid, queue<pair<int, int>> rottenQueue)
    {
        int minutes = 0;
        while (!rottenQueue.empty())
        {
            int queueSize = rottenQueue.size();
            while (queueSize > 0)
            {
                int i = rottenQueue.front().first;
                int j = rottenQueue.front().second;

                if (i > 0 && grid[i - 1][j] == 1)
                {
                    grid[i - 1][j] = 2;
                    rottenQueue.push({i - 1, j});
                }
                if (i < grid.size() - 1 && grid[i + 1][j] == 1)
                {
                    grid[i + 1][j] = 2;
                    rottenQueue.push({i + 1, j});
                }
                if (j > 0 && grid[i][j - 1] == 1)
                {
                    grid[i][j - 1] = 2;
                    rottenQueue.push({i, j - 1});
                }
                if (j < grid[0].size() - 1 && grid[i][j + 1] == 1)
                {
                    grid[i][j + 1] = 2;
                    rottenQueue.push({i, j + 1});
                }

                grid[i][j] = 0;
                rottenQueue.pop();
                queueSize--;
            }

            minutes++;
        }

        return minutes - 1;
    }
    int orangesRotting(vector<vector<int>> &grid)
    {
        queue<pair<int, int>> rottenQueue;
        bool isGridEmpty = true;
        for (int i = 0; i < grid.size(); i++)
        {
            for (int j = 0; j < grid[0].size(); j++)
            {
                if (grid[i][j] == 2)
                {
                    isGridEmpty = false;
                    rottenQueue.push({i, j});
                }
                if (grid[i][j] == 1)
                {
                    isGridEmpty = false;
                }
            }
        }

        if (isGridEmpty)
        {
            return 0;
        }

        int result = bfs(grid, rottenQueue);

        for (int i = 0; i < grid.size(); i++)
        {
            for (int j = 0; j < grid[0].size(); j++)
            {
                if (grid[i][j] == 1)
                {
                    return -1;
                }
            }
        }

        return result;
    }
};