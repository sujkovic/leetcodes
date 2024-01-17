//  make map and set
//  loop thru arr
//      map[num]++
//  loop thru map
//      add each freq to set
//      if we find a dup, return false
//  return true

//  Time - O(n)
//  Space - O(n)

//  Solved in 5 minutes

class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        unordered_set<int> set;
        unordered_map<int, int> map;

        for (int i = 0; i < arr.size(); i++) {
            map[arr[i]]++;
        }

        for (auto &num : map) {
            if (set.find(num.second) == set.end()) {
                set.insert(num.second);
            }
            else {
                return false;
            }
        }

        return true;
    }
};