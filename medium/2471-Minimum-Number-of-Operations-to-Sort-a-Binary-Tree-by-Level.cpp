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


//  not 100% sure if this approach will work but for the min operations part -
//  we basically want to look at the each index 1 by 1
//  now for that index, if the value there isn't the smallest from the subarray
//      starting at that index, swap the smallest number with it
//  else just continue
//  and obv do bfs and do this for each level
//  im just not sure if this will result in the "minimum" but i think it will?
//  im just gonna attempt it and if it doesnt work ill watch the neetcode vid
//  since otherwise its prolly some sorting algorithm i dont rememeber how to implement

//  Cool 17 minutes wasted time for neetcode vid
//  Time complexity would be O(n^3), space O(n)
//  ok nevermind watched neetcode vid and my approach was right just had a bug
//  30 min total

//  also time is actually O(n^2)
//  just realized since theres n total nodes, and each "level" is O(n^2), the time is NOT n^3
//  since a level isnt size n
//  like yeah technically you can say bottom level is n/2 which is n
//  but in the context of this problem the levels all add up to n
//  this is a bad explanation i needa brush up on this

//  wait i got it so you can write it as a formula, where the size of each level is n/2, n/4, etc, NOT n
//  O((n / 2)^2) + O((n / 4)^2) + O((n / 8)^2) .... so the additions dont matter since all bounded by O(n^2)

/*
class Solution {
public:
    int bfs(TreeNode* root) {
        queue<TreeNode*> q;
        q.push(root);
        int numSwaps = 0;

        while (!q.empty()) {
            int qSize = q.size();
            vector<int> level;

            while (qSize) {
                TreeNode* cur = q.front();
                level.push_back(cur->val);

                if (cur->left) {
                    q.push(cur->left);
                }
                if (cur->right) {
                    q.push(cur->right);
                }

                q.pop();
                qSize--;
            }

            //  minswap logic
            for (int i = 0; i < level.size(); i++) {
                int minVal = level[i];
                int minValIndex = i;

                //  Find min value from cur subarray starting at i
                for (int j = i; j < level.size(); j++) {
                    if (level[j] < minVal) {            //  SPENT 15 MINUTES DEBUGGING CAUSE THIS LINE WAS level[j] < level[i] rip
                        minVal = level[j];
                        minValIndex = j;
                    }
                }
                //  if min val not at i, swap it with the val at i
                if (minValIndex != i) {
                    swap(level[minValIndex], level[i]);
                    //  since we perform a swap, increment operation count
                    numSwaps++;
                }
            }
        }

        return numSwaps;
    }
    int minimumOperations(TreeNode* root) {
        return bfs(root);
    }
};
*/

//  Optimizing (got idea from neetcode vid)

//  instead of the double loop through the array in the minswap logic,
//  we can first sort the level, then map each number to its index in the sorted array
//  this way if the number in our cur position isnt the min from the remaining array,
//  we find and swap the min in O(1) time

//  So our total time would be O(nlogn) for sorting

//  7 6 8 5   - level
//  5 6 7 8   - sorted level
//  Map
//  7 : 0
//  6 : 1
//  8 : 2
//  5 : 3

//  iteration 0
//  7 6 8 5 
//  5 6 7 8
//  7 : 0
//  6 : 1
//  8 : 2
//  5 : 3

//  iteration 1
//  5 6 8 7 
//  5 6 7 8
//  7 : 3
//  6 : 1
//  8 : 2
//  5 : 0

//  iteration 2
//  5 6 8 7 
//  5 6 7 8
//  7 : 3
//  6 : 1
//  8 : 2
//  5 : 0

//  iteration 3
//  5 6 7 8
//  5 6 7 8
//  7 : 2
//  6 : 1
//  8 : 3
//  5 : 0


//  Solved in 25 min
//      Tried to properly swap everything but just ended up messing everything up
//      was doing way more than i needed to
//  Time - O(nlogn)
//  Space - O(n)

class Solution {
public:
    int bfs(TreeNode* root) {
        queue<TreeNode*> q;
        q.push(root);
        int numSwaps = 0;

        while (!q.empty()) {
            int qSize = q.size();
            vector<int> level;

            while (qSize) {
                TreeNode* cur = q.front();
                level.push_back(cur->val);

                if (cur->left) {
                    q.push(cur->left);
                }
                if (cur->right) {
                    q.push(cur->right);
                }

                q.pop();
                qSize--;
            }

            //  min operations logic

            //  Make a sorted level vec
            vector<int> sortedLevel = level;
            sort(sortedLevel.begin(), sortedLevel.end());

            //  Map the sorted elements to their indices (reverse)
            unordered_map<int, int> map;
            for (int i = 0; i < level.size(); i++) {
                map[level[i]] = i;
            }

            //  Find how many operations are needed
            for (int i = 0; i < level.size(); i++) {
                if (level[i] != sortedLevel[i]) {
                    //  swap in level array
                    int curIndex = i;
                    int targetIndex = map[sortedLevel[i]];
                    
                    level[targetIndex] = level[curIndex];
                    map[level[i]] = targetIndex;

                    numSwaps++;
                }
            }
        }

        return numSwaps;
    }
    int minimumOperations(TreeNode* root) {
        return bfs(root);
    }
};