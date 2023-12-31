//               Brute force             //  

//  keep a curTarget and res
//  loop through s 
//      for every index, check the furthest equal char if there is one and update res
//  return res

//  Time O(n^2)
//  Space O(1)

//  Solved in 10 minutes
/*
class Solution {
public:
    int maxLengthBetweenEqualCharacters(string s) {
        int res = -1;

        for (int i = 0; i < s.length(); i++) {
            int curLength = -1;

            for (int j = i; j < s.length(); j++) {
                if (s[j] == s[i]) {
                    curLength = j - i - 1;
                }
            }
            res = max(res, curLength);
        }

        return res;
    }
};
*/

//               Optimized              //

//  Had to look at the hint for a sec for this one (hint was save pairs of equal indices)
//  Make a hashmap of <char, pair<int, int>, and initialize res to -1
//  Iterate through s
//      if a char isnt already in hashmap, insert it with the pair <index, -1>
//      if it is, modify the second value of its pair to be the current index
//  Iterate through hashmap
//      if the second value of the pair is not -1
//          update res with the difference between the values
//      if it is
//          do nothing
//  return res

//  Time O(n)
//  Space O(n)

//  Solved in 6 minutes

class Solution {
public:
    int maxLengthBetweenEqualCharacters(string s) {
        int res = -1;
        unordered_map<char, pair<int, int>> map;

        for (int i = 0; i < s.length(); i++) {
            if (map.find(s[i]) == map.end()) {
                map[s[i]] = {i, -1};
            }
            else {
                map[s[i]] = {map[s[i]].first, i};
            }
        }

        for (auto element : map) {
            if (element.second.second != -1) {
                res = max(res, element.second.second - element.second.first - 1);
            }
        }

        return res;
    }
};
