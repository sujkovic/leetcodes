//  Gonna attempt this without knowing union find or kruskals based on a thought i just had
//  From looking at the examples, it seems that if you look at a given edge between 2 nodes
//      if you do a dfs in the direction of both node a to node b, and node b to node a,
//      and there is a cycle in both cases, you can remove that edge
//      but if for one of the cases we cant find a cycle, we cant remove that edge
//      ex. edge 1-5 in example 2
//          going from 5 to 1, we eventually find a cycle
//          but going from 1 to 5, we hit a dead end, so that edge is necessary
//      im thinking just call a dfs to detect cycle from a node a, but dont include node b
//      do this for each node starting from the end of the input array
//  ^ 10 minute mark

//  SOLVED IN 38 MIN OH YEAH
//      only change i had to make was update the excluded node to the cur one whenever you call dfs again
//      since the graph is not direct, the edge between 2 nodes will by default always be a loop technically

//  Time complexity is terrible though, I think O((V + E) * E)
//      For each edge, you do a dfs (O(V + E)) on the entire graph from it
//  Space is O(V + E)

/*
class Solution {
public:
    //  True means cycle found, false means no
    bool dfs(unordered_map<int, vector<int>> &map, unordered_set<int> &visited, int excludedNode, int curNode) {
        if (visited.find(curNode) != visited.end()) {
            return true;
        }
        visited.insert(curNode);

        for (int i = 0; i < map[curNode].size(); i++) {
            if (map[curNode][i] != excludedNode) {
                if (dfs(map, visited, curNode, map[curNode][i])) {
                    return true;
                }
            }
        }

        return false;
    }
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        unordered_map<int, vector<int>> map;
        unordered_set<int> visited;
        for (int i = 0; i < edges.size(); i++) {
            map[edges[i][0]].push_back(edges[i][1]);
            map[edges[i][1]].push_back(edges[i][0]);
        }

        for (int i = edges.size() - 1; i >= 0; i--) {
            bool dfsOne = dfs(map, visited, edges[i][0], edges[i][1]);
            visited.clear();
            bool dfsTwo = dfs(map, visited, edges[i][1], edges[i][0]);
            visited.clear();
            if (dfsOne && dfsTwo) {
                return edges[i];
            }
        }

        return {};
    }
};
*/

//  TODO: solve with union find

//  Make a Disjoint Set Union class
//  Constructor
//      set each nodes parent to be itself
//  Find(int x)     //  given a node x, find its root parent
//      if x = its parent
//          return x
//      return find(parent of x)
//  Union(int x, int y)
//      parentX = find(x)
//      parentY = find(y)
//      if (parentX == parentY)     //  they're already in the same set = cycle found = redundant connection
//          return false
//      parent[parentX] = parent[Y]     //  union the two subsets by setting the root parent of one to be parent of root element of other

//  Then for the main function
//  init a DSU of size edges.size, since were given num edges = num vertices
//  loop through edges starting from the back
//      union the nodes in the current edge, if false, return the current edge

//  ^ this thought process and writing took 19 min of total time below

//  Solved in 27 min on the dot
//  Time - O(n^2)
//  Space - O(n)

/*
class DSU {
private:
    vector<int> parent;
public:
    DSU(int n) {
        for (int i = 0; i <= n; i++) {  //  1 index but still need a zero there
            parent.push_back(i);
        }
    }

    int findRoot(int node) {
        if (node == parent[node]) {
            return node;
        }
        return findRoot(parent[node]);
    }

    bool unionSubsets(int x, int y) {   //  'union' is a resesrved keyword
        int parentX = findRoot(x);
        int parentY = findRoot(y);

        if (parentX == parentY) {
            return false;
        }

        parent[parentX] = parentY;
        return true;
    }
};

class Solution {
public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        DSU dsu(edges.size());

        for (int i = 0; i < edges.size(); i++) {
            if (!dsu.unionSubsets(edges[i][0], edges[i][1])) {
                return edges[i];
            }
        }

        return {};
    }
};
*/

//  Optimized DSU with path compression
//  Time O(nlogn)

//  Then can reduce to O(n) with ranking but i get 0ms runtime
//  so i cant even test if that makes a difference here

class DSU
{
private:
    vector<int> parent;

public:
    DSU(int n)
    {
        for (int i = 0; i <= n; i++)
        { //  1 index but still need a zero there
            parent.push_back(i);
        }
    }

    int findRoot(int node)
    {
        if (node == parent[node])
        {
            return node;
        }
        parent[node] = findRoot(parent[node]);
        return parent[node];
    }

    bool unionSubsets(int x, int y)
    { //  'union' is a resesrved keyword
        int parentX = findRoot(x);
        int parentY = findRoot(y);

        if (parentX == parentY)
        {
            return false;
        }

        parent[parentX] = parentY;
        return true;
    }
};

class Solution
{
public:
    vector<int> findRedundantConnection(vector<vector<int>> &edges)
    {
        DSU dsu(edges.size());

        for (int i = 0; i < edges.size(); i++)
        {
            if (!dsu.unionSubsets(edges[i][0], edges[i][1]))
            {
                return edges[i];
            }
        }

        return {};
    }
};