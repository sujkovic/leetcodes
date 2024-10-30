/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

//  keep map<ognode, newnode>
//  dfs from root, exploring each node
//  for each node from oggraph (dfs call)
//      make a new node
//      set new node value to ognode value
//      make a new vector of nodes (adj list)
//      loop through each node in ognode adj list
//          if it hasnt been visited (in the map)
//              add it to adj list and make a dfs call on it
//          if it has been visited
//              add map[ogNode] (new node) to the current adj list
//      return new node

//  Solved in 14 min
//  Time - O(V + E)
//  Space - O(V) - Storing V pointers in a map

class Solution
{
public:
    Node *dfs(Node *node, unordered_map<Node *, Node *> &map)
    {
        Node *newNode = new Node();
        map[node] = newNode;
        vector<Node *> adjList;
        newNode->val = node->val;

        for (int i = 0; i < node->neighbors.size(); i++)
        {
            if (map.find(node->neighbors[i]) == map.end())
            {
                dfs(node->neighbors[i], map);
            }
            adjList.push_back(map[node->neighbors[i]]);
        }

        newNode->neighbors = adjList;
        return newNode;
    }
    Node *cloneGraph(Node *node)
    {
        if (!node)
        {
            return nullptr;
        }
        unordered_map<Node *, Node *> map;
        return dfs(node, map);
    }
};