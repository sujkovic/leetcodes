//  brute force just do double for loop 

//  Finished in 4 minutes, TLE as expected

//  Time - O(n^2)
//  Space - O(1)
/*
class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        vector<int> res;
        
        for (int i = 0; i < temperatures.size(); i++) {
            int possible = false;

            for (int j = i + 1; j < temperatures.size(); j++) {
                if (temperatures[j] > temperatures[i]) {
                    res.push_back(j - i);
                    possible = true;
                    break;
                }
            }

            if (!possible) {
                res.push_back(0);
            }
        }

        return res;
    }
};
*/
//  0 1 2 3 4 5 6 7
//  1 1 4 2 1 1 0 0

//  (76, 6), (73, 7)

//  Initialize a stack of pair<int, int>, and a result vec of size temps.size
//  Loop thru temps
//      if cur < top of stack
//          while top of stack < cur
//              set result vec at top of stacks index to cur index - top of stack index
//              pop top of stack
//      push cur to top of stack
//  return res

//  Time - O(n)
//  Space - O(n)

//  Solved in 20 minutes
//      Most of it trying to figure out how to use monotonic stack for this problem

class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
       int len = temperatures.size();
       vector<int> res(len, 0);
       stack<pair<int, int>> stk;
       stk.push({temperatures[0], 0});

       for (int i = 1; i < temperatures.size(); i++) {
           int curTemp = temperatures[i];

           if (!stk.empty() && curTemp > stk.top().first) {
               while (!stk.empty() && curTemp > stk.top().first) {
                   res[stk.top().second] = i - stk.top().second;
                   stk.pop();
               }
           }
           
           stk.push({curTemp, i});
       }

       return res;
    }
};