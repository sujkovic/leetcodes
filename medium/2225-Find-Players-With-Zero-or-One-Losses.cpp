//  make a set of all existing players, and a hashmap of each players loss history (that have one)
//  just iterate through the set and check for players with 0 losses and with 1 loss
//  push those two lists into a vec of vecs and return it

//  Time - O(nlogn) - loop iterations are n, then sorting the result vecs is nlogn at worst
//  Space - O(n) - set and hashmap worst case size n

//  Solved in 6 minutes

class Solution {
public:
    vector<vector<int>> findWinners(vector<vector<int>>& matches) {
        unordered_set<int> players;
        unordered_map<int, int> losses;
        vector<int> ones;
        vector<int> zeroes;

        for (int i = 0; i < matches.size(); i++) {
            players.insert(matches[i][0]);
            players.insert(matches[i][1]);
            losses[matches[i][1]]++;
        }

        for (auto player: players) {
            if (losses.find(player) == losses.end()) {
                zeroes.push_back(player);
            }
            else if (losses[player] == 1) {
                ones.push_back(player);
            }
        }

        sort(ones.begin(), ones.end());
        sort(zeroes.begin(), zeroes.end());
        return {zeroes, ones};
    }
};