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

//  maximum path some from any node is gonna be the 
//      the node + max path sum of left subtree + max path sum of right subtree
//  but its a little more complicated than that, like in the example,
//  max path sum of the right subtree of -10 would technically be 42, but we dont want to 
//  add the entire thing, so we're just going to return the max subtree length of 20, + 20
//  then we'll just compute the current max path sum and update if needed

//  dfs(root)
//      if null return 0
//      left = dfs(root->left)
//      right - dfs(root->right)
//      curMaxPath = left + right + curNode
//      res = max(res, curMaxPath)
//      return max(left + curnode, right + curnode)

//  Solved in 16 min
//      Missed like 2-3 edge cases, this problem has a lot of them
//  Time - O(n)
//  Space - O(n)

class Solution {
public:
    int dfs(TreeNode *node, int &maxPath) {
        if (node == nullptr) {
            return 0;
        }

        int left = dfs(node->left, maxPath);
        int right = dfs(node->right, maxPath);
        int curMaxPath = max(max(node->val, left + right + node->val), max(left + node->val, right + node->val));
        maxPath = max(maxPath, curMaxPath);

        return max(node->val, max(left + node->val, right + node->val));
    }
    int maxPathSum(TreeNode* root) {
        int maxPath = INT_MIN;
        dfs(root, maxPath);
        return maxPath;
    }
};