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


//  do an inorder dfs on both trees
//  for the dfs, once you hit the base caes (a leaf node (cur == nullptr)), push the node to a vec
//  do for both trees
//  return true if the result vecs are the same, else false


//  Let o = root1 height, p= root2 height, n = # nodes in root1, m = # nodes in root2
//  Time - O(max(n, m))
//      Traverse through all the nodes in each tree
//  Space - O(max(2^o, 2^p))
//      Need to store all the nodes in bottom of tree, which is 2 to the power of the height of the tree at worst

//  Solved in 6 minutes

class Solution {
public:
    void dfs(TreeNode *cur, vector<int> &vec) {
        if (!cur) {
            return;
        }
        if (!cur->left && !cur->right) {
            vec.push_back(cur->val);
        }
        
        dfs(cur->left, vec);
        dfs(cur->right, vec);
    }
    bool leafSimilar(TreeNode* root1, TreeNode* root2) {
        vector<int> treeOneVec;
        vector<int> treeTwoVec;
        dfs(root1, treeOneVec);
        dfs(root2, treeTwoVec);
        return treeOneVec == treeTwoVec;
    }
};