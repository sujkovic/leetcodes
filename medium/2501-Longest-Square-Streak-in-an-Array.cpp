//  2, 3, 4, 6, 8, 16

//  sort the array, then do a double for loop, in the first loop keep track of the cur num to be squared
//  longestStreak = 0
//  for i in nums
//      curNum = nums[i]
//      curStreak = 1
//      for j = i + 1 in nums
//          if nums[j] == cur^2
//              cur = nums[j]
//              curStreak++
//              update longesstreak
//  if longest streak >= 2, return it, else return -1

//  Finished in 15 min, TLE

/*
class Solution {
public:
    int longestSquareStreak(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int longestStreak = 1;

        for (int i = 0; i < nums.size(); i++) {
            long long curNum = nums[i];
            int curStreak = 1;
            for (int j = i + 1; j < nums.size(); j++) {
                long long curNumSquared = curNum * curNum;
                if (nums[j] == curNumSquared) {
                    curNum = nums[j];
                    curStreak++;
                    longestStreak = max(longestStreak, curStreak);
                }
            }
        }

        if (longestStreak > 1) {
            return longestStreak;
        }
        return -1;
    }
};
*/

//  Checked solutions, looks like you just need to use a map to store steaks to make it O(n)
//      (didnt look at any code just looked for hints and then tried again an hour later)
//  2, 3, 4, 6, 8, 16
//  map[2] = 1
//  map[3] = 1
//  map[4] = 2
//  map[6] = 1
//  map[8] = 1
//  map[16] = 3

//  so do one loop, at each iteration, check if sqrt(cur num) is in the map, if it is, insert the current
//      num into the map with the value of the map at its sqrt, + 1. and update the max

//  Solved in 15 min

class Solution
{
public:
    int longestSquareStreak(vector<int> &nums)
    {
        unordered_map<float, int> map;
        sort(nums.begin(), nums.end());
        int longestStreak = -1;

        for (int i = 0; i < nums.size(); i++)
        {
            if (map.find(sqrt(nums[i])) != map.end())
            {
                map[nums[i]] = map[sqrt(nums[i])] + 1;
                longestStreak = max(longestStreak, map[nums[i]]);
            }
            else
            {
                map[nums[i]] = 1;
            }
        }

        return longestStreak;
    }
};