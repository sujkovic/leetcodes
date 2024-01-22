//  Make two sets
//  One set of every number from 1 to nums.size
//  Another one of all the numbers in nums
//      as youre making this one, keep checking if the cur num already exists in set
//  realized i dont need that first set oops

//  Time - O(n)
//  Space - O(n)

//  Solved in 7 minutes


class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        unordered_set<int> actualNums;
        int missingNum = -1;
        int duplicateNum = -1;

        for (int i = 0; i < nums.size(); i++) {
            if (actualNums.find(nums[i]) != actualNums.end()) {
                duplicateNum = nums[i];
            }
            actualNums.insert(nums[i]);
        }

        for (int i = 0; i < nums.size(); i++) {
            if (actualNums.find(i + 1) == actualNums.end()) {
                missingNum = i + 1;
            }
        }

        return {duplicateNum, missingNum};
    }
};