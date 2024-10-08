//  -4 -1 -1 0 1 2
//  -4
//

class Solution
{
public:
    vector<vector<int>> threeSum(vector<int> &nums)
    {
        vector<vector<int>> res;
        sort(nums.begin(), nums.end());

        for (int i = 0; i < nums.size(); i++)
        {
            if (i > 0 && nums[i] == nums[i - 1])
            {
                continue;
            }
            int left = i + 1;
            int right = nums.size() - 1;
            while (left < right)
            {
                int sum = nums[i] + nums[left] + nums[right];
                if (sum == 0)
                {
                    res.push_back({nums[i], nums[left], nums[right]});

                    left++;
                    while (left != nums.size() - 1 && nums[left] == nums[left - 1])
                    {
                        left++;
                    }
                }
                if (sum > 0)
                {
                    right--;
                }
                if (sum < 0)
                {
                    left++;
                }
            }
        }

        return res;
    }
};