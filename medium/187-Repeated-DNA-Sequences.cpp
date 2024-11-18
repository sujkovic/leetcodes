//  if s length < 10, return []
//  make a hashmap of dna sequence frequencies
//  loop through s, adding every 10 letter substring to a hashmap 
//      map[curSubstr]++
//  loop through the map, adding all substrs with a count > 1 to results 
//  return results

//  Solved in 8 min
//  Time - O(n)
//      The substr is a constant length of 10 so O(n * 10) -> O(n)
//  Space - O(n)
//      Same logic as time, n strings of length 10

class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
        if (s.length() < 10) {
            return {};
        }

        unordered_map<string, int> counts;
        vector<string> res;

        for (int i = 0; i < s.length(); i++) {
            string curDna = s.substr(i, 10);
            counts[curDna]++;
        }

        for (auto it = counts.begin(); it != counts.end(); it++) {
            if (it->second > 1) {
                res.push_back(it->first);
            }
        }

        return res;
    }
};