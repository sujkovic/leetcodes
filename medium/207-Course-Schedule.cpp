//  Build adjacency list
//  ex numCourses 2, prereqs [1,0], [0, 1]
//  0 -> 1
//  1 -> 0

//

//  had no idea how to detect cycle so watched neetcode vid and now reattempting an hour later

//  ex
//  1 -> 2
//  2 -> 3, 4
//  3 -> 5
//  4 -> 1
//  5 ->

//  first, build a graph (map) of each course : prereq
//  make a visited set to track the nodes currently in the call stack
//  then, loop through each node, calling dfs on it
//  dfs:
//      if curNode is in visited, return false
//      else, add curnode to visited
//      for each node in cur nodes adj list
//          call dfs on it
//              if it returns false, return false
//              else, its safe (no cycle), pop it from the adj list
//      remove curnode from visited
//      return true

//  Solved in 14 minutes with the only error being visited.delete instead of .erase im cracked
//  Time - O(V + E)
//  Space - O(V + E)

class Solution
{
public:
    bool dfs(int curCourse, vector<vector<int>> &graph, unordered_set<int> &visited)
    {
        if (visited.find(curCourse) != visited.end())
        {
            return false;
        }
        visited.insert(curCourse);

        while (!graph[curCourse].empty())
        {
            if (!dfs(graph[curCourse].back(), graph, visited))
            {
                return false;
            }
            graph[curCourse].pop_back();
        }

        visited.erase(curCourse);
        return true;
    }
    bool canFinish(int numCourses, vector<vector<int>> &prerequisites)
    {
        vector<vector<int>> graph(numCourses, vector<int>());
        unordered_set<int> visited;

        //  Init graph
        for (int i = 0; i < prerequisites.size(); i++)
        {
            graph[prerequisites[i][0]].push_back(prerequisites[i][1]);
        }

        //  Dfs from every node in graph
        for (int i = 0; i < graph.size(); i++)
        {
            if (!dfs(i, graph, visited))
            {
                return false;
            }
        }

        return true;
    }
};