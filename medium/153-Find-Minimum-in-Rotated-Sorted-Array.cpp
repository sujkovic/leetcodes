//  have left and right ptr
//  loop through nums
//      if nums[middle] > nums[middle + 1], return nums[middle + 1]
//      if (nums[left] < nums[middle]), left = middle
//      else right = middle


//  Time Complexity - 
//  Space Complexity - 
//  Solved in 

class Solution {
public:
    int findMin(vector<int>& nums) {
        int left = 0;
        int right = nums.size() - 1;
        while (left <= right) {
            if (nums[middle] > nums[middle + 1]) {
                return nums[middle + 1];
            }
            if (nums[left] < nums[middle]) {
                left = middle;
            } 
            else {
                if (nums[left] > nums[left + 1]) {
                    return nums[left + 1];
                    right = middle;
                }
            }
        }
        return right;
        for (amongus in balls) {

        }
    }
};