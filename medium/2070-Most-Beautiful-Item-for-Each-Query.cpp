//  Immediate thought is sort the items array by price and binary search every time for
//  the index of the max price we can currently reach
//  and then also have a prefix sum table for the most beautiful item until that point

//  ok spent 40 min and this is not working gonna watch neetcode
/*
class Solution {
public:
    int binarySearch(vector<vector<int>> &items, int &target) {
        int left = 0;
        int right = items.size() - 1;
        int res = -1;

        while (left <= right) {
            int middle = (left + right) / 2;
            cout << middle << " ";

            if (target < items[middle][0]) {
                right = middle - 1;
            }
            else if (target > items[middle][0]) {
                left = middle + 1;
            }
            else {
                res = middle;
                break;
            }
        }

        if (res == -1) {
            return -1;
        }
        while (res < items.size() && items[res][0] == target) {
            res++;
        }
        res--;

        return res;
    }
    vector<int> maximumBeauty(vector<vector<int>>& items, vector<int>& queries) {
        vector<int> prefixSum;
        vector<int> res;

        sort(items.begin(), items.end(), [](const vector<int> &x, const vector<int> &y) {
            if (x[0] != y[0]) {
                return x[0] < y[0];
            }
            return x[1] < y[1];
        });

        for (int i = 0; i < items.size(); i++) {
            cout << items[i][0] << " " << items[i][1] << endl;
        }
        cout << "---\n";

        for (int i = 0; i < items.size(); i++) {
            if (i == 0) {
                prefixSum.push_back(items[i][1]);
            }
            else {
                prefixSum.push_back(max(prefixSum[i - 1], items[i][1]));
            }
        }

        for (int i = 0; i < queries.size(); i++) {
            int curRes = 0;
            for (int j = items.size() - 1; j >= 0; j--) {
                if (items[j][0] <= queries[i]) {
                    curRes = items[j][1];
                    break;
                }
            }
            res.push_back(curRes);

        }

        return res;
    }
};
*/

//  first array just needs to be sorted by cost
//  for the second array, we're not guaranted its sorted, so we need
//  to make it a new array of pairs to keep track of og index, then sort
//  by the query cost.
//      ^^ the query thing is why my first solution didnt work

//  for query in queries
//      while curitem price < query and were in bounds
//          update maxBeauty
//      push maxbeauty to res

//  m = items size, n = queries size
//  O(mlogm + nlogn) Time
//  O(n) Space

//  Solved in 11 min

class Solution
{
public:
    vector<int> maximumBeauty(vector<vector<int>> &items, vector<int> &queries)
    {
        int maxBeauty = 0;
        int itemsIndex = 0;
        vector<int> res(queries.size(), 0);
        vector<pair<int, int>> queries2;
        sort(items.begin(), items.end());

        for (int i = 0; i < queries.size(); i++)
        {
            queries2.push_back({queries[i], i});
        }

        sort(queries2.begin(), queries2.end());

        for (int i = 0; i < queries2.size(); i++)
        {
            while (itemsIndex < items.size() && items[itemsIndex][0] <= queries2[i].first)
            {
                maxBeauty = max(maxBeauty, items[itemsIndex][1]);
                itemsIndex++;
            }

            res[queries2[i].second] = maxBeauty;
        }

        return res;
    }
};