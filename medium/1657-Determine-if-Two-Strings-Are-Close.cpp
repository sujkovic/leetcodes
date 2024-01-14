//  make a vector of char frequencies for each word
//  if the maps are equal, return true
//  else
//  go through all the chars in word1
//  for each char that has equal frequency in word1 and word2, we can just ignore it
//  for everything else, we need to find if in word1, for each non valid char, 
//      if there is another char in word1 that isnt valid, that has the freq of the og char in word2
//  this explanation is awful and i am really not confident in my ability to code this lmao it is too late to be leetcoding i needa go to bed
//  ok sick got it working wasnt that bad, time to knock

//  Time - O(n) - loop through strings of size n
//  Space - O(1) - making 2 vectors of size 26, constant

//  Solved in 25 minutes

class Solution {
public:
    bool closeStrings(string word1, string word2) {
        if (word1.length() != word2.length()) {
            return false;
        }
        vector<int> oneFreq(26, 0);
        vector<int> twoFreq(26, 0);

        for (int i = 0; i < word1.length(); i++) {
            oneFreq[word1[i] - 'a']++;
            twoFreq[word2[i] - 'a']++;
        }

        for (int i = 0; i < oneFreq.size(); i++) {
            if (oneFreq[i] != twoFreq[i]) {
                if (twoFreq[i] == 0 || oneFreq[i] == 0) {
                    return false;
                }
                bool chillin = false;
                for (int j = i + 1; j < oneFreq.size(); j++) {
                    if (oneFreq[j] == twoFreq[i]) {
                        int temp = oneFreq[i];
                        oneFreq[i] = oneFreq[j];
                        oneFreq[j] = temp;
                        chillin = true;
                    }
                }
                if (!chillin) {
                    return false;
                }
            }
        }
        return true;
    }
};