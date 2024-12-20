//  for sides to be valid, their slope must be 0 or infinity
//      aka (x1 - x2) / (y1 - y2) =  0 or infinity
//  Given points (x1, y1), (x2, y2), (x3, y3), (x4, y4)
//      y1 = y2 and y3 = y4 and y1 != y3
//      x1 = x2 and x3 = x4 and x1 != x3
//      then area is abs(x1 - x2) * abs(y1 - y3)

//  can build a map of all points at a certain x value and certain y value

//  Finished in 19 min, TLE
//  Time - O(n^4)
//  Space - O(1)

/*
class Solution {
public:
    int minAreaRect(vector<vector<int>>& points) {
        sort(points.begin(), points.end());
        int minArea = INT_MAX;

        for (int i = 0; i < points.size(); i++) {
            for (int j = i + 1; j < points.size(); j++) {
                //  found a vertical line, now we want another with same y vals
                if (i != j && points[i][0] == points[j][0]) {
                    for (int k = j + 1; k < points.size(); k++) {
                        for (int l = k + 1; l < points.size(); l++) {
                            //  2 vertical sides of rectangle found
                            if (points[k][0] == points[l][0] && points[i][1] == points[k][1] && points[j][1] == points[l][1]) {
                                int curArea = abs(points[i][1] - points[j][1]) * abs(points[i][0] - points[k][0]);
                                minArea = min(minArea, curArea);
                            }
                        }
                    }
                }
            }
        }

        if (minArea == INT_MAX) {
            return 0;
        }
        return minArea;
    }
};
*/

//  Ok building off earlier idea, i think im gonna make a vector of 
//  horizontal lines, and of vertical lines, and then sort them by length

//  actually scratch all that, check discussion, you just need 2 diagonals
//  so can just do a double for loop
//  for i in points
//      for j in points
//          if difference in x == difference in y, theyre diagonal
//              update min

//  (2, 1), (3, 2)
//  abs(2 - 3) == abs(1 - 2)

/*
class Solution {
public:
    int minAreaRect(vector<vector<int>>& points) {
        minArea = INT_MAX;

        for (int i = 0; i < points.size(); i++) {
            for (int j = 0; j < points.size(); j++) {
                if (abs(points[i][0] - points[j][0]) == abs(points[i][1] - points[j][1])) {
                    int area = (abs(points[i]))
                }
            }
        }


        if (minArea == INT_MAX) {
            return 0;
        }
        return minArea;
    }
};
*/

//  ^ yeah that also doesn't work, watched a video on it , basically you want to keep a set
//  of points you've visited as you're going through the points, then for each point you visit,
//  loop THROUGH the visited set, so we'll have vec[i] = x1, y1 and set[j] = x2, y2,
//      check if the set contains (x1, y2) AND (x2, y1)
//          if yes, update the min area


//  ex. 
//  y
//  3  .     .
//  2     .
//  1  .     .
//  0  1  2  3   x

//  so eventually we'll have (x1, y1 = 1, 3) in vec and (x2, y2 = 3, 1) in set
//  so since we have two diagonals, we can get the other two diagonals from a combination
//  of those points, and if those other two diagonals exist, we have a rectangle


//  Solved in 20 min
//  Time - O(n^2 * logn)
//      since c++ unordered map doesnt provide a hash for vectors, you have to use set, 
//      which has logn lookup. if you made a hash or assumed you're given one, time is then O(n^2)
//  Space - O(n^2)

/*
class Solution {
public:
    int minAreaRect(vector<vector<int>>& points) {
        int minArea = INT_MAX;
        set<vector<int>> set;

        //  loop THROUGH the visited set, so we'll have vec[i] = x1, y1 and set[j] = x2, y2,
        for (int pItr = 0; pItr < points.size(); pItr++) {                              //  O(n)
            int x1 = points[pItr][0];
            int y1 = points[pItr][1];

            for (auto sItr = set.begin(); sItr != set.end(); sItr++) {                  //  O(n)
                int x2 = (*sItr)[0];
                int y2 = (*sItr)[1];
                
                //  check if the set contains (x1, y2) AND (x2, y1)
                if (set.find({x1, y2}) != set.end() && set.find({x2, y1}) != set.end()) {  //   O(logn) 
                    int curArea = abs(x2 - x1) * abs(y2 - y1);
                    minArea = min(minArea, curArea);
                }
            }

            set.insert({x1, y1});                                                       //  O(logn)
        }



        return minArea == INT_MAX ? 0 : minArea;
    }
};
*/

//  Added a custom hash but leetcode is still saying O(n^2 * logn) runtime weird
//  maybe my hash function is terrible and its just chaining values or smtn


struct customHash {
    size_t operator()(const vector<int> &pair) const {
            return hash<int>()(pair[0]) ^ (hash<int>()(pair[1]) << 1);
        };
};

class Solution {
public:
    int minAreaRect(vector<vector<int>>& points) {
        int minArea = INT_MAX;
        /*
        //  if using this one just need to do decltype(customHash) when using it

        auto customHash = [](const vector<int> &pair) {
            return pair[0] ^ pair[1];
        };

        OR you could just do it inline like with sorting but wrap it with decltype(...)
        */
        unordered_set<vector<int>, customHash> set;

        //  loop THROUGH the visited set, so we'll have vec[i] = x1, y1 and set[j] = x2, y2,
        for (int pItr = 0; pItr < points.size(); pItr++) {                              //  O(n)
            int x1 = points[pItr][0];
            int y1 = points[pItr][1];

            for (auto sItr = set.begin(); sItr != set.end(); sItr++) {                  //  O(n)
                int x2 = (*sItr)[0];
                int y2 = (*sItr)[1];
                
                //  check if the set contains (x1, y2) AND (x2, y1)
                if (set.find({x1, y2}) != set.end() && set.find({x2, y1}) != set.end()) {  //   O(logn) 
                    int curArea = abs(x2 - x1) * abs(y2 - y1);
                    minArea = min(minArea, curArea);
                }
            }

            set.insert({x1, y1});                                                       //  O(logn)
        }



        return minArea == INT_MAX ? 0 : minArea;
    }
};