//  Create new vector for unique vals, call it vec
//  push nums[0] to vec
//  loop through nums, starting at index 1
//      if nums[i] != nums[i - 1], push it to vec, else continue
//  set the first k values of nums to the values of vec from 0 to vec.size()
//  return vec.size()

//  let n = nums.size(), k = # unique vals
//  Time Complexity - O(n), looping through array of size n and array of size k
//  Space Complexity - O(n), worst case every element is unique
//  Solved in 7 minutes

//  update you can optimize space complexity to O(1) by using two pointer

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        vector<int> vec;
        for (int i = 0; i < nums.size() - 1; i++) {
            if (nums[i] != nums[i + 1]) {
                vec.push_back(nums[i]);
            }
        }
        for (int i = 0; i < vec.size(); i++) {
            nums[i] = vec[i];
        }
        return vec.size();
    }
};