//                                        []
//              [1]                       [2]                      [3]
//      [1, 2]       [1, 3]        [2, 1]       [2, 3]      [3, 1]       [3, 2]
//    [1, 2, 3]     [1, 3, 2]   [2, 1, 3]      [2, 3, 1]   [3, 1, 2]   [3, 2, 1]

//  dfs - at each position, the path you can go down is any number not visited yet
//  so will probaly need a visited set (can just use array here)

//  Solved in 10 minutes

class Solution
{
public:
    void dfs(vector<int> &nums, vector<vector<int>> &res, vector<bool> visited, vector<int> curPath)
    {
        if (curPath.size() == nums.size())
        {
            res.push_back(curPath);
            return;
        }

        for (int i = 0; i < nums.size(); i++)
        {
            if (!visited[i])
            {
                visited[i] = true;
                curPath.push_back(nums[i]);
                dfs(nums, res, visited, curPath);
                visited[i] = false;
                curPath.pop_back();
            }
        }
    }
    vector<vector<int>> permute(vector<int> &nums)
    {
        vector<vector<int>> res;
        vector<bool> visited(nums.size(), false);
        dfs(nums, res, visited, {});

        return res;
    }
};