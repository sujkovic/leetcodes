//  Topological sort

//  example 2
//  0 ->
//  1 -> 0
//  2 -> 0
//  3 -> 1, 2

//  3 -> 1 - > 0
//    \     /
//      > 2
//  so we would return 3,1,2,0 or 3,2,1,0

//  Going to need a graph, a visited set and a stack to keep ordering of courses
//      actually need 2 visited sets -
//          one for cycle detection
//          and one to avoid duplicates for the for loop in main
//  first initialize the graph with all the prereqs
//  then for each node in the graph, call dfs on it
//      if any dfs call returns false, return an empty array (cycle found)
//  then iterate thru the stack, pushing each course to a results vec (reverse order)
//  return results

//  dfs:
//  if cur course is in visitedCycle
//      return false (cycle found)
//  if cur course is in visitedDuplicate
//      return true (to avoid duplicate in result)
//  add cur course to visitedCycle and visitedDuplicate
//  loop thru cur nodes adj list
//      call dfs on cur node
//          if false, return false
//          if true, remove the node from the cur node adj list
//  remove cur course from visitedCycle
//  push cur course to stack

//  The reason this works is we explore depth first as far as we can til we reach
//  a node with no prereqs, since this is the "last" course in the path we would
//  need to take, we put it at the bottom of the stack, then go up a level and repeat
//  and we can remove a node from the adj list since we know once the dfs call on it
//  is complete, we've explored all of its prereqs
//  as for cycle detection, only our current, singular path will ever be in the
//  visited set since we remove a node when done exploring it, so if we ever
//  see a repeat node, we know we must have entered a cycle

//  Solved in 29 minutes
//  Time and space - O(V + E)

class Solution
{
public:
    bool dfs(int curCourse, vector<vector<int>> &graph, unordered_set<int> &visitedCycle, unordered_set<int> &visitedDuplicate, stack<int> &courseStack)
    {
        if (visitedCycle.find(curCourse) != visitedCycle.end())
        {
            return false;
        }
        if (visitedDuplicate.find(curCourse) != visitedDuplicate.end())
        {
            return true;
        }
        visitedCycle.insert(curCourse);
        visitedDuplicate.insert(curCourse);

        for (int i = graph[curCourse].size() - 1; i >= 0; i--)
        {
            if (!dfs(graph[curCourse][i], graph, visitedCycle, visitedDuplicate, courseStack))
            {
                return false;
            }
            graph[curCourse].pop_back();
        }

        visitedCycle.erase(curCourse);
        courseStack.push(curCourse);
        return true;
    }

    vector<int> findOrder(int numCourses, vector<vector<int>> &prerequisites)
    {
        vector<vector<int>> graph(numCourses);
        unordered_set<int> visitedCycle;
        unordered_set<int> visitedDuplicate;
        stack<int> courseStack;
        vector<int> result;

        for (int i = 0; i < prerequisites.size(); i++)
        {
            graph[prerequisites[i][0]].push_back(prerequisites[i][1]);
        }

        for (int i = 0; i < numCourses; i++)
        {
            if (!dfs(i, graph, visitedCycle, visitedDuplicate, courseStack))
            {
                return {};
            }
        }

        while (!courseStack.empty())
        {
            result.push_back(courseStack.top());
            courseStack.pop();
        }
        reverse(result.begin(), result.end());
        return result;
    }
};
