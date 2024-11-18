//  Solved September 2023

//  Recursion

//  at any point, can either rob the cur house, then jump 2 forward, or dont rob the cur house, and consider the next house
//  want to return the max of those two options
//  To memoize, make a vec of nums.size, caching the best at each index

//  Time - O(n)
//  Space - O(n)

//  Solved in 6 minutes (4 min + 2 min memoizing)
/*
class Solution {
public:
    int dfs(vector<int> &nums, int index, vector<int> &memo) {
        if (index >= nums.size()) {
            return 0;
        }
        if (memo[index] != -1) {
            return memo[index];
        }

        int jumpOne = dfs(nums, index + 1, memo);
        int jumpTwo = dfs(nums, index + 2, memo) + nums[index];

        memo[index] = max(jumpOne, jumpTwo);
        return memo[index];
    }
    int rob(vector<int>& nums) {
        int len = nums.size();
        vector<int> memo(len, -1);
        return dfs(nums, 0, memo);
    }
};
*/

//  Dynamic Programming

//  Based on the recursive function, at any point, the result is the max of memo[i - 1], memo[i - 2] + nums[i]
//  so just loop thru nums to build this vec
//  then optimize later for space since you only need to keep track of the previous two

//  Time - O(n)
//  Space - O(n)

//  Solved in 6 minutes. Forgot that you also need to update the prev in memo in case you do multiple skips in a row 
/*
class Solution {
public:
    int rob(vector<int>& nums) {
        if (nums.size() == 1) {
            return nums[0];
        }
        if (nums.size() == 2) {
            return max(nums[0], nums[1]);
        }
        int len = nums.size();
        vector<int> memo(len, 0);
        memo[0] = nums[0];
        memo[1] = nums[1];

        for (int i = 2; i < nums.size(); i++) {
            memo[i] = max(memo[i - 1], memo[i - 2] + nums[i]);
            memo[i - 1] = max(memo[i - 1], memo[i - 2]);
        }

        return memo[len - 1];
    }
};
*/

//  Now to optimize space, we see we're only ever doing computation with memo[i - 1] and memo[i - 2], so just make two variables
//  backOne and backTwo

//    V
//  2 1 1 2
//  backOne = 1
//  backTwo = 2
//      V
//  2 1 1 2
//  backOne = max(i - 1, i - 2 + curNum) = max(1, 2 + 1) = 3
//  backTwo = max(i - 1, i - 2) max(1, 2) = 2

//  Time - O(n)
//  Space - O(1)

//  Solved in 6 minutse
/*
class Solution {
public:
    int rob(vector<int>& nums) {
        if (nums.size() == 1) {
            return nums[0];
        }
        if (nums.size() == 2) {
            return max(nums[0], nums[1]);
        }
        int backTwo = nums[0];
        int backOne = nums[1];

        for (int i = 2; i < nums.size(); i++) {
            int temp = backOne;
            backOne = max(backOne, backTwo + nums[i]);
            backTwo = max(backTwo, temp);
        }

        return backOne;
    }
};
*/


//  Solved November 2024

//  2 7 9 3 1
//  10 1 1 10 1
//  at each point we can either rob the current house and i += 2 or skip it and i += 1

//                     2
//   rob 2, i += 2        dont rob 2, i+= 1

//  Solved in 14min, TLE
//  Should be O(n^2) time and O(n) space

/*
class Solution {
public:
    int dfs(vector<int> &nums, int index) {
        if (index >= nums.size()) {
            return 0;
        }

        int include = dfs(nums, index + 2) + nums[index];
        int dontInclude = dfs(nums, index + 1);
        return max(include, dontInclude);
    }
    int rob(vector<int>& nums) {
        return dfs(nums, 0);
    }
};
*/

//  Optimize with memoization
//  Once we get the result of the dfs call of a certain index, we can just save it 

//  Solved in 3 min
//  O(n) time and space

/*
class Solution {
public:
    int dfs(vector<int> &nums, vector<int> &memo, int index) {
        if (index >= nums.size()) {
            return 0;
        }
        if (memo[index] != -1) {
            return memo[index];
        }

        int include = dfs(nums, memo, index + 2) + nums[index];
        int dontInclude = dfs(nums, memo, index + 1);
        memo[index] = max(include, dontInclude);
        return memo[index];
    }
    int rob(vector<int>& nums) {
        vector<int> memo(nums.size() + 2, -1);
        return dfs(nums, memo, 0);
    }
};
*/


//  Iterative approach
//  looking at recursive solution, the recurrence relation seems to be 
//  res[i] = max(res[i - 1], res[i - 2] + nums[i])

//  Solved in 9 min
//      half of that was realizing i had to init dp[1] to the max of first 2, not just the 2nd
//      also forgor edge case of nums size = 1
//  Time - O(n)
//  Space - O(n)

/*
class Solution {
public:
    int rob(vector<int>& nums) {
        if (nums.size() == 1) {
            return nums[0];
        }
        if (nums.size() == 2) {
            return max(nums[0], nums[1]);
        }
        vector<int> dp(nums.size(), 0);
        dp[0] = nums[0];
        dp[1] = max(nums[0], nums[1]);

        for (int i = 2; i < nums.size(); i++) {
            dp[i] = max(dp[i - 1], dp[i - 2] + nums[i]);
        }

        return dp[nums.size() - 1];
    }
};
*/

//  Optimize space 
//  we only ever need the last 2 elements, so can just make variables for them and ditch vec

//  Solved in 1 min
//  Time - O(n)
//  Space - O(1)

class Solution {
public:
    int rob(vector<int>& nums) {
        if (nums.size() == 1) {
            return nums[0];
        }
        if (nums.size() == 2) {
            return max(nums[0], nums[1]);
        }
        int backTwo = nums[0];
        int backOne = max(nums[0], nums[1]);

        for (int i = 2; i < nums.size(); i++) {
            int cur = max(backOne, backTwo + nums[i]);
            backTwo = backOne;
            backOne = cur;
        }

        return backOne;
    }
};

//  30 min total 