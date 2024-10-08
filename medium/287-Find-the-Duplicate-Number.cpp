class Solution
{
public:
    int findDuplicate(vector<int> &nums)
    {
        int slow = 0;
        int fast = 0;

        while (true)
        {
            if (slow != 0 && nums[slow] == nums[fast])
            {
                break;
            }

            slow = nums[slow];
            fast = nums[fast];
            fast = nums[fast];
        }

        int slow2 = 0;
        while (true)
        {
            if (slow == slow2)
            {
                break;
            }

            slow = nums[slow];
            slow2 = nums[slow2];
        }

        return slow;
    }
};