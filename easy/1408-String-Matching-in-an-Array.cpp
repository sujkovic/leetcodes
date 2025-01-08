//  To check if substr do s.find(sub) == string::npos

//  Brute force 
//  Double loop, check if cur string is a substr of every other string

//  Solved in 11 min
//      half was debugging cause i was doing words[i].find(words[i]) but i wanted the opposite
//  Time - O(n^2 * w)
//      where n = wordsSize and w = longest worst in words
//  Space - O(1)

class Solution {
public:
    vector<string> stringMatching(vector<string>& words) {
        vector<string> res;

        for (int i = 0; i < words.size(); i++) {
            for (int j = 0; j < words.size(); j++) {
                if (i != j && words[j].find(words[i]) != string::npos) {
                    res.push_back(words[i]);
                    break;
                }
            }
        }

        return res;
    }
};