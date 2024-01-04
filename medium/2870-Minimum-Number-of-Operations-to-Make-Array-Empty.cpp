//  this part i had to look at neetcode vid for
//  Basically all you need to do is add freq / 3 if freq % 3 == 0, and (freq / 3) + 1 otherwise
//  Any number that isnt divisible by 3 has either 1 or 2 left over
//      if it has one left over
//          you just turn one of the 3s into 2 2s. which is the same thing as just doing 3 + 1
//      if it has two left over
//          you just add another 2 
//  this is dope

//  Pseudocode
//  make hashmapf of frequency of each number
//  loop through hashmap, for each unique number
//      ^ follow the first blob of text
//  return result

class Solution {
public:
    int minOperations(vector<int>& nums) {
        unordered_map<int, int> freq;
        int res = 0;

        for (int i = 0; i < nums.size(); i++) {
            freq[nums[i]]++;
        }

        for (auto num : freq) {
            if (num.second == 1) {
                return -1;
            }
            if (num.second % 3 == 0) {
                res += num.second / 3;
            }
            else {
                res += (num.second / 3) + 1;                
            }
        }

        return res;
    }
};