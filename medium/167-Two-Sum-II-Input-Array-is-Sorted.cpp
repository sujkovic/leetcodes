//  2 3 4      6
//  l r
//  l   r

//  2 7 11 15
//  l      r
//  l   r
//  l r

class Solution
{
public:
    vector<int> twoSum(vector<int> &numbers, int target)
    {
        int left = 0;
        int right = numbers.size() - 1;

        while (left < right)
        {
            int sum = numbers[left] + numbers[right];

            if (sum == target)
            {
                return {left + 1, right + 1};
            }
            if (sum > target)
            {
                right--;
            }
            else
            {
                left++;
            }
        }

        return {-1, -1};
    }
};