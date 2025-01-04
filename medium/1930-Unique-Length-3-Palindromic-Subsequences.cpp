//  since its only length 3, we dont need to do recursive / dp i think
//  should suffice to just find 2 of the same letter, and pick all combos of letters
//  between them such that there are no duplicate length 3 palindromes

//  Finished in 9 min, TLE
//  Time - O(n^3)
//  Space - O(n)

/*
class Solution {
public:
    int countPalindromicSubsequence(string s) {
        set<string> palindromes;
        int res = 0;

        for (int i = 0; i < s.length(); i++) {
            for (int j = i + 1; j < s.length(); j++) {
                if (s[i] == s[j]) {
                    for (int k = i + 1; k < j; k++) {
                        string curPalindrome = string(1, s[i]) + s[k] + s[j];
                        if (palindromes.find(curPalindrome) == palindromes.end()) {
                            res++;
                            palindromes.insert(curPalindrome);
                        }
                    }
                }
            }
        }

        return res;
    }
};
*/

//  find first and last occurence of each character, then find in between
//  Solved in 15 min
//  Was rushing this problem since just got to hotel and wanted to bang it out
//  before heading out so i keep the monthly streak
//  Looked at solutions for a sec just to get the hint of "find first/last occur of each char"
//  Had a bunch of errors with converting chars to ints and how to index it since i was rushing
//  Time - O(n)
//      26 * n = n
//  Space - O(n)

class Solution {
public:
    int countPalindromicSubsequence(string s) {
        unordered_map<char, vector<int>> chars;
        int res = 0;
        char charIt = 'a';

        for (char i = 'a'; i <= 'z'; i++) {
            chars[i] = {-1, -1};
        }

        for (int i = 0; i < s.length(); i++) {
            if (chars[s[i]][0] == -1) {
                chars[s[i]][0] = i;
            }
            else {
                chars[s[i]][1] = i;
            }
        }

        for (auto it = chars.begin(); it != chars.end(); it++) {
            if (it->second[0] == -1 || it->second[1] == -1) {
                continue;
            }

            set<char> uniqueChars;
            for (int j = it->second[0] + 1; j < it->second[1]; j++) {
                if (uniqueChars.find(s[j]) == uniqueChars.end()) {
                    res++;
                    uniqueChars.insert(s[j]);
                }
            }
        }
        
        return res;
    }
};