//           top down backtracking memo approach         //

//  examples
//  1 2 3 4 5 6
//  1 2 3 4 5 6
//  can do 6 + 1 or 1 + 6

//  basically gonna be a decision tree problem where # of branches = the # of sides of each die (k)
//      and the depth of the tree is the # of dice (n)

//                                                  []
//           1                    2                3                 4                 5               6
//   /   /  /  \   \  \     / / /   \ \ \       ...
//  1   2  3   4   5   6   1 2 3    4 5 6       ...

//  and keep track of the cur sum throughout the recursive calls, until you hit target number of dice
//  can probably memoize with some sort of hashmap, cant think of it yet gonna just code out brute force and come back
//  thought process took around 9 minutes

//  solved in 45 minutes (looked at neetcode vid to figure out the memoization)

//  Time - O(n * target * k * logn)
//      # of recursive calls and map operations are logn
//          would be n * k but unordered_map doesnt support pairs need to figure tht out
//  Space - O(n * target)
//      Recursive call stack depth

class Solution
{
public:
    int MOD = pow(10, 9) + 7;
    int decisionTree(int n, int &k, int target, map<pair<int, int>, int> &map)
    {
        if (map.find({n, target}) != map.end())
        {
            return map[{n, target}];
        }
        if (n == 0)
        {
            if (target == 0)
            {
                return 1;
            }
            else
            {
                return 0;
            }
        }

        int res = 0;
        for (int i = 1; i <= k; i++)
        {
            res = (res + decisionTree(n - 1, k, target - i, map)) % MOD;
        }

        map[{n, target}] = res;
        return res;
    }
    int numRollsToTarget(int n, int k, int target)
    {
        map<pair<int, int>, int> map;
        int res = decisionTree(n, k, target, map);
        return res;
    }
};

//             bottom up dp approach           //

//  ex 2 dice, 6 sides, target 7
//
// target | 0  1  2  3  4  5  6  7
//   n ---|------------------------
//    0   | 1  0  0  0  0  0  0  0
//    1   | 0  1  1  1  1  1  1  0
//    2   | 0  0  2  2  4  4  6  6
//        |

//  watched neetcode explanation of this and still not getting it
//  need to go back and relearn coin change 2, comments saying its similar