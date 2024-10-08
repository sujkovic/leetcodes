class Solution
{
public:
    int maxSubArray(vector<int> &nums)
    {
        int curSum = nums[0];
        int bestSum = nums[0];

        for (int i = 1; i < nums.size(); i++)
        {
            if (nums[i] > curSum && curSum < 0)
            {
                curSum = nums[i];
            }
            else
            {
                curSum += nums[i];
            }
            bestSum = max(bestSum, curSum);
        }

        return bestSum;
    }
};