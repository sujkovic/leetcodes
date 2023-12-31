//  keep a hashmap of char : frequency
//  iterate through words and the strings in it, updating map
//  loop through map, making sure for each char
//  frequency % (num total chars in words) == 0

//  Time - O(n * m) where n is words.size and m is the longest string in words
//      Iterate through words once then hashmap of size max 26 
//  Space - O(1)
//      hashmap size will never exceed 26 since it can only have lowercase english letters

//  Solved in idk way too long, spent forever figuring out the false conditions at the end

class Solution {
public:
    bool makeEqual(vector<string>& words) {
        unordered_map<char, int> map;
        if (words.size() == 1) {
            return true;
        }

        for (int i = 0; i < words.size(); i++) {
            for (int j = 0; j < words[i].size(); j++) {
                map[words[i][j]]++;
            }
        }
        
        for (auto curChar : map) {
            if (words.size() % curChar.second != 0 && curChar.second % words.size() != 0) {
                return false;
            }
            if (curChar.second < words.size()) {
                return false;
            }
        }

        return true;
    }
};