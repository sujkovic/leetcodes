//  make two hashmaps for the frequencies of each char in each string
//  loop thru s, checking the differences between each character in s with that char in t
//      if it appears in t less than in s, add the difference to res
//  return res

//  Time - O(n) - loop thru string of size n
//  Space - O(1) - hashmap to keep track of chars in the strings, max size 26 bc lowercase only

//  Solved in 18 minutes bc its 1 am and im falling asleep, this is too easy for medium tbh
//      plus another 2 minutes to change hashmap to vector

class Solution {
public:
    int minSteps(string s, string t) {
        vector<int> sMap(26, 0);
        vector<int> tMap(26, 0);
        int sameCount = 0;

        for (int i = 0; i < s.length(); i++) {
            sMap[s[i] - 'a']++;
            tMap[t[i] - 'a']++;
        }

        for (int i = 0; i < sMap.size(); i++) {
            if (sMap[i] > tMap[i]) {
                sameCount += sMap[i] - tMap[i];
            }
        }

        return sameCount;
    }
};