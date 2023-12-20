//  make hashmap of freqs of chars in each str, return sMap == tMap

//  O(n) both

//  Solved in 3 minutes

//  Look at solns, can optimize to O(1) space by having a vec of 26 ints (alphabet) and just incrementing/decrementing the count of each index based on cur char in each string. Pretty neat

class Solution {
public:
    bool isAnagram(string s, string t) {
        if (s.length() != t.length()) {
            return false;
        }
        unordered_map<char, int> sMap;
        unordered_map<char, int> tMap;

        for (int i = 0; i < s.size(); i++) {
            sMap[s[i]]++;
            tMap[t[i]]++;
        }
        
        return sMap == tMap;
    }
};