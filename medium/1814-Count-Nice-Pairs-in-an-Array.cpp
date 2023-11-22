//  make a set to keep track of # of pairs found so far
//  make a second vector 'rev' of every number in reverse order
//  do a double for loop basically comparing everything in nums to everything in rev
//      if nums[i] + rev[j] = nums[j] + rev[i]
//          add pair to set 
//              (use format <smallernum, biggernum> to avoid dups)
//  return set.size()

//  Time Complexity - O(n^2)
//      Double for loop for vec of size n
//  Space Complexity - O(n)
//      Using extra vec to store reverses

//  damn worked on first try but time limit exceeded (took 12 minutes)

/*
class Solution {
public:
    int countNicePairs(vector<int>& nums) {
        set<pair<int, int>> set;
        vector<int> rev;
        for (int i = 0; i < nums.size(); i++) {
            string curStr = to_string(nums[i]);
            reverse(curStr.begin(), curStr.end());
            rev.push_back(stoi(curStr));
        }

        for (int i = 0; i < nums.size(); i++) {
            for (int j = i + 1; j < nums.size(); j++) {
                if (nums[i] + rev[j] == nums[j] + rev[i]) {
                    set.insert({min(nums[i], nums[j]), max(nums[i], nums[j])});
                }
            }
        }

        return set.size();
    }
};
*/

//  optimized soln
//  rewrite equation as nums[i] - rev[i] = nums[j] - rev[j]
//  

class Solution {
public:
    int countNicePairs(vector<int>& nums) {
        unordered_map<int, long> map;
        for (int i = 0; i < nums.size(); i++) {
            string curStr = to_string(nums[i]);
            reverse(curStr.begin(), curStr.end());
            int rev = stoi(curStr);
            map[nums[i] - rev]++;
        }
        long count = 0;
        for (auto element : map) {
            count = (count + (element.second * (element.second + 1)) / 2) % (long)(pow(10, 9) + 7);
            //  this line took me forever to understand but its the formula n(n - 1) / 2
            // that equation = the summation of integers from 1 to n
            //  still do not really get it tbh
        }
        return count % (long)(pow(10, 9) + 7);
    }
};