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


//  Perform a bfs on the tree, checking if each level is even/odd

//  let n = # of nodes in tree
//  Time Complexity - O(n), search each node once
//  Space Complexity - O(n), queue to hold nodes
//  Solved in 40 minutes
//      Completely misread the question originally
//      spent 10 minutes wondering why it wasnt working til i reread it
//      spent another 15 minutes forgetting that when you make a new 
//      node its not automatically a null object, its CHILDREN are, oops

class Solution {
public:

    bool bfs(TreeNode* root) {
        queue<TreeNode*> q;
        q.push(root);
        bool isCurLevelOdd = true;

        while (!q.empty()) {
            queue<TreeNode*> newQueue;
            TreeNode* lastNode = new TreeNode();
            bool isFirstIteration = true;
            while (!q.empty()) {
                TreeNode* curNode = q.front();
                q.pop();
                if (isCurLevelOdd && !isFirstIteration && (curNode->val <= lastNode->val)) {
                    return false;
                }

                if (!isCurLevelOdd && !isFirstIteration && (curNode->val >= lastNode->val)) {
                    return false;
                }

                if ((isCurLevelOdd && curNode->val % 2 == 0)) {
                    return false;
                }
                if ((!isCurLevelOdd && curNode->val % 2 == 1)) {
                    return false;
                }

                if (curNode->left) {
                    newQueue.push(curNode->left);
                }

                if (curNode->right) {
                    newQueue.push(curNode->right);
                }

                isFirstIteration = false;
                lastNode = curNode;
            }
            
            q = newQueue;
            isCurLevelOdd = !isCurLevelOdd;
        }
        return true;
    }

    bool isEvenOddTree(TreeNode* root) {
        return bfs(root);
    }
};