//  10 9 2 5 3 7 101 18

//       2 5 3 7 101 18

//  ok tinkered w/ some arrays, can just loop through nums
//  for each element, calculate its longest increasing subsequence
//      once we hit a number thats bigger, stop 
//  res = max(res, curTotal)
//  

//  spent 25 min on this and realized this is not going to work :D time for dp
/*
class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int res = 0;

        for (int i = 0; i < nums.size(); i++) {
            int curTotal = 1; 
            int curMax = nums[i];
            if (res > (nums.size()) - i) {
                break;
            }

            for (int j = i + 1; j < nums.size(); j++) {
                if (j == i + 1 && (nums[j] < nums[i])) {
                    break;
                }
                if (nums[j] > curMax) {
                    curTotal++;
                    curMax = nums[j];
                }
            }

            res = max(res, curTotal);
        }

        return res;
    }
};
*/

//  Top down DP approach

//  At any number in the array, we can make a decision to jump to any number that comes after it in the array
//                      0               1           0           3           2           3
//       /    /    /        \   \
//      1    X    3         2   3
//  /  /  \
//  3  2  3 
//  |  |   
//  X  3 

//  as for memo, lets say in the above example, we go down the 0 1 2 3 path
//      at the end of it, we are at index 5 in the array
//          the LIS at index 5 is 1
//      if we backtrack one, the LIS at index 4 is 2
//      and so on, so cache is index : LIS

//  Time - O(n^2)
//    The dfs tree for each element is at most size n, and we need to make one for each element, so n * n
//  Space - O(n)
//      cache the LIS for each value in array of size n

//  Solved in around 30 min
/*
class Solution {
public:
    int dfs(vector<int>& nums, vector<int> &memo, int index, int prev) {
        if (nums[index] <= prev) {
            return 0;
        }
        if (memo[index] != 0) {
            return memo[index];
        }
        int res = 1;

        for (int i = index + 1; i < nums.size(); i++) {
            res = max(res, 1 + dfs(nums, memo, i, nums[index]));
        }
        memo[index] = res;
        return res;
    }
    int lengthOfLIS(vector<int>& nums) {
        int len = nums.size();
        int res = 0;
        vector<int> memo(len, 0);
        for (int i = 0; i < nums.size(); i++) {
            res = max(res, dfs(nums, memo, i, INT_MIN));
        }
        return res;
    }
};
*/

//  Bottom up DP
//  since we're caching the LIS subproblem at each index, start at end of array and work back
//  looping backwards, for each number, i, in the array
//      check all numbers after it, j
//      if j > i
//          memo[curIIndex] = max(memo[curIIndex], 1 + memo[curJIndex])
//  return biggest number in array

//  Time - O(n^2)
//      double for loop looping thru input size n
//  Size - O(n)
//      memo size n

//  Solved in around 10 minutes a few hours after watching the neetcode vid

class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int res = 0;
        int len = nums.size();
        vector<int> memo(len, 1);

        for (int i = len - 1; i >= 0; i--) {
            for (int j = i + 1; j < len; j++) {
                if (nums[j] > nums[i]) {
                    memo[i] = max(memo[i], 1 + memo[j]);
                }
            }
            res = max(res, memo[i]);
        }

        return res;
    }
};
