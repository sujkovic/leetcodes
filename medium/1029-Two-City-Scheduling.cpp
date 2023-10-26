//  Find the difference between aCosti and bCosti for each i
//  make new vector called difs vector<pair<int, pair<int, int>>>
//  loop through costs
//      difs.push_back({abs(costs[i][0] - costs[i][1]), {costs[i][0], costs[i][1]}})
//  sort difs
//  iterate through difs
//      add max(difs[i].second.first, difs[i].second.second) to res
//  return res


//  watched vid, my answer was close but we dont take the absolute value, and at the end
//  we literally just add the first half to city a and second half to city b

//  Time Complexity - 
//  Space Complexity -
//  Solved in  

class Solution {
public:
    int twoCitySchedCost(vector<vector<int>>& costs) {
        vector<pair<int, pair<int, int>>>; difs;

        for (int i = 0; i < costs.size(); i++) {
            pair<int, int> cur = {costs[i][0], costs[i][1]};
            difs.push_back({abs(cur.first - cur.second), {cur.first, cur.second}});
        }

        sort(difs.begin(), difs.end());
        int res = 0;

        for (int i = 0; i < difs.size(); i++) {
            int += max(difs[i].second.first, difs[i].second.second);
        }
        return res;
    }
};