//  theres gotta be some sort of pattern / math with # of each character or smtn like that
//  ex.
//  annabelle, k = 2
//  a = 2
//  b = 1
//  e = 2
//  l = 2
//  n = 2

//  so even # seems to be the easy case, can always make anagram with that
//  maybe its # of odd characters and its relation to k
//  ex.
//  leetcode, k = 3
//  c = 1
//  d = 1
//  e = 3
//  l = 1
//  o = 1

//  so here everything is odd and it doesnt work
//  but then in the word true its the same but it works
//  ex leetcodd k = 3
//  false
//  leeetcodd k = 3
//  false
//  leettcodd k = 3
//  true
//  c = 1
//  d = 2
//  e = 2
//  l = 1
//  o = 1
//  t = 2
//  ok i think the rule is just # of odd characters must be <= # of even characters
//  7 min 45
//  ok coded it out and forgot about k

//  leettcodd k = 2
//  true
//  c = 1
//  d = 2
//  e = 2
//  l = 1
//  o = 1
//  t = 2

//  ok i was close it was # of odd characters <= k

//  Solved in 14 min
//  Time - O(n)
//  Space - O(1)
//      since max size of hashmap is 26 (alphabet)

class Solution {
public:
    bool canConstruct(string s, int k) {
        unordered_map<char, int> freq;

        for (int i = 0; i < s.length(); i++) {
            freq[s[i]]++;
        }

        int numOdds = 0;

        for (auto it = freq.begin(); it != freq.end(); it++) {
            if (it->second % 2 == 1) {
                numOdds++;
            }
        }

        if (numOdds <= k && s.length() >= k) {
            return true;
        }
        return false;
    }
};