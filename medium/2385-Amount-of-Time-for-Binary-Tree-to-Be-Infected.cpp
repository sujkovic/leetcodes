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

//  from my thoughts it seems like we need to get the height of left and right of root
//  then figure out what side the start is on
//  the answer is gonna be the height of the opposite side 
//      - 1
//      + the distance from start to the root
//      + distance from start to the bottom IFF that side height is > opposite height
//
//  will need to do a bfs

//  welp spent 30 minutes on this, have gone through like 5 submissions finding out 
//  that there are more edge cases that im not hitting and one of them made me realized
//  my algorithm is not going to work, will return to this in the morning hopefully 
//  neetcode uploads

/*
class Solution {
public:
    int bfs(TreeNode *root, int start, int &startLevel) {
        if (!root) {
            return 0;
        }

        int curLevel = 1;
        deque<TreeNode*> queue;
        queue.push_back(root);

        while (!queue.empty()) {
            int curQueueSize = queue.size();

            for (int i = 0; i < curQueueSize; i++) {
                if (queue.front()->val == start) {
                    startLevel = curLevel;
                }
                if (queue.front()->left) {
                    queue.push_back(queue.front()->left);
                }
                if (queue.front()->right) {
                    queue.push_back(queue.front()->right);
                }

                queue.pop_front();
            }

            curLevel++;
        }

        return curLevel - 1;
    }
    int amountOfTime(TreeNode* root, int start) {
        int startLevel = -1;
        int startsOnLeft = false;
        int leftHeight = bfs(root->left, start, startLevel);
        if (startLevel != -1) {
            startsOnLeft = true;
        }
        int rightHeight = bfs(root->right, start, startLevel);
        cout << leftHeight << " " << rightHeight << endl;
        if (root->val == start) {
            return max(leftHeight, rightHeight);
        }
        else if (startsOnLeft) {
            if (rightHeight == 0) {
                return max(startLevel, leftHeight - startLevel);
            }
            if (leftHeight - startLevel > rightHeight) {
                return rightHeight + startLevel + (leftHeight - startLevel);
            }
            return rightHeight + startLevel;
        }
        else {
            if (leftHeight == 0) {
                return max(startLevel, rightHeight - startLevel);
            }
            if (rightHeight - startLevel > leftHeight) {
                return leftHeight + startLevel + (rightHeight - startLevel);
            }
            return leftHeight + startLevel;
        }
    }
};
*/


//  Ok after looking at solutions it seems like the only way to solve this is with parent pointers, so will retry that way

//  create a GraphNode struct (same as treenode but w/ parent ptr)
//  first, do a dfs to convert each TreeNode into a GraphNode
//      during that, also save a reference to the start GraphNode
//  then, do a bfs from the start GraphNode, keeping count of the # of levels visited
//  return # levels visited

//  Time - O(n) - iterating through all n nodes in input tree 2-3 times 
//                              (somewhere between that bc of start distanec from root in findStart function)
//  Space - O(n) - making a copy of the tree, as well as deque and visited set

//  Solved in 45 minutes
//      for some reason i had so much trouble setting the startNode, couldnt just simply assign it and took forever
//      to think of a solution for it (was trying to do it from the dfs function)

class Solution {
public:
    struct GraphNode {
        int val;
        GraphNode *left;
        GraphNode *right;
        GraphNode *parent;
        GraphNode() : val(-1), left(nullptr), right(nullptr), parent(nullptr) {}
        GraphNode(TreeNode *node, GraphNode* p) : val(node->val), left(nullptr), right(nullptr), parent(p) {}
    };
    GraphNode* dfs(TreeNode* cur, GraphNode* prev, bool wentLeft) {
        if (!cur) {
            return nullptr;
        }

        GraphNode* newNode = new GraphNode(cur, prev);
        if (prev != nullptr) {
            if (wentLeft) {
                prev->left = newNode;
            }
            else {
                prev->right = newNode;
            }
        }
        dfs(cur->left, newNode, true);
        dfs(cur->right, newNode, false);

        return newNode;
    }
    void findStart(GraphNode* cur, GraphNode* startNode, int &start) {
        if (!cur) {
            return;
        }
        if (cur->val == start) {
            startNode->val = cur->val;
            startNode->left = cur->left;
            startNode->right = cur->right;
            startNode->parent = cur->parent;
        }
        findStart(cur->left, startNode, start);
        findStart(cur->right, startNode, start);
    }
    int bfs(GraphNode* startNode) {
        int numLevels = -1;
        queue<GraphNode*> queue;
        unordered_set<int> visited;
        queue.push(startNode);
        visited.insert(startNode->val);

        while (!queue.empty()) {
            int queueSize = queue.size();
            for (int i = 0; i < queueSize; i++) {
                GraphNode* cur = queue.front();
                visited.insert(cur->val);
                queue.pop();

                if (cur->parent && visited.find(cur->parent->val) == visited.end()) {
                    queue.push(cur->parent);
                }
                if (cur->left && visited.find(cur->left->val) == visited.end()) {
                    queue.push(cur->left);
                }
                if (cur->right && visited.find(cur->right->val) == visited.end()) {
                    queue.push(cur->right);
                }
            }

            numLevels++;
        }

        return numLevels;
    }
    int amountOfTime(TreeNode* root, int start) {
        GraphNode *graphRoot = dfs(root, nullptr, false);
        GraphNode *startNode = new GraphNode();
        findStart(graphRoot, startNode, start);
        return bfs(startNode);
    }
};