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
class Solution
{
public:
    int bfs(TreeNode *node, int &res)
    {
        if (!node)
        {
            return 0;
        }

        int left = bfs(node->left, res) + 1;
        int right = bfs(node->right, res) + 1;
        res = max(res, left + right);

        return max(left, right);
    }
    int diameterOfBinaryTree(TreeNode *root)
    {
        int res = 0;
        bfs(root, res);
        return res - 2;
    }
};