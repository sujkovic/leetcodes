//  Can just use hashmap of num counts
//  return most freq element

//  Time - O(n)
//  Space - O(n)
//  Solved in 3 minutes
/*
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        unordered_map<int, int> map;
        int resultCount = 0;
        int resultNum = nums[0];

        for (int i = 0; i < nums.size(); i++) {
            map[nums[i]]++;
            if (map[nums[i]] > resultCount) {
                resultCount = map[nums[i]];
                resultNum = nums[i];
            }
        }

        return resultNum;
    }
};
*/


//  had to look this one up, using the meyer voting algorithm
//  from my understanding, keep a curNum and curCount variable, initalized to nums[0]
//  at each iteration
//      if nums[i] == curnum
//          increment curcount
//      else
//          decrement curcount
//          if curcount = 0
//              set the curNum to nums[i]

//  Time - O(n)
//  Space - O(1)

//  Solved in 5 minutes (+ like 3 minutes to look at the the utexas page on the algo)

class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int curNum = nums[0];
        int count = 1;

        for (int i = 1; i < nums.size(); i++) {
            if (nums[i] == curNum) {
                count++;
            }
            else {
                count--;
                if (count == 0) {
                    curNum = nums[i];
                    count++;
                }
            }
        }

        return curNum;
    }
};