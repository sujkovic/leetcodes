//  make a dfs decision tree 
//  can either include cur word or not include
//  keep a vector for each call of size 26, aka if cur letter used
//  if we already have that letter, return 0
//  else return the max of the two recursive calls
//  base case is hitting end of vec, go through the cur vec and return number of 1s
//  
//                                            ""
//                    "un"                                         ""
//          "uniq"             "un"                       "iq"              ""
//  "unique"     "uniq"    "unqu"       "un"       "ique"    "iq"      "qu"      ""


//  Time - O(2^n)
//      size of the decision tree
//      at each decision you can make two choices, and the height of tree is n (arr size)
//  Space - O(n)
//      the chars vec within each call is constant size (26), so O(1)
//      and recursive call stack is max O(n)

//  Solved in 26 minutes 
//      (literally spent 10 minutes debugging then realized the problem was my 
//       cout statement that i was using for debugging going out of bounds lmao)

//  apparantly you cant memoize this idk why needa watch neetcode vid later

class Solution {
public:
    int dfs(vector<string> &arr, vector<int> chars, int index) {
        if (index >= arr.size()) {
            int res = 0;
            for (int i = 0; i < chars.size(); i++) {
                res += chars[i];
            }

            return res;
        }
        
        int dontInclude = dfs(arr, chars, index + 1);
        int include;
        bool duplicateFound = false;

        for (int i = 0; i < arr[index].length(); i++) {
            char curChar = arr[index][i];
            if (chars[curChar - 'a'] == 1) {
                duplicateFound = true;
            }

            chars[curChar - 'a'] = 1;
        }

        if (duplicateFound) {
            include = 0;
        }
        else {
            include = dfs(arr, chars, index + 1);
        }

        return max(dontInclude, include);
    }
    int maxLength(vector<string>& arr) {
        vector<int> chars(26, 0);
        return dfs(arr, chars, 0);
    }
};