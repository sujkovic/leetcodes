//  i think this is literally just get the count of every character, and if its over 2, 
//      if odd, make it 1, if even, make it 2
//  then sum all char counts

//  Solved in 7 min
//      compiled/accepted on 1st try
//      After solving yesterdays daily theres no way both of these should be mediums 
//  Time - O(n)
//  Space - O(1)

class Solution {
public:
    int minimumLength(string s) {
        unordered_map<char, int> freq;
        int minLength = 0;

        for (int i = 0; i < s.length(); i++) {
            freq[s[i]]++;
        }

        for (auto it = freq.begin(); it != freq.end(); it++) {
            if (it->second >= 3) {
                it->second = (it->second % 2 == 0 ? 2 : 1);
            }
            minLength += it->second;
        }

        return minLength;
    }
};