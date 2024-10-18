//                                                   []
//                                      /                           \
//                           [1]                                              []
//                      /           \                                   /           \
//            [1, 2]                     [1]                       [2]                 []
//      /           \                   /    \                  /     \              /    \
//  [1, 2, 3]        [1, 2]        [1, 3]     [1]           [2, 3]     [2]         [3]      []

//  basically do a depth first search, going down the nums, and at any point you can either include
//  the current num or not include it
//  once youve gone through the entire nums array, you have a subset and you add to the result

//  Solved in 9 minutes

class Solution
{
public:
    void dfs(vector<int> &nums, vector<vector<int>> &res, int index, vector<int> curSubset)
    {
        if (index == nums.size())
        {
            res.push_back(curSubset);
            return;
        }

        dfs(nums, res, index + 1, curSubset); //  dont include
        curSubset.push_back(nums[index]);
        dfs(nums, res, index + 1, curSubset); //  include
    }
    vector<vector<int>> subsets(vector<int> &nums)
    {
        vector<vector<int>> res;
        dfs(nums, res, 0, {});
        return res;
    }
};