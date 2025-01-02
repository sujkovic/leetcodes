//  Brute force
//  Loop through the queries vector
//  For each query in queries
//      Loop through words for that l, r range
//          if that word starts and ends with a vowel, add 1 to cur query result
//  Time - O(queriesLength * wordsLength)
//  Space - O(1)

//  Optimized
//  Precompute, make a vector of booleans called vowelStrings
//      if a word in words starts/ends with a vowel, its index in vowelStrings is true
//      else false
//  this saves us the time of looping through each word in words
//  Wait i forgot you can instead keep a running sum and this also elimnates the need
//  to loop through the words vec at all, by just doing
//      vowelStrings[r] - vowelStrings[l]
//  ill just call it prefixsum 

//  Solved in 15 min
//      i was doing prefixsum[r] - prefixsum[l] but had to do 1 - 1, and then also acccount for l == 0
//      ^ that only took like 2-3 min to troubleshoot tho and was only error
//  Time - O(wordsLength + queriesLength)
//  Space - O(wordsLength)

class Solution {
public:
    bool isVowel(char c) {
        if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u') {
            return true;
        }
        return false;
    }
    vector<int> vowelStrings(vector<string>& words, vector<vector<int>>& queries) {
        vector<int> prefixSum;
        int curSum = 0;

        for (int i = 0; i < words.size(); i++) {
            if (isVowel(words[i][0]) && isVowel(words[i][words[i].length() - 1])) {
                curSum++;
            }

            prefixSum.push_back(curSum);
        }

        vector<int> result;

        for (int i = 0; i < queries.size(); i++) {
            if (queries[i][0] == 0) {
                result.push_back(prefixSum[queries[i][1]]);
            }
            else {
                result.push_back(prefixSum[queries[i][1]] - prefixSum[queries[i][0] - 1]);
            }
        }

        return result;
    }
};