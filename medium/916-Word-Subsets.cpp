//  could make a hashmap for each word
//  then loop through the words in words1
//      then loop through all the words in words2, comparing their maps to words1s map
//      if all maps equal, the word is valid

//  Finished in 28 min, TLE
//      This is probably way overcomplicated
//      Also had syntax errors in that last area of the code with indexing cause its a mess
//  Time - O((n * p)  + (n * m * o))
//      n = words1.size, m = words2.size, o = longest word in word 2, p = longest word in word 1
//  Space - O((m * o) + (n * p))

/*
class Solution {
public:
    vector<string> wordSubsets(vector<string>& words1, vector<string>& words2) {
        vector<string> res;
        vector<unordered_map<char, int>> map1;
        vector<unordered_map<char, int>> map2;

        for (int i = 0; i < words1.size(); i++) {
            //  get map of cur word
            unordered_map<char, int> map;

            for (int j = 0; j < words1[i].length(); j++) {
                map[words1[i][j]]++;
            }

            map1.push_back(map);
        }

        for (int i = 0; i < words2.size(); i++) {
            unordered_map<char, int> map;

            for (int j = 0; j < words2[i].length(); j++) {
                map[words2[i][j]]++;
            }

            map2.push_back(map);
        }

        for (int i = 0; i < map1.size(); i++) {
            bool isUniversal = true;

            for (int j = 0; j < map2.size(); j++) {
                bool isSubset = true;

                for (auto it = map2[j].begin(); it != map2[j].end(); it++) {
                    if (map1[i].find(it->first) == map1[i].end() || map1[i][it->first] < it->second) {
                        isSubset = false;
                        break;
                    }
                }

                if (!isSubset) {
                    isUniversal = false;
                }
            }

            if (isUniversal) {
                res.push_back(words1[i]);
            }
        }

        return res;
    }
};
*/

//  dang watched the neetcode vid and all you have to do is combine all of words2 into one hashmap
//  did not think of that

//  Solved in 12 min
//      Thought i was done in 5min, spent 5min debugging cluelessly, asked chatgpt what was wrong
//      and realized i had to get the MAXIMUM count of a char from each word, and use that value in map2
//      i was just summing all the values up. i guess i did not really understand the neetocde solution
//      now i do ig lol
//  Time - O((m * o) + (n * max(o, p)))
//  Space - O(n * o * p)

class Solution {
public:
    vector<string> wordSubsets(vector<string>& words1, vector<string>& words2) {
        vector<string> res;
        unordered_map<char, int> map2;

        //  build map for words2
        for (int i = 0; i < words2.size(); i++) {
            unordered_map<char, int> curWord;
            for (int j = 0; j < words2[i].length(); j++) {
                curWord[words2[i][j]]++;
            }

            //  Take the highest frequency of each character from each word and use that as map2[char]
            for (auto it = curWord.begin(); it != curWord.end(); it++) {
                if (map2.find(it->first) == map2.end()) {
                    map2[it->first] = it->second;
                }
                else {
                    map2[it->first] = max(map2[it->first], it->second);
                }
            }
        }

        //  Go through words1
        for (int i = 0; i < words1.size(); i++) {
            //  Build map for current word in words1
            unordered_map<char, int> map1;

            for (int j = 0; j < words1[i].size(); j++) {
                map1[words1[i][j]]++;
            }

            //  Compare map1 to map2, adding to result if map2 is a subset of map1
            bool isSubset = true;
            
            for (auto it = map2.begin(); it != map2.end(); it++) {
                if (map1.find(it->first) == map1.end() || map1[it->first] < it->second) {
                    isSubset = false;
                    break;
                }
            }

            if (isSubset) {
                res.push_back(words1[i]);
            }
        }

        return res;
    }
};