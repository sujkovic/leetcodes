//  decision tree problem
//  ex. 11106
//                      ""
//              /               \
//             1                11
//          /    \           /      \
//        11      1         10       1
//       /         \       /          \
//      0          10     6            0 
//  not valid        \  valid     not valid
//                    6 
//                   valid            

//  keep making recursive calls on where youre currently at
//  if the char at cur index is a 1 or 2
//      make a call for adding both the one digit and two digit numbers
//  if the char at cur index is a 0
//      invalid, return

//  Time - O(n)
//      Only need to do one pass through the array to populate the cache, so instead of going through a 2^n tree, its just n
//  Space - O(n)
//      call stack depth (depth of tree)

//  Solved in 40 minutes (10 min thought process, 15ish min to brute force solution, 15ish min memoizing)

class Solution {
public:
    int decisionTree(string &s, int index, unordered_map<int, int> &map) {
        if (index == s.length()) {
            return 1;
        }
        if (s[index] == '0') {
            return 0;
        }
        if (map.find(index) != map.end()) {
            return map[index];
        }

        int res = decisionTree(s, index + 1, map);

        if (index < s.length() - 1 && (s[index] == '1' || (s[index] == '2'&& s[index + 1] < '7'))) {
            res += decisionTree(s, index + 2, map);
        }
        
        map[index] = res;
        return res;
    }
    int numDecodings(string s) {
        unordered_map<int, int> map;
        return decisionTree(s, 0, map);
    }
};