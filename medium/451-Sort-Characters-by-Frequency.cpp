//  make a map of each char frequency
//  loop thru s, doing map[s[i]]++
//  then loop thru the hashmap, adding each key value pair to a heap
//      heap will sort the key value pairs by frequency
//  then loop thru heap, adding each char to result string, its frequency times

//  Time - O(n)
//      first loop is O(n)
//      second loop is O(logn) because we only have 26 + 26 + 10 possible values which 
//          is constant, reducing that loop down to just O(1), but we add to heap in 
//          it which is O(logn)
//      third loop is O(1) similarly
//  Space - O(1) - same logic above, constant number of possible elements

//  Solved in 12 minutes

class Solution {
public:
    string frequencySort(string s) {
        unordered_map<char, int> map;
        priority_queue<pair<int, char>> queue;
        string res = "";

        for (int i = 0; i < s.length(); i++) {
            map[s[i]]++;
        }

        for (auto pair : map) {
            queue.push({pair.second, pair.first});
        }

        while (!queue.empty()) {
            for (int i = 0; i < queue.top().first; i++) {
                res += queue.top().second;
            }
            queue.pop();
        }

        return res;
    }
};