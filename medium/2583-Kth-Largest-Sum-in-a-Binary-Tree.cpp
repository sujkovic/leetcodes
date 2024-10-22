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

//  Level order traversal = bfs
//  kth largest = max heap (priority queue)
//  so do a bfs, and after each iteration insert the current level sum into heap
//  when done, pop the top k - 1 elements from the heap then return the top

//  Solved in 13 min
//  Time - O(n) where n is # nodes in tree. visit each node once
//  Space - O(n)
//      heap size is O(height of tree) = O(log(n))
//      bfsQueue size is at most the bottom level of a complete tree, O(n / 2) = O(n)

class Solution
{
public:
    void bfs(TreeNode *root, priority_queue<long long> &heap)
    {
        queue<TreeNode *> bfsQueue;
        bfsQueue.push(root);

        while (!bfsQueue.empty())
        {
            int bfsQueueSize = bfsQueue.size();
            long long curLevelSum = 0;

            while (bfsQueueSize > 0)
            {
                TreeNode *curNode = bfsQueue.front();
                curLevelSum += curNode->val;

                if (curNode->left)
                {
                    bfsQueue.push(curNode->left);
                }
                if (curNode->right)
                {
                    bfsQueue.push(curNode->right);
                }

                bfsQueue.pop();
                bfsQueueSize--;
            }

            heap.push(curLevelSum);
        }
    }

    long long kthLargestLevelSum(TreeNode *root, int k)
    {
        priority_queue<long long> heap;
        bfs(root, heap);

        if (heap.size() < k)
        {
            return -1;
        }

        while (k > 1)
        {
            heap.pop();
            k--;
        }

        return heap.top();
    }
};