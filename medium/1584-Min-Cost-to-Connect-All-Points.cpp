//  can use kruskals algorithm, which is basically just union find with like an extra step
//  first, create all possible edges between points
//      ex. for 5 points, it would be 4 + 3 + 2 + 1 = 10 points
//  sort the edges by weight (can just do a custom sort function using manhattan distance to avoid storing weights)
//  loop through the edges from lowest weight, adding them only if thay are not in the same set already
//      when we add an edge, also increment a result variable with the edge weight
//  once we've added all the edges to the union find data structure, return result
//  ^ 7 min

//  Ok spent 30 minutes trying to work through this and realized indexing is going to be borderline impossible
//  so i think im gonna make a node struct with a primary key, x value, and y value

/*
class DSU {
private:
    vector<vector<pair<int, int>>> parent;
public:
    DSU(vector<vector<int>>& points) {
        parent = vector<vector<pair<int, int>>>(points.size(), vector<pair<int, int>>(points[0].size(), {0, 0}));
        for (int i = 0; i < points.size(); i++) {
            parent[points[i][0]][points[i][1]] = points[i];
        }
    }
    int findRoot(int node) {
        if (node == parent[node]) {
            return node;
        }
        parent[node] = findRoot(parent[node]);
        return parent[node];
    }
    bool unionSubset(int x, int y) {
        parentX = findRoot(x);
        parentY = findRoot(Y);

        if (parentX == parentY) {
            return false;
        }

        parent[parentX] = parentY;
        return true;
    }
};

class Solution {
public:
    int minCostConnectPoints(vector<vector<int>>& points) {
        DSU dsu(points);
        return 1;
    }
};
*/

//  Reattempting but with a node struct and fresh mind after the above abomination yesterday
//  Solved in 32 min RAHHHHH
//  Added ranking in another 5 minutes but it had zero effect on the runtime
//  Time - O(nlogn) due to sorting
//  Space - O(n)
//  Im proud of this one didnt need to google a single thing for struct/comparator syntax or dsu/kruskals stuff

struct Node
{
    int x;
    int y;
    int id;
    Node(int x, int y, int id) : x(x), y(y), id(id) {}
};

class DSU
{
private:
    vector<Node> parent;
    vector<int> rank;

public:
    DSU(vector<vector<int>> &points)
    {
        for (int i = 0; i < points.size(); i++)
        {
            Node node(points[i][0], points[i][1], i);
            parent.push_back(node);
            rank.push_back(1);
        }
    }
    Node findRoot(Node node)
    {
        if (node.id == parent[node.id].id)
        {
            return node;
        }
        parent[node.id] = findRoot(parent[node.id]);
        return parent[node.id];
    }
    bool unionSubset(Node x, Node y)
    {
        Node parentX = findRoot(x);
        Node parentY = findRoot(y);

        if (parentX.id == parentY.id)
        {
            return false;
        }

        if (rank[parentX.id] > rank[parentY.id])
        {
            parent[parentY.id] = parentX;
            rank[parentX.id] += rank[parentY.id];
        }
        else
        {
            parent[parentX.id] = parentY;
            rank[parentY.id] += rank[parentX.id];
        }
        return true;
    }
};

class Solution
{
public:
    int minCostConnectPoints(vector<vector<int>> &points)
    {
        DSU dsu(points);
        vector<pair<Node, Node>> edges;
        int costToConnectPoints = 0;
        int edgesAdded = 0;

        //  Create all possible edges
        for (int i = 0; i < points.size(); i++)
        {
            for (int j = i + 1; j < points.size(); j++)
            {
                Node node1(points[i][0], points[i][1], i);
                Node node2(points[j][0], points[j][1], j);
                edges.push_back({node1, node2});
            }
        }

        //  Sort edges by manhattan distance
        sort(edges.begin(), edges.end(), [](const pair<Node, Node> &edge1, const pair<Node, Node> &edge2)
             {
            int dist1 = abs(edge1.first.x - edge1.second.x) + abs(edge1.first.y - edge1.second.y);
            int dist2 = abs(edge2.first.x - edge2.second.x) + abs(edge2.first.y - edge2.second.y);
            return dist1 < dist2; });

        for (int i = 0; i < edges.size(); i++)
        {
            if (edgesAdded == points.size())
            {
                break;
            }
            if (dsu.unionSubset(edges[i].first, edges[i].second))
            {
                costToConnectPoints += (abs(edges[i].first.x - edges[i].second.x) + abs(edges[i].first.y - edges[i].second.y));
                edgesAdded++;
            }
        }

        return costToConnectPoints;
    }
};