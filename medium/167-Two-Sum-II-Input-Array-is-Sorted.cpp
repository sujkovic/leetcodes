//  Can just two pointer it
//  2, 7, 11, 15
//  l         r     -> sum is 17, 17 > 9 so go smaller
//  l     r            13 > 9
//  l  r               9 = 9, return

//  Solved in 4 min
//  Time - O(n)
//  Space - O(1)

class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int left = 0;
        int right = numbers.size() - 1;

        while (left < right) {
            int sum = numbers[left] + numbers[right];

            if (sum < target) {
                left++;
            }
            else if (sum > target) {
                right--;
            }
            else {
                return {left + 1, right + 1};
            }
        }

        return {-1, -1};
    }
};