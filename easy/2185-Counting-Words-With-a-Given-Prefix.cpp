//  i dont think theres any fast way to do this i think this is just an easy
//  for i in words
//      bool containsprefix = true
//      for j in cur word
//          if curword[j] != pref[j]
//              containsprefix = false
//      res += containsprefix
//  return res

//  Solved in 5 min
//      Logic bug, inner loop should be just the length of pref not words[i], and then make sure pref is smaller
//      that took like 30 seconds to fix
//  Time - O(n * m)    n = words.length, m = pref.length
//  Space - O(1)

class Solution {
public:
    int prefixCount(vector<string>& words, string pref) {
        int res = 0;

        for (int i = 0; i < words.size(); i++) {
            if (words[i].size() < pref.size()) {
                continue;
            }

            bool isPrefix = true;

            for (int j = 0; j < pref.size(); j++) {
                if (words[i][j] != pref[j]) {
                    isPrefix = false;
                }
            }

            res += isPrefix;
        }

        return res;
    }
};