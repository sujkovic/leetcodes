//  3, 1
//  11 || 01 = 11
//  3, 2, 1, 5
//  011 || 010 || 001 || 101 = 111
//  so basically just or the entire input array to get the max
//  then just generate every possible subset, checking to see if its or is the max  and its not the empty set

//                          []
//              [3]                     []
//      [3, 1]       [3]         [1]           []

//  Solved in 11 min

class Solution
{
public:
    int calculateMaxBitwiseOr(vector<int> &nums)
    {
        int res = 0;
        for (int i = 0; i < nums.size(); i++)
        {
            res = res | nums[i];
        }

        return res;
    }

    int dfs(vector<int> &nums, int &maxBitwiseOr, int index, int curBitwiseOr)
    {
        if (index == nums.size())
        {
            if (curBitwiseOr == maxBitwiseOr)
            {
                return 1;
            }
            return 0;
        }

        int dontInclude = dfs(nums, maxBitwiseOr, index + 1, curBitwiseOr);
        curBitwiseOr = curBitwiseOr | nums[index];
        int include = dfs(nums, maxBitwiseOr, index + 1, curBitwiseOr);

        return include + dontInclude;
    }

    int countMaxOrSubsets(vector<int> &nums)
    {
        int maxBitwiseOr = calculateMaxBitwiseOr(nums);
        return dfs(nums, maxBitwiseOr, 0, 0);
    }
};