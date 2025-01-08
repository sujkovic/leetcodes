//  Brute force
//  Double for loop, trying every combo
//  for int i in words
//      for int j in words
//          res += ispreixandsuffix(words[i], words[i])

// ispreixandsuffix
//  if word2.length < word1.length, return false
//  for i = 0 to word1 length
//      if word1[i] != word2[i], return false
//  for i = word1length - 1, j = word2.length - 1
//      if word1[i] != word2[j], return false
//      i--, j--

//  Solved in 10 min
//      Compiled and accepted on first try no typos yippee
//  Time - O(n^2 * length of longest word)
//  Space - O(1)

class Solution {
public:
    bool isPrefixAndSuffix(string &word1, string &word2) {
        if (word2.length() < word1.length()) {
            return false;
        }

        for (int i = 0; i < word1.length(); i++) {
            if (word1[i] != word2[i]) {
                return false;
            }
        }

        int i = word1.length() - 1;
        int j = word2.length() - 1;

        while (i >= 0) {
            if (word1[i] != word2[j]) {
                return false;
            }

            i--;
            j--;
        }

        return true;
    }
    int countPrefixSuffixPairs(vector<string>& words) {
        int res = 0;

        for (int i = 0; i < words.size(); i++) {
            for (int j = i + 1; j < words.size(); j++) {
                res += isPrefixAndSuffix(words[i], words[j]);
            }
        }

        return res;
    }
};