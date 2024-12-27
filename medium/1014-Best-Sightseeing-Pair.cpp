//  Going to try bruteforce first
//  Just try every possible combination 

//  Finisehd in 6 min, TLE
//  Time O(n^2)
//  Space O(1)

/*
class Solution {
public:
    int maxScoreSightseeingPair(vector<int>& values) {
        int best = 0;

        for (int i = 0; i < values.size(); i++) {
            for (int j = i + 1; j < values.size(); j++) {
                best = max(best, values[i] + values[j] - (j - i));
            }
        }

        return best;
    }
};
*/

//  optimize

//  8 1 5 2 6

//  0 4 0 0 4 0 0 0 0 5
//  dont think sliding window / prefix sum will work

//  8 1 5 2 6
//  i = 1   biggest is 8 w/ index 1, curBest = 8 + 1 - 1 = 8
//  i = 2   biggest is 8

//  ^ spent like 10 min

//  Ok gave up and watched the neetcode video
//  Basically you want to just iterate through the array keeping track of idk how to explain,
//  the current best value accounting for both its size and distance
//  ex. 
//  8 1 5 2 6
//  i          best = max(best - 1, 8 - 0) = 8, bestScore = best + curVal
//    i                             1 - 1  = 7, bestScore = 7 + 1 = 8
//      i                           5 - 2  = 6, bestScore = 6 + 5 = 11
//        i                         2 - 3  = 5, bestScore = 5 + 2  still 11
//          i                       6 - 4  = 4, bestScore = 4 + 6  still 11

//  Solved in 12 min
//  Time - O(n)
//  Space - O(1)

class Solution {
public:
    int maxScoreSightseeingPair(vector<int>& values) {
        int bestScore = 0;
        int bestSpot = values[0];

        for (int i = 1; i < values.size(); i++) {
            bestScore = max(bestScore, (bestSpot - 1) + values[i]);
            bestSpot = max(bestSpot - 1, values[i]);
        }

        return bestScore;
    }
};