//  first thought is just dfs it with either include or dont include cur
//  everytime sum is equal, increment global res var
//  memoize with the index? not sure yet

//   im so stupid i just realized its CONTIGIOUS gotta redo this
//  Spent 6 minutes on this

//  ok scratch all that,
//  do a double for loop where first is i = 0 and second is j = i
//  calculate the sum of each contiguous subarray and increment res if equal

//  Solved this in 3 minutes once i realized its contiguous lol

//  Time - O(n^2)
//  Space - O(1)

/*
class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int res = 0;
        
        for (int i = 0; i < nums.size(); i++) {
            int curRes = 0;

            for (int j = i; j < nums.size(); j++) {
                curRes += nums[j];

                if (curRes == k) {
                    res++;
                }
            }

        }

        return res;
    }
};
*/


//  Can be optimmized with prefix sum, gonna try to figure it out on my own

//  ex arr 
//  1 2 3 4 5 6
//  prefix sums
//  1 3 6 10 15 21
//  
//  so if we want sum from i = 1 to i = 4
//  its just sum[4] - sum[1 - 1]

//  ok watched the neetcode vid that isnt exactly it cause thats still n^2

//  its sorta like a two sum trick where youre checking if curSum - k is in a hashmap
//  so you loop thru the nums array
//      add cur num to sum
//      if curSum - k is in the map
//          increment result by its value
//      increment the count of map[curSum - k]

//  ^ only thing thats wrong is last line, its map[curSum]
//      bc curSum - k is just for checking if theres a solution given our curSum

//  ex
//  1  2  1  2  1      k = 3
//  curSum
//  1  3  4  6  7

//  at every iteration
//      if curSum - k is in the map, add its count to res
//      increment map at curSum

//  ngl the map[0] = 1 is still throwing me off a little, would have never came up with that
//  ig it makes sense for when you have a duplicate 


//  Time - O(n)
//  Space - O(n)

//  Solved in 10 minutes after like 3 watches of neetcode vid


class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int, int> map;
        map[0] = 1;
        int res = 0;
        int sum = 0;

        for (int i = 0; i < nums.size(); i++) {
            sum += nums[i];
            if (map.find(sum - k) != map.end()) {
                res += map[sum - k];
            }

            map[sum]++;
        }

        return res;
    }
};