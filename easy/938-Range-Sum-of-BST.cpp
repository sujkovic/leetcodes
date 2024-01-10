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


// currently typing this on an ipad because my laptop is at the repair shop so will probably be slow but 
// do an inorder search
// once you find the lowest number, push every number after it to the res vec until you hit the high num, then return

//  Time - O(n) - need to check at most all nodes in the tree (n nodes)
//  Space - O(logn) - recursive call stack = height of tree, at worst logn

//  Solved in 12 minutes (if i wasnt typing on an ipad probably would be under 5)


class Solution {
public:
    void dfs(TreeNode* cur, int &res, int &low, int &high) {
        if (!cur) {
            return;
        }

        dfs(cur->left, res, low, high);
        if (low <= cur->val && cur->val <= high) {
            res += cur->val;
        }
        dfs(cur->right, res, low, high);
    }
    int rangeSumBST(TreeNode* root, int low, int high) {
        int res = 0;
        dfs(root, res, low, high);
        return res;
    }
};