//  keep left and right ptr
//  while left <= right
//      if target == nums[middle], return middle
//      if target < nums[middle], right = middle - 1
//      if target > nums[middle], left = middle + 1

//  Time Complexity - O(logn) - we keep dividing array of size n in half
//  Space Complexity - O(1) - no extra space used except like 3 int variables
//  Solved in 12 minutes

class Solution {
public:
    int search(vector<int>& nums, int target) {
        int left = 0;
        int right = nums.size() - 1;

        while (left <= right) {
            int middle = (left + right) / 2;

            if (target == nums[middle]) {
                return middle;
            }

            else if (target < nums[middle]) {
                right = middle - 1;
            }

            else {
                left = middle + 1;
            }
        }
        
        return -1;
    }
};