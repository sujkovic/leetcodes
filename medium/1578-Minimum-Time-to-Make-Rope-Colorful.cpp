//  loop through colors array
//  keep a curSum and curMax
//  whenever you see multiple of a color in a row, increment the curSum by neededTime 
//      and keep track of the biggest neededTime within that streak (thats the one we'll keep to minimize time)
//  when the streak of that color breaks, add it to result
//  return when done looping

//  Solved in 11 minutes 
//  (looked at the discussion tab after a few minutes cause i was confused, saw they were saying its not as hard as it looks, then came up with idea myself)

//  Time - O(n)
//      loop through input size n
//  Space - O(1)
//      no new data structs

class Solution {
public:
    int minCost(string colors, vector<int>& neededTime) {
        bool needToDelete = false;
        int curSum = neededTime[0];
        int curMax = curSum;
        int res = 0;

        for (int i = 1; i < colors.length(); i++) {

            if (colors[i] == colors[i - 1]) {
                curMax = max(curMax, neededTime[i]);
                curSum += neededTime[i];
                needToDelete = true;
            }
            
            else {
                if (needToDelete) {
                    res += (curSum - curMax);
                }
                
                curSum = neededTime[i];
                curMax = curSum;
                needToDelete = false;
            }
        }

        if (needToDelete) {
            res += (curSum - curMax);
        }

        return res;
    }
};