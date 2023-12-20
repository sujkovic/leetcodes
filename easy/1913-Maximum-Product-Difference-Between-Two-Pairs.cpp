//  Find 2 max nums and 2 min nums
//  return max * max - min * min

//  Time O(n), Space O(1)

//  Solved in 10 min

//  Checked solutions, can do in one loop by just checking 
//  if (nums[i] > maxOne)
//      // logic here
//  else if (nums[i] > maxTwo)
//      //  logic here
//  and then same for min

class Solution {
public:
    int maxProductDifference(vector<int>& nums) {
        int maxOne = 0;
        int maxTwo = 0;
        int minOne = INT_MAX;
        int minTwo = INT_MAX;
        int maxOneIndex = 0;
        int minOneIndex = 0;
        for (int i = 0; i < nums.size(); i++) {
            if (maxOne < nums[i]) {
                maxOne = nums[i];
                maxOneIndex = i;
            }
        }
        for (int i = 0; i < nums.size(); i++) {
            if (maxTwo < nums[i] && i != maxOneIndex) {
                maxTwo = nums[i];
            }
        }
        for (int i = 0; i < nums.size(); i++) {
            if (minOne > nums[i]) {
                minOne = nums[i];
                minOneIndex = i;
            }
        }
        for (int i = 0; i < nums.size(); i++) {
            if (minTwo > nums[i] && minOneIndex != i) {
                minTwo = nums[i];
            }
        }
        return (maxOne * maxTwo) - (minOne * minTwo);
    }
};