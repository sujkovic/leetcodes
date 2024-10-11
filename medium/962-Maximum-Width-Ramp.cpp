//  brute force, double for loop
//      for every nums[i]
//          find the biggest nums[j] that comes after it
//              update max

//  Solved in 4 min, tle

//  6 0 8 2 1 5
//  8 8 8 5 5 5
//  l r           2
//  l   r         3
//  l     r       3
//    l   r       3
//    l     r     4
//    l       r   5

//  Solved in 27 min
//      accidentally had it as prefixMaximums[left] instead of right lmao

class Solution
{
public:
    int maxWidthRamp(vector<int> &nums)
    {
        int curPrefixMax = INT_MIN;
        vector<int> prefixMaximums(nums.size(), 0);

        for (int i = nums.size() - 1; i >= 0; i--)
        {
            curPrefixMax = max(curPrefixMax, nums[i]);
            prefixMaximums[i] = curPrefixMax;
        }

        int maxRamp = 0;
        int left = 0;
        int right = 1;

        while (right < nums.size())
        {
            if (nums[left] <= prefixMaximums[right])
            {
                maxRamp = max(maxRamp, right - left);
                right++;
            }
            else
            {
                left++;
            }
        }

        return maxRamp;
    }
};