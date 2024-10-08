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
class Solution {
public:
    int bfs(TreeNode* node) {
        if (!node) {
            return 0;
        }

        int left = bfs(node->left) + 1;
        int right = bfs(node->right) + 1;

        return max(left, right);
    }
    int maxDepth(TreeNode* root) {
        return bfs(root);
    }
};