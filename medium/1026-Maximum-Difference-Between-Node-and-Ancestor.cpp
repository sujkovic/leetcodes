/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

//  need to find the maximum and minimum in each subtree and return the biggest difference
//  between max/mins in any subtree
//  do a dfs
//  keep track of the max/min seen so far in any dfs call, updating them with cur val if needed
//  return abs(max - min)

//  Time - O(n) - need to search all n nodes in tree
//  Space - O(n) - recursive stack (height of tree, worst case n)

//  Solved in 11 min 

class Solution {
public:
    void dfs(TreeNode* cur, int minNum, int maxNum, int &res) {
        if (!cur) {
            return;
        }

        minNum = min(minNum, cur->val);
        maxNum = max(maxNum, cur->val);
        res = max(res, abs(maxNum - minNum));
        dfs(cur->left, minNum, maxNum, res);
        dfs(cur->right, minNum, maxNum, res);
    }
    int maxAncestorDiff(TreeNode* root) {
        int res = 0;
        dfs(root, 10001, -1, res);
        return res;
    }
};