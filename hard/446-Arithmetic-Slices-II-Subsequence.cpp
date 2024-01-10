//  dfs top down
//  start at beginning of array,
//      at each point we can either include or not include the current number
//  build a tree of every possible combo
//  ex.
//                  2           4           6           8           10
//            /  /   \  \
//          4   6    8  10
//        / | \
//       6  8  10
//          |
//         10
/*
class Solution {
public:
    int dfs(vector<int>& nums, vector<int> &curSlice, int curIndex) {
        cout << "curIndex " << curIndex << ", vec: ";
        for (int i = 0; i < curSlice.size(); i++) {
            cout << curSlice[i] << " ";
        }
        cout << endl;
        if (curIndex >= nums.size()) {
            return 0;
        }
        int res = 0;
        if (curSlice.size() > 2) {
            int cur = curSlice[curSlice.size() - 1];
            int prev = curSlice[curSlice.size() - 2];
            int prevPrev = curSlice[curSlice.size() - 3];
            if (abs(prev - prevPrev) != abs(cur - prev)) {
                return 0;
            }
            res++;
        }

        for (int i = curIndex; i < nums.size(); i++) {
            curSlice.push_back(nums[i]);
            res += dfs(nums, curSlice, i);
            curSlice.pop_back();
        }
    
        return res;
    }
    int numberOfArithmeticSlices(vector<int>& nums) {
        vector<int> curSlice;
        return dfs(nums, curSlice, 0);
    }
};

*/


//  bottom up dp

//  solved in like an hour and a half with watching neetcode vid and all, tbh i still do not fully understand, need to come back to this problem and draw it out more

//  Time - O(n^2)   double for loop
//  Space - O(n^2)  memo of size nums * nums

class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& nums) {
        int len = nums.size();
        vector<unordered_map<long int, long int>> memo(len, unordered_map<long int, long int>());
        int res = 0;

        for (int i = 1; i < nums.size(); i++) {
            for (int j = 0; j < i; j++) {
                long int dif = (long int)nums[i] - (long int)nums[j];
                memo[i][dif] += 1 + memo[j][dif];
                res += 1 + memo[j][dif];
            }
        }
        return res - ((len * (len - 1)) / 2);
    }
};