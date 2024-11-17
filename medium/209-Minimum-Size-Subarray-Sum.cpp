//  2 3 1 2 4 3      target 7
//  L R              sum 5, right++
//  L   R            sum 6, right++
//  L     R          sum 8, update min, sum too big so make array smaller (left++)
//    L   R          sum 6, right++
//    L     R        sum 10 update min, left++
//      L   R        sum 7, update min, left++
//      L     R      sum 10, update, left++
//        L   R      sum 9, update, left++
//          L R      sum 7, update, left++
//            LR


//  left = 0, right = 0, sum = nums[0]
//  while right <= nums size
//      if left == right || sum < target
//          right++
//          sum += nums[right]
//      else if sum >= target
//          update minArray to right - left, if smaller
//          sum -= nums[left]
//          left++

//  Solved in 30 min
//  Time - O(n)
//  Space - O(1)

/*
class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int left = 0;
        int right = 0;
        int sum = 0;
        int minArray = nums.size() + 1;

        while (right < nums.size()) {
            if (left == right) {
                sum = nums[left];
            }
            if (sum < target) {
                if (right >= nums.size() - 1) {
                    break;
                }
                right++;
                sum += nums[right];
                cout << sum << endl;
            }
            else {
                minArray = min(minArray, right - left + 1);
                sum -= nums[left];
                cout << sum << endl;
                left++;
            }
        }

        if (minArray == nums.size() + 1) {
            return 0;
        }
        return minArray;
    }
};
*/

//  Redoing with cleaner code
//  instead of all the messy conditions, we can use the fact that we know right will always be incremented
//  and then within the while loop, we can have another while loop incrementing left however much is needed

//  int left = 0, right = 0, sum = 0, minArray = nums size + 1
//  while right < nums size
//      sum += nums[right]
//      while sum >= target
//          update min array
//          sum -= nums[left]
//          left++
//  return res if valid, else 0

//  Solved in 7 min
//  O(n), O(1)

class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int left = 0;
        int right = 0;
        int sum = 0;
        int minArray = nums.size() + 1;

        while (right < nums.size()) {
            sum += nums[right];

            while (sum >= target) {
                minArray = min(minArray, right - left + 1);
                sum -= nums[left];
                left++;
            }

            right++;
        }

        if (minArray == nums.size() + 1) {
            return 0;
        }

        return minArray;
    }
};