//  2, 3, 0, 1, 1, 4
//  if you start at 2, you cant
//  oh wait you literally have to start at 2
//  oh but you can take any number of jumps between 1-2
//  so can jump to the 3 instead of the 0 and then so on

//  first thing that comes to mind is dfs, at any point try to jump
//  between 1 and the cur num

//  Finished in 6 min, TLE
//      misread the instructions and forgot last index also counts, not just end of array
//  Time - O(maxNum^n) -> nvm we're limited by the length of array so it becomes O(n^n)
//  Space - O(n)

/*
class Solution {
public:
    bool dfs(vector<int> &nums, int index) {
        if (index >= nums.size() - 1) {
            return true;
        }
        if (nums[index] == 0) {
            return false;
        }
        
        bool res = false;

        for (int i = index + 1; i <= index + nums[index]; i++) {
            res = res | dfs(nums, i);
        }

        return res;
    }
    bool canJump(vector<int>& nums) {
        return dfs(nums, 0);
    }
};
*/

//  optimize

//  4 min
//  Still TLE
//  O(n^2)

/*
class Solution {
public:
    bool dfs(vector<int> &nums, unordered_map<int, bool> &memo, int index) {
        if (index >= nums.size() - 1) {
            return true;
        }
        if (nums[index] == 0) {
            return false;
        }
        if (memo.find(index) != memo.end()) {
            return memo[index];
        }
        
        bool res = false;

        for (int i = index + 1; i <= index + nums[index]; i++) {
            res = res | dfs(nums, memo, i);
        }

        memo[index] = res;
        return res;
    }
    bool canJump(vector<int>& nums) {
        unordered_map<int, bool> memo;
        return dfs(nums, memo, 0);
    }
};
*/

//  instead of the above, at every index i, loop through nums from i to i + nums[curindex]
//  and pick the biggest number we can find. choose that number to jump to

//  Ok got to 23 min and I've been battling edge cases for the last 10 so gonnna watch video

/*

class Solution {
public:
    bool canJump(vector<int>& nums) {
        int left = 0;

        while (left < nums.size()) {
            if (nums[left] == 0) {  //  base case
                break;
            }

            int right = left + nums[left];
            left++;
            int maxJump = 0;
            int maxJumpIndex = left;

            if (left >= nums.size()) {
                return true;
            }
            
            //  find the biggest number we can currently jump to
            while (left <= right && left < nums.size()) {
                if (nums[left] >= maxJump) {
                    maxJump = nums[left];
                    maxJumpIndex = left;
                }
                left++;

            }

            left = maxJumpIndex;
        }

        if (left < nums.size() - 1) {
            return false;
        }
        return true;
    }
};
*/

//  Watched neetcode vid, need to work backwards in this problem and just move the goal post towards the start

//  2 3 1 1 4
//          i  g = 4
//        i    g = 3 (+1 to get to prev goal)
//      i      g = 2 ^same
//    i        g = 1
//  i          g = 0
// if g = 0, return true

//  Solved in 3 min
//  Time - O(n)
//  Space - O(1)

class Solution {
public:
    bool canJump(vector<int>& nums) {
        int goal = nums.size() - 1;
        int i = nums.size() - 2;

        while (i >= 0) {
            if (i + nums[i] >= goal) {
                goal = i;
            }

            i--;
        }

        if (goal == 0) {
            return true;
        }
        return false;
    }
};