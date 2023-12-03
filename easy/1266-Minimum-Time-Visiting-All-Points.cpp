//  loop through points vec
//      if both coords equal
//          continue
//      if x coords are equal
//          result += dif in y coordinates
//      if y coords are equal
//          result += dif in x coordinates
//      if neither are equal
//          if the dif in x coords and dif in y coords is equal
//              result += the diagonal
//          else
//              result += the diagonal of the smaller dif, + the regular dif of the other 
//  return result


//  O(n) time, O(1) space
//  Just a for loop through input, no new data structs

//  Solved in 20 (spent 10 min debugging forgetting i - 1 in one of my points wow)

class Solution {
public:
    int minTimeToVisitAllPoints(vector<vector<int>>& points) {
        int result = 0;
        for (int i = 1; i < points.size(); i++) {
            int curX = points[i][0];
            int curY = points[i][1];
            int prevX = points[i - 1][0];
            int prevY = points[i - 1][1];

            if (curX == prevX && curY == prevY) {
                continue;
            }
            else if (curX == prevX) {
                result += abs(curY - prevY);
            }
            else if (curY == prevY) {
                result += abs(curX - prevX);
            }
            else {
                result += max(abs(curX - prevX), abs(curY - prevY));

            }
        }
        return result;
    }
};