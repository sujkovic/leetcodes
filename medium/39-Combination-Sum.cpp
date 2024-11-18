//                                      []
//            2                 3                 6                7
// 2, 2  2, 3  2, 6  2, 7   3, 2
//  i dont think this approach would skip over duplicates  
//  could just keep a set of results, and sort every time we want to add smtn
//  would be slow tho but just to get a solution in first

//  Solved in 16min
//      let n = candidats size
//  Time - O(n^maxVal * nlogn) -> i think bc maxval is unrelated to n, n^maxval no longer overrides nlogn
//  space - O(n)

/*
class Solution {
public:
    void dfs(vector<int> &candidates, vector<vector<int>> &res, set<vector<int>> &resSet, vector<int> curCombination, int curSum, int &target) {
        if (curSum  > target) {
            return;
        }
        if (curSum == target) {
            sort(curCombination.begin(), curCombination.end());
            if (resSet.find(curCombination) == resSet.end()) {
                resSet.insert(curCombination);
                res.push_back(curCombination);
            }
            return;
        }

        for (int i = 0; i < candidates.size(); i++) {
            curCombination.push_back(candidates[i]);
            curSum += candidates[i];
            dfs(candidates, res, resSet, curCombination, curSum, target);
            curCombination.pop_back();
            curSum -= candidates[i];
        }
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> res;
        set<vector<int>> resSet;
        dfs(candidates, res, resSet, {}, 0, target);
        return res;
    }
};
*/


//  Optimize without the sorting in dfs
//  had to look at the solutions to figure this out but basically, if you sort 
//  the input array before calling any dfs, and then iterating through the array
//  with the index as a dfs parameter, we won't have duplicates
//  i guess it makes sense like in the case 2, 3, 6 7, itll go as follows:
//               2                   3                  6                   7
//    2,2   2,3   2,6   2,7   3,3   3,6   3,7       6,7    6,7             7,7
//  2,2,2...                3,3,3..  3,6,6.. 3,7,7..

//  Solved in 5 min
//  According to neetcode, TC is O(2^target), leetcode ai says O(2^n)
//  i think neetcode is probably right
//  i thought it was candidatssize^target at first since you're making at most 
//    candidates size calls within each dfs call, need to review this

/*
class Solution {
public:
    void dfs(vector<int> &candidates, vector<vector<int>>& res, int &target, vector<int> curCombination, int curSum, int index) {
        if (curSum > target) {
            return;
        }
        if (curSum == target) {
            res.push_back(curCombination);
            return;
        }

        for (int i = index; i < candidates.size(); i++) {
            curCombination.push_back(candidates[i]);
            curSum += candidates[i];
            dfs(candidates, res, target, curCombination, curSum, i);
            curCombination.pop_back();
            curSum -= candidates[i];
        }
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> res;
        dfs(candidates, res, target, {}, 0, 0);
        return res;
    }
};
*/


//  ah so neetcodes approach is different, either:
//      include nums[i], dfs(nums, i)
//      dont include nums[i], dfs(nums, i + 1)
//                                       []
//                    2                                      []
//      2,2                     2                  3                 []
//  2,2,2    2,2           2, 3      2         3, 3     3        6         []

//  makes sense now why its 2^t, still not sure what my code would be considered?

class Solution {
public:
    void dfs(vector<int> &candidates, vector<vector<int>>& res, vector<int> curCombination, int remainingSum, int index) {
        if (remainingSum < 0 || index >= candidates.size()) {
            return;
        }
        if (remainingSum == 0) {
            res.push_back(curCombination);
            return;
        }

        //  include cur num
        curCombination.push_back(candidates[index]);
        dfs(candidates, res, curCombination, remainingSum - candidates[index], index);

        //  dont include cur num
        curCombination.pop_back();
        dfs(candidates, res, curCombination, remainingSum, index + 1);
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> res;
        dfs(candidates, res, {}, target, 0);
        return res;
    }
};