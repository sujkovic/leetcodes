//  Dijkstra's Algorithm
//  first, build an adjacency list given the times vector
//      int : vector<pair<int, int>>
//      source node : {weight, destination node}
//  make a shortestPaths vector and a min heap and a visited set
//  initialize all nodes in shortestPaths to infinity (int_max)
//  insert node k with weight 0 to the min heap and shortestPaths
//  now the idea of dijkstras is pick the smallest edge from the current node,
//  and explore that destination node. update the distance to all nodes connected to it
//  the pseudocode
//  while minheap not empty
//      curnode = top of heap
//      insert curnode in visited
//      pop top of heap
//      for edges in curnode's adj list
//          if shortestPaths[edge.destination] > shortestPaths[curNode] + edge.weight
//              update it
//          if edge.destination is not in visited, add it to the minheap
//  at the end, return the sum of all elements in shortestPaths
//  if any are still int_max, return -1
//  ^ 12 min

//  Spent an hour trying to debug with no luck so redoing it with neetcodes method

/*
class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        unordered_map<int, vector<pair<int, int>>> map;
        vector<int> shortestPaths(n + 1, INT_MAX);
        unordered_set<int> visited;
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> heap;

        for (int i = 0; i < times.size(); i++) {
            map[times[i][0]].push_back({times[i][2], times[i][1]});
        }

        shortestPaths[k] = 0;
        heap.push({0, k});

        while (!heap.empty()) {
            int curNode = heap.top().second;
            int curDist = heap.top().first;
            cout << curNode << endl;
            heap.pop();
            visited.insert(curNode);

            for (int i = 0; i < map[curNode].size(); i++) {
                cout << "curnode shortest path " << shortestPaths[curNode] << endl;
                cout << "looking at " << map[curNode][i].second << " with weight " << map[curNode][i].first << endl;
                cout << shortestPaths[map[curNode][i].second] << ", " << shortestPaths[curNode] << ", " << curDist << endl;
                if (shortestPaths[map[curNode][i].second] > shortestPaths[curNode] + curDist) {
                    shortestPaths[map[curNode][i].second] = shortestPaths[curNode] + curDist;
                }

                if (visited.find(map[curNode][i].second) == visited.end()) {
                    heap.push({map[curNode][i].second});
                }
            }
        }

        int result = 0;

        cout << endl;
        for (int i = 1; i < shortestPaths.size(); i++) {
            cout << shortestPaths[i] << endl;
            if (shortestPaths[i] == INT_MAX) {
                return -1;
            }

            result += shortestPaths[i];
        }

        return result;
    }
};
*/

//  Redoing everything
//  SOLVED IN 10 MIN RAHHHHHHH

class Solution
{
public:
    int networkDelayTime(vector<vector<int>> &times, int n, int k)
    {
        unordered_map<int, vector<pair<int, int>>> map;
        unordered_set<int> visited;
        vector<int> dist(n + 1, INT_MAX);
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> heap;

        for (int i = 0; i < times.size(); i++)
        {
            int source = times[i][0];
            int dest = times[i][1];
            int weight = times[i][2];
            map[source].push_back({weight, dest});
        }

        dist[k] = 0;
        heap.push({0, k});

        while (!heap.empty())
        {
            int source = heap.top().second;
            heap.pop();
            if (visited.find(source) != visited.end())
            {
                continue;
            }
            visited.insert(source);

            for (int i = 0; i < map[source].size(); i++)
            {
                int dest = map[source][i].second;
                int weight = map[source][i].first;

                if (dist[dest] > dist[source] + weight)
                {
                    dist[dest] = dist[source] + weight;
                    heap.push({dist[dest], dest}); // THIS IS THE LINE THAT WAS WRONG
                }
            }
        }

        int result = 0;
        for (int i = 1; i < dist.size(); i++)
        {
            cout << dist[i] << endl;
            if (dist[i] == INT_MAX)
            {
                return -1;
            }
            result = max(result, dist[i]);
        }

        return result;
    }
};