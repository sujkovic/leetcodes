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


//  do a dfs, building a map of the nodes at each level
//  need to keep track of parents, so store node with its parent
//  0 : (5, null)
//  1 : (4, 5), (9, 5)
//  2 : (1, 4), (10, 4), (7, 9) 
//  Then, do another dfs. at each node, loop through the nodes in its level, getting sum of all
//  nodes that dont have its parent, then set its value to the sum

//  this was some absolutely horrific overcomplicated code but i couldnt think of anything else at the time
//  finished in 45 minutes and TLE
//  time - O(n^2) - go through all n nodes in tree, and loop through its current level each time, 
//          inner loop is worst case a full bottom level of tree, n / 2 = n
//  space - O(n^2) 

/*
class Solution {
public:
    void buildMap(TreeNode* node, unordered_map<int, vector<pair<TreeNode*, TreeNode*>>> &map, TreeNode* parent, unordered_map<TreeNode*, TreeNode*> &nodeParents, int level) {
        if (!node) {
            return;
        }

        map[level].push_back({node, parent});
        nodeParents[node] = parent;
        buildMap(node->left, map, node, nodeParents, level + 1);
        buildMap(node->right, map, node, nodeParents, level + 1);
    }

    void calculateSums(TreeNode* node, unordered_map<int, vector<pair<TreeNode*, TreeNode*>>> &map, unordered_map<TreeNode*, TreeNode*> &nodeParents, unordered_map<TreeNode*, int> &cousinSums, int level) {
        if (!node) {
            return;
        }

        int cousinSum = 0;

        if (level > 0) {
            for (int i = 0; i < map[level].size(); i++) {
                if (map[level][i].second != nodeParents[node]) {
                    cousinSum += map[level][i].first->val;
                }
            }
        }
        cout << endl;

        cousinSums[node] = cousinSum;
        calculateSums(node->left, map, nodeParents, cousinSums, level + 1);
        calculateSums(node->right, map, nodeParents, cousinSums, level + 1);
    }

    void updateTree(TreeNode* node, unordered_map<TreeNode*, int> &cousinSums) {
        if (!node) {
            return;
        }

        node->val = cousinSums[node];
        updateTree(node->left, cousinSums);
        updateTree(node->right, cousinSums);
    }

    TreeNode* replaceValueInTree(TreeNode* root) {
        unordered_map<int, vector<pair<TreeNode*, TreeNode*>>> map;
        unordered_map<TreeNode*, TreeNode*> nodeParents;
        unordered_map<TreeNode*, int> cousinSums;

        buildMap(root, map, nullptr, nodeParents, 0);
        calculateSums(root, map, nodeParents, cousinSums, 0);
        updateTree(root, cousinSums);

        return root;
    }
};
*/



//  Attempt v2 a day after watching neetcode explanation

//  the sum of a nodes cousins is just that levels sum - the node and its brother
//  so, do a bfs originally to get each levels sum
//  then, do a dfs to update each nodes children, since u need access to the brother

//  Solved in 15 min
//  Time - O(n) - 1 bfs and 1 dfs, both look at each node once
//  Space - O(n) - bfs queue worst case bottom of tree is full

class Solution {
public:
    vector<int> getLevelSums(TreeNode* root) {
        vector<int> levelSums;
        queue<TreeNode*> bfsQueue;
        bfsQueue.push(root);

        while (!bfsQueue.empty()) {
            int queueSize = bfsQueue.size();
            int curLevelSum = 0;
            while (queueSize > 0) {
                curLevelSum += bfsQueue.front()->val;
                if (bfsQueue.front()->left) {
                    bfsQueue.push(bfsQueue.front()->left);
                }
                if (bfsQueue.front()->right) {
                    bfsQueue.push(bfsQueue.front()->right);
                }
                bfsQueue.pop();
                queueSize--;
            }

            levelSums.push_back(curLevelSum);
        }

        return levelSums;
    }

    void dfs(TreeNode* node, vector<int> &levelSums, int index) {
        if (!node) {
            return;
        }

        if (node->left && node->right) {
            int brotherSum = node->left->val + node->right->val;
            node->left->val = levelSums[index + 1] - brotherSum;
            node->right->val = levelSums[index + 1] - brotherSum;
        }
        else if (node->left) {
            node->left->val = levelSums[index + 1] - node->left->val;
        }
        else if (node->right) {
            node->right->val = levelSums[index + 1] - node->right->val;
        }

        dfs(node->left, levelSums, index + 1);
        dfs(node->right, levelSums, index + 1);
    }

    TreeNode* replaceValueInTree(TreeNode* root) {
        vector<int> levelSums = getLevelSums(root);
        root->val = 0;
        dfs(root, levelSums, 0);
        return root;
    }
};
