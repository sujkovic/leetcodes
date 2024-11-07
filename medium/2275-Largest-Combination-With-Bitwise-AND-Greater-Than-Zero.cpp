//  Brute force could just try every possible combination
//  ex. 1, 5 3
//                                               []
//                      [1]                                             []
//          [1, 5]              [1]                           [5]                  []
//  [1, 5, 3]      [1, 5]   [1, 3]    [1]         [5, 3]            [5]     [3]         []
//      

//  Finished in like 30 min, TLE, but needed to ask chatgpt to debug for me, needed to swap 
//  the order of the if statements and return INT_MIN instead of 0

/*
class Solution {
public:
    int dfs(vector<int> &candidates, int index, int curBitwiseAnd) {
        if (curBitwiseAnd == 0) {
            return INT_MIN;
        }
        if (index == candidates.size()) {
            return 0;
        }

        int include = dfs(candidates, index + 1, curBitwiseAnd & candidates[index]) + 1;
        int dontInclude = dfs(candidates, index + 1, curBitwiseAnd);

        return max(include, dontInclude);
    }
    int largestCombination(vector<int>& candidates) {
        return dfs(candidates, 0, INT_MAX);
    }
};
*/


//  Other method, had to watch neetcode vid, count the occurence of set bits for each number
//  ex. 16, 17, 71, 62, 12, 24, 14
//    10000
//    10001
//  1000111
//   111110
//     1100
//    11000
//     1110
//
//     4432  <- go down each bit above summing up
//           stop at the smalllest numbers number of bits

//  Solved in 15 min
//  Time - O(n * log(m)) where n is candidates size and m is the biggest number
//  Space - O(1) - array is a constant size of 24

/*
class Solution {
public:
    int largestCombination(vector<int>& candidates) {
        vector<int> numSetBits(24, 0);  //  problem says max num is 10^7 which is 24 bits

        for (int i = 0; i < candidates.size(); i++) {
            int curNum = candidates[i];
            int curSetBit = 0;

            while (curNum > 0) {
                if (curNum % 2 == 1) {
                    numSetBits[curSetBit]++;
                }

                curNum = curNum >> 1;
                curSetBit++;
            }

        }

        int maxBits = 0;
        for (int i = 0; i < numSetBits.size(); i++) {
            maxBits = max(maxBits, numSetBits[i]);
        }

        return maxBits;
    }
};
*/


//  Solved in 3 minutes, not sure if this is more efficient or not for time

class Solution {
public:
    int largestCombination(vector<int>& candidates) {
        int maxBits = 0;

        for (int i = 0; i < 24; i++) {
            int curSum = 0;

            for (int j = 0; j < candidates.size(); j++) {
                if (candidates[j] % 2 == 1) {
                    curSum++;
                }

                candidates[j] = candidates[j] >> 1;
            }

            maxBits = max(maxBits, curSum);
        }

        return maxBits;
    }
};
