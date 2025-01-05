//  Solved Dec 25, 2024, forgot to push to github tho

//  i think the problem just reduces down to solving the following problem for both trees:
//      find the node such that the distance between it and every other node is minimized
//      ex in ex 1 tree 1, it would be 0, since the dist between it and every other node is 1
//          but if you pick any other node, there will be a distance of 2
//  so i think you could just dfs from each node in the two trees, returning the node with the 
//      smallest max distance between it and any other node
//  then the answer would be that value from tree 1 + that value from tree 2 + 1

//  to clarify, dfs should return the largest distance between our starting node and any other node
//  then we want to find the minimum of all the dfs calls we make from main

//  thought i had it done in 25 min but missed an edge case
//  if one of the trees' diameters is still LARGER than the result i calculate, 
//      aka mintree1 + mintree2 + 1, then we throw out our calculation and have to return
//      the original tree's diameter so that is still the resulting diameter of the final tree

//  Finished in 40 min, TLE :|
//  Time - max( O( (Vn + En) * Vn), O( (Vm + Em) * Vm ) )
//      aka dfs(v+e) for each node (v) and take worst case from either tree

/*
class Solution {
public:
    int dfs(unordered_map<int, vector<int>> &tree, unordered_set<int> &visited, int curNode) {
        visited.insert(curNode);
        int maxDistance = 0;

        for (int i = 0; i < tree[curNode].size(); i++) {
            if (visited.find(tree[curNode][i]) == visited.end()) {
                maxDistance = max(maxDistance, dfs(tree, visited, tree[curNode][i]) + 1);
            }
        }

        return maxDistance;
    }
    int minimumDiameterAfterMerge(vector<vector<int>>& edges1, vector<vector<int>>& edges2) {
        //  first convert the input into maps
        unordered_map<int, vector<int>> tree1;
        unordered_map<int, vector<int>> tree2;

        //  init tree 1
        for (int i = 0; i < edges1.size(); i++) {
            tree1[edges1[i][0]].push_back(edges1[i][1]);
            tree1[edges1[i][1]].push_back(edges1[i][0]);
        }

        //  init tree 2
        for (int i = 0; i < edges2.size(); i++) {
            tree2[edges2[i][0]].push_back(edges2[i][1]);
            tree2[edges2[i][1]].push_back(edges2[i][0]);
        }

        //  Find the minimum of the dfs call from each vertex in our trees
        //  And store maximum in case we can't optimize
        int minDistTree1 = (edges1.size() == 0) ? 0 : INT_MAX;
        int minDistTree2 = (edges2.size() == 0) ? 0 : INT_MAX;
        int diameterTree1 = 0;
        int diameterTree2 = 0;

        for (auto it = tree1.begin(); it != tree1.end(); it++) {
            unordered_set<int> visited;
            int curDfsCall = dfs(tree1, visited, it->first);

            minDistTree1 = min(minDistTree1, curDfsCall);
            diameterTree1 = max(diameterTree1, curDfsCall);

        }

        for (auto it = tree2.begin(); it != tree2.end(); it++) {
            unordered_set<int> visited;
            int curDfsCall = dfs(tree2, visited, it->first);

            minDistTree2 = min(minDistTree2, curDfsCall);
            diameterTree2 = max(diameterTree2, curDfsCall);
        }

        return max(max(diameterTree1, diameterTree2), minDistTree1 + minDistTree2 + 1);
    }
};
*/

//  Reattempting the next day with more optimal solution
//  Problem can be reduced to find the "center" of each tree, which is really just the 
//  diameter divided by 2. 
//  the answer will either be (diam tree1 / 2) + (diam tree2 / 2) + 1, OR
//      the diam of tree 1 or diam tree 2 if either is bigger than the above, since that means
//      we cant optimize
//  yesterday i was dfsing from every node to see which is the center which made it v^2 and is unnecessary
//  can avoid that by simply picking any node, and doing a dfs from it to find the furthest node.
//  need to then save that furthest node, then do a dfs from it to find the diameter
//      i think i'll need to modify the dfs to be able to figure out what that furthest node is,
//      prolly gonna keep a global count variable to see how far out we are and a global furthestNode

//  this problem would probably be better to bfs might try that after

//  Solved in 34 min :D
//      just had two errors, called dfs on curNode insatead of tree[curnode][i] 
//          and had to do ceil for the last return and cast stuff cause c++ is annoying with that
//  Time - O(n + m)
//  Space - O(n + m)

class Solution {
public:
    unordered_map<int, vector<int>> initTree(vector<vector<int>> &edges) {
        unordered_map<int, vector<int>> tree;

        for (int i = 0; i < edges.size(); i++) {
            tree[edges[i][0]].push_back(edges[i][1]);
            tree[edges[i][1]].push_back(edges[i][0]);
        }

        return tree;
    }

    void getFarthestNode(unordered_map<int, vector<int>> &tree, unordered_set<int> &visited, int &farthestDepth, int &farthestNode, int curNode, int curDepth) {
        visited.insert(curNode);
        if (curDepth > farthestDepth) {
            farthestNode = curNode;
            farthestDepth = curDepth;
        }

        for (int i = 0; i < tree[curNode].size(); i++) {
            if (visited.find(tree[curNode][i]) == visited.end()) {
                getFarthestNode(tree, visited, farthestDepth, farthestNode, tree[curNode][i], curDepth + 1);
            }
        }
    }

    int getTreeDiameter(unordered_map<int, vector<int>> &tree, unordered_set<int> &visited, int curNode) {
        visited.insert(curNode);
        int maxDepth = 0;

        for (int i = 0; i < tree[curNode].size(); i++) {
            if (visited.find(tree[curNode][i]) == visited.end()) {
                maxDepth = max(maxDepth, getTreeDiameter(tree, visited, tree[curNode][i]) + 1);
            }
        }

        return maxDepth;
    }

    int minimumDiameterAfterMerge(vector<vector<int>>& edges1, vector<vector<int>>& edges2) {
        //  init trees
        unordered_map<int, vector<int>> tree1 = initTree(edges1);
        unordered_map<int, vector<int>> tree2 = initTree(edges2);

        //  init diameters to 0 in case of empty tree
        int diameterTree1 = 0;
        int diameterTree2 = 0;

        if (edges1.size() != 0) {
            //  First, get the farthest node
            int farthestNode = -1;
            int farthestDepth = 0;
            unordered_set<int> visited;
            getFarthestNode(tree1, visited, farthestDepth, farthestNode, tree1.begin()->first, 0);
            //  Then, get the diameter of the tree from that node
            visited.clear();
            diameterTree1 = getTreeDiameter(tree1, visited, farthestNode);
        }
        
        if (edges2.size() != 0) {
            //  First, get the farthest node
            int farthestNode = -1;
            int farthestDepth = 0;
            unordered_set<int> visited;
            getFarthestNode(tree2, visited, farthestDepth, farthestNode, tree2.begin()->first, 0);
            //  Then, get the diameter of the tree from that node
            visited.clear();
            diameterTree2 = getTreeDiameter(tree2, visited, farthestNode);
        }

        return max(max(diameterTree1, diameterTree2), (int)ceil((float)diameterTree1 / 2) + (int)ceil((float)diameterTree2 / 2) + 1);
    }
};