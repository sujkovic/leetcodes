//  keep a global hashmap of frequencies of each number and an int res
//  dfs down the tree
//  as you're going down a path from the root to a leaf, keep adding the cur node to a hashmap
//  base case is gonna be when you hit a leaf node (right && left both null)
//      needed to look at hint for this part
//      loop thru hashmap, if more than one number has an odd frequency, its not valid
//      else, increment result by one
//      then decrement the frequency of the current element by one and return
//  return res


//  Time - O(n * m) where n is # of nodes and m is the height of the tree 
//  Space - O(n * m) same thing since we need to store the seen node freqs, and loop thru them

//  Solved in 25 minutes


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
class Solution {
public:
    void dfs(TreeNode* cur, unordered_map<int, int> map, int &res) {
        if (!cur) {
            return;
        }

        map[cur->val]++;
        
        if (!cur->left && !cur->right) {
            int numOddFreqs = 0;
            for (auto element : map) {
                if (element.second % 2 == 1) {
                    numOddFreqs++;
                }
            }
            if (numOddFreqs <= 1) {
                res++;
            }

            map[cur->val]--;
            return;
        }

        dfs(cur->left, map, res);
        dfs(cur->right, map, res);
    }
    int pseudoPalindromicPaths (TreeNode* root) {
        unordered_map<int, int> map;
        int res = 0;
        dfs(root, map, res);
        return res;
    }
};