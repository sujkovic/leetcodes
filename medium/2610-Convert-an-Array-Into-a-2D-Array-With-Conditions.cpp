//              First answer            //

//  sort the input
//  create a vector of vectors
//  iterate through nums
//  keep track of the # of times you've seen the current number
//      use that as the index of which row to insert it into
//  return result vector 

//  Time - O(nlogn) - sort input of size n (nlogn), then loop through it (n)
//  Space - O(1) - no new data structs (assuming sort in place)

//  Solved in 15 minutes
//      compiled and accepted solution on FIRST TRY not one syntax error or anything :D
/*
class Solution {
public:
    vector<vector<int>> findMatrix(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> res;
        int curNum = nums[0];
        int curNumCount = 1;
        res.push_back({curNum});

        for (int i = 1; i < nums.size(); i++) {
            if (nums[i] == curNum) {
                if (curNumCount >= res.size()) {
                    res.push_back({curNum});
                }
                else {
                    res[curNumCount].push_back(curNum);
                }
                curNumCount++;
            }
            else {
                curNum = nums[i];
                res[0].push_back(curNum);
                curNumCount = 1;
            }
        }

        return res;
    }
};
*/

//          Optimized           //

//  Looked at solutions and realized you can do O(n) with hashmap
//  Make hashmap of frequencies of each number
//  Loop thru input, updating hashmap
//  also find the MODE of the input array
//  create a result vector of MODE vectors
//  Loop thru input, for each num
//      push num to result[map[num] - 1]
//      map[num]--
//  return rse

//  Time - O(n) - 2 passes through array of size n, and 1 pass through map of max size n
//  Space - O(n) - worst case size of hashmap

//  Solved in 10 minutes

class Solution {
public:
    vector<vector<int>> findMatrix(vector<int>& nums) {
        vector<vector<int>> res(modeFreq, vector<int>());
        unordered_map<int, int> map;
        int modeFreq = 0;

        for (int i = 0; i < nums.size(); i++) {
            map[nums[i]]++;
        }

        for (auto num : map) {
            modeFreq = max(modeFreq, num.second);
        }

        for (int i = 0; i < nums.size(); i++) {
            int curNum = nums[i];
            map[curNum]--;
            res[map[curNum]].push_back(curNum);
        }

        return res;
    }
};