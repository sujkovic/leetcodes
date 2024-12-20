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

//  want to do a level order traversal, so bfs
//  for each level of the tree, push the nodes to a temp level vec
//  if the current level is odd,
//      iterate through the vec w/ left and right pointer
//          temp = vec[left].val
//          vec[left].val = vec[right].val
//          vec[right].val = temp

//  Solved in 15min
//      only error was forgot to do left++,right--
//  Time - O(n)
//  Space - O(n)
//      the max size of a level, which is bottom level, which is n/2, which is O(n)

class Solution {
public:
    void bfs(TreeNode* root) {
        queue<TreeNode*> q;
        q.push(root);
        int level = 0;

        while (!q.empty()) {
            int qSize = q.size();
            vector<TreeNode*> levelVec;

            while (qSize) {
                //  push is back pop is front. get front
                TreeNode* cur = q.front();
                levelVec.push_back(cur);

                if (cur->left != nullptr) {
                    q.push(cur->left);
                }
                if (cur->right != nullptr) {
                    q.push(cur->right);
                }

                q.pop();
                qSize--;
            }

            if (level % 2 == 1) {
                int left = 0;
                int right = levelVec.size() - 1;
                while (left < right) {
                    int temp = levelVec[left]->val;
                    levelVec[left]->val = levelVec[right]->val;
                    levelVec[right]->val = temp;
                    left++;
                    right--;
                }
            }
            level++;
        }
    }
    TreeNode* reverseOddLevels(TreeNode* root) {
        bfs(root);
        return root;
    }
};