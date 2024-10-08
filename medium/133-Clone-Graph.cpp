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

//  keep a map of all the nodes youve seen so far
//  if you hit one you've seen, ignore
//  loop through each node in the graph, adding all its neighbors to its new node

class Solution
{
public:
    Node *dfs(Node *node, unordered_map<Node *, Node *> &map)
    {
        vector<Node *> adjList;
        Node *newNode = new Node(node->val);
        map[node] = newNode;

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