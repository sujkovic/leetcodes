//  keep track of cur point with a pair
//  make a unordered set of pairs, add every visited point to it
//  if one already exists, return false
//  return true

//  Time - O(n) - One itertaion thru input of size n
//  Space - O(n) - visited set of size n

//  Solved in 10 min

class Solution {
public:
    bool isPathCrossing(string path) {
        pair<int, int> curPoint = {0, 0};
        set<pair<int, int>> visited;
        visited.insert(curPoint);

        for (int i = 0; i < path.length(); i++) {
            if (path[i] == 'N') {
                curPoint.second++;
            }
            else if (path[i] == 'S') {
                curPoint.second--;
            }
            else if (path[i] == 'E') {
                curPoint.first++;
            }
            else if (path[i] == 'W') {
                curPoint.first--;
            }
            
            if (visited.find(curPoint) != visited.end()) {
                return true;
            }
            visited.insert(curPoint);
        }
        return false;
    }
};