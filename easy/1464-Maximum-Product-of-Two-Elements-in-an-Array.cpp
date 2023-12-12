//  solved in 4 min bruh what are these daily problems

class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int maxOne = 0;
        int maxTwo = 0;
        int maxOneIndex = 0;

        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] >= maxOne) {
                maxOne = nums[i];
                maxOneIndex = i;
            }
        }

        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] >= maxTwo && i != maxOneIndex) {
                maxTwo = nums[i];
            }
        }

        return (maxOne - 1) * (maxTwo - 1);
    }
};