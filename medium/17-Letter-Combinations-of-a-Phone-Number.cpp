//  Ok im gonna write out the thoughts first
//  Im thinking make a decision tree, with each levle bing the ith index of digits
//  ex "23"
//                          ""
//                  /        |          \
//           "a"            "b"              "c"
//      /    |    \      /    |   \       /    |   \
//  "ad"  "ae"  "af"  "bd"  "be" "bf"   "cd"  "ce"  "cf"

//  So basically make a recursive dfs function
//  Call dfs on original string
//  parameters - og string, cur index, cur result, result vector
//  in dfs, check if we are at end of og string
//      if we are, push cur string to results vector
//  call dfs 3 times, for all 3 possible letters at current index, and increment index



//  Time Complexity - O(4^n)
//      Worst case you only have 9's and 4's, each one multiplies the calls by 4
//  Space Complexity - O(4^n) 
//      Call stack space 
//  Solved in 40 minutes
//      Most of which was trying to figure out a clean way to make the map

class Solution {
public:

    void dfs(string &digits, int index, string curString, vector<string> &results, vector<vector<char>> &map) {
        cout << curString << endl;
        if (index >= digits.size()) {
            results.push_back(curString);
            return;
        }
        int curDigit = digits[index] - '0';
        for (int i = 0; i < map[curDigit].size(); i++) {
            curString.push_back(map[curDigit][i]);
            dfs(digits, index + 1, curString, results, map);
            curString.pop_back();
        }
    }

    vector<vector<char>> initMap() {
        vector<vector<char>> map;
        vector<char> vec;
        map.push_back(vec);
        map.push_back(vec);
        char curChar = 'a';

        for (int i = 1; i <= 26; i++) {
            vec.push_back(curChar);
            curChar++;

            if (((i % 3 == 0) && i < 18) || i == 19 || i == 22 || i == 26) {
                map.push_back(vec);
                vec.clear();
            }
        }
        return map;
    }

    vector<string> letterCombinations(string digits) {
        if (digits.empty()) {
            return {};
        }
        vector<vector<char>> map = initMap();
        vector<string> results;
        dfs(digits, 0, "", results, map);
        return results;
    }
};