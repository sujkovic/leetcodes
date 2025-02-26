//  Make a set of (digit sum, number)
//  Make a max heap of digit sums (nevermind dont need this)
//  loop through nums
//      if cur digit sum is not in the set, insert it and the cur num as a pair
//      else if it is in the set
//          update res to max of res and curNum + the value at set[digitsum].second
//          replace the num in the set with the cur num if its bigger

//  scratching set for map since c++ doesnt support pair hashing i forgot
//      (and cause i realized i shouldve been using a map lmao whoops)

//  also just realized this might not work, might need a sorted list of every digit sum
//  nvm greedy works in this case

//  Solved in 11 min
//  Time - O(n)
//  Space - O(1)
//      Since nums can only be up to 9 digits, max digit size is 9 * 9 = 81 (+1 for zero)
//      so hashmap is constant and the time to convert a num to digit sum is constant

class Solution {
    public:
        /*
        int getDigitSum(int num) {
            string numStr = to_string(num);
            int res = 0;
    
            for (int i = 0; i < numStr.length(); i++) {
                res += (numStr[i] - '0');
            }
            
            return res;
        }
        */
        int getDigitSum(int num) {
            int res = 0;
    
            while (num) {
                res += num % 10;
                num = num / 10;
            }
            
            return res;
        }
        int maximumSum(vector<int>& nums) {
            unordered_map<int, int> map;
            int res = -1;
    
            for (int i = 0; i < nums.size(); i++) {
                int digitSum = getDigitSum(nums[i]);
                if (map.find(digitSum) == map.end()) {
                    map[digitSum] = nums[i];
                }
                else {
                    res = max(res, map[digitSum] + nums[i]);
                    map[digitSum] = max(map[digitSum], nums[i]);
                }
            }
    
            return res;
        }
    };