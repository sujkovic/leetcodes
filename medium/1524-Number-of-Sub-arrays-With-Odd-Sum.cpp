//  the sums dont really matter, could just use true/false bools
//  ig first thought is double for loop
//  for i = 0 to n - 1
//      isEven = nums[i] % 2 == 0
//      for j = 0 to n - 1
//          if !isEven and cur num is even orrrr if isEven and cur num is odd
//              res++

//  Finished in 7 min, TLE
//  Time - O(n^2)
//  Space - O(1)

/*
class Solution {
public:
    int numOfSubarrays(vector<int>& arr) {
        int res = 0;

        for (int i = 0; i < arr.size(); i++) {
            bool isEven = true;
            for (int j = i; j < arr.size(); j++) {
                if ((isEven && arr[j] % 2 == 1) || (!isEven && arr[j] % 2 == 0)) {
                    res++;
                    isEven = false;
                }
                else {
                    isEven = true;
                }
                
            }
        }

        return res;
    }
};
*/
//  Can probably use some sort of prefix sum or smtn

//  1 3 5
//  1 4 9

//  i = 0 -> cur num works
//  i = 1 -> cur num works, prefix sum at cur doesnt work
//  i got no idea

//  regular 1 2 3 4  5  6  7
//  prefix  1 3 6 10 15 21 28

//  Had to watch the neetcode video here
//  Basically we want to keep track of 4 variables:
//      current sum
//      res 
//      # of subarrays so far with even sum
//      # of subarrays so far with odd sum

//  ex. 
//  index  .  0  1  2  3  4  5  6
//  array     1  2  3  4  5  6  7
//  sum    0  1  3  6  10
//  evens  0  0  0  1  2
//  odds   0  1  2  2  2
//  res    0  1  2  4  6

//  at i=0, our sum is odd, so add 1 + the amount of evens
//  at i=1, our sum is odd, so add 1 + # of evens
//  at i=2, our sum is even, add the # of odds
//  ok this actually works

//  Solved in 18 min
//  Time - O(n)
//  Space - O(1)

class Solution {
    public:
        int numOfSubarrays(vector<int>& arr) {
            int MOD = (pow(10, 9) + 7);
            int sum = 0;
            int evens = 0;
            int odds = 0;
            int res = 0;
    
            for (int i = 0; i < arr.size(); i++) {
                sum += arr[i];
    
                if (sum % 2 == 0) {
                    res = (res + odds) % MOD;
                    evens++;
                }
                else {
                    res = (res + evens + 1) % MOD;
                    odds++;
                }
            }
    
            return res;
        }
    };