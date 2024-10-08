class Solution
{
public:
    int maxArea(vector<int> &height)
    {
        int maxContainer = 0;
        int left = 0;
        int right = height.size() - 1;

        while (left < right)
        {
            int curContainer = (right - left) * min(height[left], height[right]);
            maxContainer = max(maxContainer, curContainer);

            if (height[left] > height[right])
            {
                right--;
            }
            else
            {
                left++;
            }
        }

        return maxContainer;
    }
};