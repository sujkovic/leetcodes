//  I instantly see this is prefix sum just from the first bullet point but ill right out brute force anyways
//  Brute force:
//      loop through nums from first element to second to last element
//          keep a running sum of the elements seen so far in this loop
//          then within that loop, have another one for all the elements after current 
//          keep a sum of that inner loop as well ^
//          for each iteration of the outer loop, compare its sum with inner loops sum, res++ if outer >= inner
//      Time - O(n^2)
//      Space - O(1)

//  Prefix sum
//  Init a prefix sum array of the running sum of nums at each index
//  Loop through nums from first element to second to last
//      if prefixSum[i] >= prefixSum[numsSize - 1] - prefixSum[i + 1]
//          res++

//  Solved in 10 min
//      Again made that mistake that calculating the prefix sum is sum[n - 1] - sum[i], NOT sum[n - 1] - sum[i + 1]
//  Time - O(n)
//  Space - O(n)
/*
class Solution {
public:
    int waysToSplitArray(vector<int>& nums) {
        vector<long long> prefixSum;
        long long curSum = 0;
        int numWays = 0;

        //  init prefixSum
        for (int i = 0; i < nums.size(); i++) {
            curSum += nums[i];
            prefixSum.push_back(curSum);
        }

        for (int i = 0; i < nums.size() - 1; i++) {
            if (prefixSum[i] >= prefixSum[nums.size() - 1] - prefixSum[i]) {
                numWays++;
            }
        }

        return numWays;
    }
};
*/

//  Looked at solutions tab for 1 second and realized you can do it without the prefixsum array

//  Solved in 2 min
//  Time - O(n)
//  Space - O(1)

class Solution {
public:
    int waysToSplitArray(vector<int>& nums) {
        long long arraySum = accumulate(nums.begin(), nums.end(), (long long)0);
        long long curSum = 0;
        int numWays = 0;

        for (int i = 0; i < nums.size() - 1; i++) {
            curSum += nums[i];

            if (curSum >= arraySum - curSum) {
                numWays++;
            }
        }

        return numWays;
    }
};