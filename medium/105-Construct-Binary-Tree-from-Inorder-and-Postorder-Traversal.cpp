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


//  3 9 20 15 7   preorder
//  9 3 15 20 7   postoder
//  preorder is basically level order traversal, but we need to find out when a level starts
//      like if the 9 didnt exist, it would be 3 20 15 17
//  but maybe we can use the inorder to check, since in it the 9 comes before the 3
//  ^ at this point checked neetcode vid and yeah im on the right track
//  basically preorder always starts at root, so from there find the 3 in postorder
//      wherever the 3 is in postorder, that divides the array btwn left/right side
//      so we would then build the left subtree with the left side of the array,
//      and the right subtree with right side

//  TreeNode* dfs(preorder, inorder, pIndex, left, right)
//      if out of bounds, return
//      
//      TreeNode* cur = new TreeNode(preorder[pIndex])
//      int iIndex = the index of preorder[pindex] in inorder
//      cur->left = dfs(preorder, inorder, pIndex + 1, left, iIndex - 1)
//      cur->right = dfs(preorder, inorder, pIndex + 2, iIndex + 1, right)
//      return cur


//  Solved in 33 min
//      Only thing that didnt work was the pIndex
//      I was trying to just pass a copy and then increment in the dfs function call, 
//      but for a case like [1, 2] that would go out of bounds and checking for that would give wrong res
//      checked solutions (leetcode and neetcode), ig if you pass ref and do ++ in 
//      initializing the new node it works fine
//  Time - O(n)
//  Space - O(n)
//      if you do it without the map, it would be Time O(n^2), Space O(1)

class Solution {
public:
    TreeNode* dfs(vector<int> &preorder, vector<int> &inorder, unordered_map<int, int> &map, int &pIndex, int left, int right) {
        if (left > right) {
            return nullptr;
        }

        int iIndex = map[preorder[pIndex]];
        TreeNode* curNode = new TreeNode(preorder[pIndex++]);
        curNode->left = dfs(preorder, inorder, map, pIndex, left, iIndex - 1);
        curNode->right = dfs(preorder, inorder, map, pIndex, iIndex + 1, right);

        return curNode;
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        unordered_map<int, int> map;
        int pIndex = 0;
        for (int i = 0; i < inorder.size(); i++) {
            map[inorder[i]] = i;
        }

        return dfs(preorder, inorder, map, pIndex, 0, inorder.size() - 1);
    }
};