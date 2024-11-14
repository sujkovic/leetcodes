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


//  level order = bfs
//  in bfs, we use a queue to visit the tree level by level
//  while queue not empty
//      for all elements currently in the queue (the current level)
//          add their children to results and to the queue, popping them when done

//  Solved in 9 minutes
//      comments - forgot the null input case, and used wrong queue functions
//          for queue its just push, pop, front

//  Time - O(n)
//  Space - O(n)

class Solution {
public:
    vector<vector<int>> bfs(TreeNode* root) {
        vector<vector<int>> result;
        queue<TreeNode*> q;
        q.push(root);

        while (!q.empty()) {
            int levelSize = q.size();
            vector<int> levelResult;
            
            while (levelSize > 0) {
                TreeNode* curNode = q.front();
                q.pop();

                levelResult.push_back(curNode->val);
                if (curNode->left != nullptr) {
                    q.push(curNode->left);
                }
                if (curNode->right != nullptr) {
                    q.push(curNode->right);
                }

                levelSize--;
            }

            result.push_back(levelResult);
        }

        return result;
    }
    vector<vector<int>> levelOrder(TreeNode* root) {
        if (root == nullptr) {
            return {};
        }
        return bfs(root);
    }
};