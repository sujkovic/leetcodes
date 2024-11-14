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


//             4
//        3         1
//    2      1
//  1    1

//  dfs, where we return the max depth from either left or right, + 1 for the current node
//      ^ before that check if abs(left - right) <= 1, return false if not

//  Solved in 4 minutes
//  O(n) time
//  O(n) space

class Solution {
public:
    int dfs(TreeNode* node, bool &res) {
        if (!node) {
            return 0;
        }

        int left = dfs(node->left, res);
        int right = dfs(node->right, res);

        if (abs(left - right) > 1) {
            res = false;
        }

        return max(left, right) + 1;
    }
    bool isBalanced(TreeNode* root) {
        bool res = true;
        dfs(root, res);
        return res;
    }
};