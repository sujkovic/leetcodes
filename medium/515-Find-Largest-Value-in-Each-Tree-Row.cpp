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


//  just a bfs and for each level of bfs get the max value, push to res vec

//  Solved in 6 min
//      Forgot to check for null root and negative values stop rushing
//  Time - O(n)
//  Space - O(n)

class Solution {
public:
    vector<int> bfs(TreeNode* root) {
        queue<TreeNode*> q;
        q.push(root);
        vector<int> largestVals;

        while (!q.empty()) {
            int qSize = q.size();
            int curLargest = INT_MIN;

            while (qSize) {
                TreeNode* curNode = q.front();
                curLargest = max(curLargest, curNode->val);

                if (curNode->left != nullptr) {
                    q.push(curNode->left);
                }
                if (curNode->right != nullptr) {
                    q.push(curNode->right);
                }

                q.pop();
                qSize--;
            }

            largestVals.push_back(curLargest);
        }

        return largestVals;
    }
    vector<int> largestValues(TreeNode* root) {
        if (root == nullptr) {
            return {};
        }
        return bfs(root);
    }
};