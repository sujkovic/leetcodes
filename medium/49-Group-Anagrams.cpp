//  create hashmap of string : vec<string> 
//  loop thru strs, at every str in strs, sort it, pushing it to map[sortedStr]
//  loop through hashmap adding the strings at each unique sorted string to a vec in res vec

//  Let n = strs size, m = max size of string in strs
//  Time - O(n * mlogm)
//      loop thru strs, sort each string
//  Space - O(n * m)
//      hashmap of n strings of size m

//  Solved in 3 minutes 

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> map;
        vector<vector<string>> res;
        
        for (int i = 0; i < strs.size(); i++) {
            string cur = strs[i];
            sort(cur.begin(), cur.end());
            map[cur].push_back(strs[i]);
        }

        for (auto element : map) {
            res.push_back(element.second);
        }

        return res;
    }
};