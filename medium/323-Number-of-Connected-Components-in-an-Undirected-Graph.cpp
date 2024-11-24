//  Use union find
//  initialize a union find data structure of n nodes
//  make a findRoot and unionSubsets function
//  add all edges to it with unionsubsets 
//  at the end, find the number of connected components
//      can have a function that calls findParent on each node
//      and keep a set of unique parents and return the set size

//  Solved in 10 min and accepted on first compile no typos dang
//      + 2 min for path compression / union by rank
//      Also watchted the neetcode vid, dont need the getnumsubsets 
//      everytime we call union, if we're adding to a union just decrement
//      our numSubsets, otherwise if we try to union 2 already unioned nodes
//      do nothing

//  Time - O(n + (m * x))  where x is the unionSubsets time complexity (i have zero clue what it is)
//                  like it seems to be alpha(n) which goes to 5 so is constant?? but leetcode says logn.
//  Space - O(n)

class UnionFind {
private:
    vector<int> parent;
    vector<int> rank;

public:
    UnionFind(int size) {                   //  O(n)
        for (int i = 0; i < size; i++) {
            parent.push_back(i);
            rank.push_back(1);
        }
    }

    int findRoot(int node) {                //  O(1)
        if (parent[node] == node) {
            return node;
        }

        parent[node] = findRoot(parent[node]);
        return parent[node];
    }

    bool unionSubsets(int x, int y) {
        int parentX = findRoot(x);
        int parentY = findRoot(y);

        if (parentX == parentY) {
            return false;
        }

        if (rank[parentX] > rank[parentY]) {
            parent[parentY] = parentX;
            rank[parentX] = rank[parentX] + rank[parentY];
        }
        else {
            parent[parentX] = parentY;
            rank[parentY] = rank[parentX] + rank[parentY];
        }
        return true;
    }

    /*
    int getNumSubsets() {
        unordered_set<int> subsets;

        for (int i = 0; i < parent.size(); i++) {
            subsets.insert(findRoot(parent[i]));
        }

        return subsets.size();
    }
    */
};

class Solution {
public:
    int countComponents(int n, vector<vector<int>>& edges) {
        UnionFind graph(n);                                 //  O(n)
        int numComponents = n;

        for (int i = 0; i < edges.size(); i++) {            //  O(m)
            numComponents -= graph.unionSubsets(edges[i][0], edges[i][1]);
        }

        return numComponents;
    }
};