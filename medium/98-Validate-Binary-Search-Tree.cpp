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

//  Perform a DFS starting at root
//  Keep track of current left and right boundary
//  ex -   2
//        /  \
//       1    3
//      at 1, boundaries are  infinity < 1 < 2
//  So keep a left and right parameter
//  on each function call, 
//  if !cur, return true

//  if left < cur->val < right, dfs right and left
//      for right, update left boundary to cur->val
//      for left, update right boundary to cur->Val
//  return true


//  let n = nodes in tree
//  Time Complexity - O(n), look at all nodes in tree
//  Space Complexity - O(n), worst case call stack depth 
//      is n for a tree that goes straight in one direction
//  Solved in 30 min


class Solution {
public:
    bool dfs(TreeNode* curNode, long left, long right) {
        if (!curNode) {
            return true;
        }
        if (curNode->val >= right || curNode->val <= left) {
            return false;
        }
        return dfs(curNode->left, left, curNode->val) && dfs(curNode->right, curNode->val, right);
    }

    bool isValidBST(TreeNode* root) {
        return dfs(root, LONG_MIN, LONG_MAX);
    }
};