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

//  Do a dfs, going through both trees at the same time
//  if root1->left == root2->left AND root1->right == root2->right
//      keep going like a normal dfs
//  if they're flipped
//      dfs(root1->left, root2->right)
//      dfs(root1->right, root2->left)
//  else if they arent equal or flipped
//      return false

//  Solved in 26 min cause edge cases kept popping up and ig i didnt code it perfectly at first

class Solution
{
public:
    bool dfs(TreeNode *node1, TreeNode *node2)
    {
        if (!node1 && !node2)
        {
            return true;
        }
        if (!node1 || !node2)
        {
            return false;
        }

        //  All children null
        if (!node1->left && !node1->right && !node2->left && !node2->right)
        {
            return true;
        }
        //  Both left children null
        else if (!node1->left && !node2->left)
        {
            return dfs(node1->right, node2->right);
        }
        //  Both right children null
        else if (!node1->right && !node2->right)
        {
            return dfs(node1->left, node2->left);
        }
        //  Flip flopped children null
        else if (!node1->left && !node2->right)
        {
            return dfs(node1->right, node2->left);
        }
        else if (!node1->right && !node2->left)
        {
            return dfs(node1->left, node2->right);
        }
        //  one has all children, other has one or none
        else if ((node1->left && node1->right) && (!node2->left || !node2->right))
        {
            return false;
        }
        else if ((node2->left && node2->right) && (!node1->left || !node1->right))
        {
            return false;
        }
        //  No null children
        //  trees are equal
        else if (node1->left->val == node2->left->val && node1->right->val == node2->right->val)
        {
            return (node1->val == node2->val) &&
                   dfs(node1->left, node2->left) && dfs(node1->right, node2->right);
        }
        //  trees are flip flopped
        else if (node1->left->val == node2->right->val && node1->right->val == node2->left->val)
        {
            return (node1->val == node2->val) &&
                   dfs(node1->left, node2->right) && dfs(node1->right, node2->left);
        }
        //  trees are not equal and not flip flopped equivalently
        else
        {
            return false;
        }
    }

    bool flipEquiv(TreeNode *root1, TreeNode *root2)
    {
        return dfs(root1, root2);
    }
};