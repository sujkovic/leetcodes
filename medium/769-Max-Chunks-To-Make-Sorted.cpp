//  Looks like you want to find the smallest number in the array since thats the limitting factor
//  ex. 2 3 0 1 4
//  nope that does not work, 8 min

//  Watched the neetcode video, you can solve with prefix sum
//  since the numbers are in range 0 to n - 1, we know what the sum of the array should be at each i easily
//  basically just keep a current sum variable and if the current subarray sum (cursum) = the running sum of i, its a valid array
//  Solved in 5 min
//  Time - O(n)
//  Space - O(1)

class Solution {
public:
    int maxChunksToSorted(vector<int>& arr) {
        int targetSum = 0;
        int curSum = 0;
        int res = 0;

        for (int i = 0; i < arr.size(); i++) {
            targetSum += i;
            curSum += arr[i];

            if (targetSum == curSum) {
                res++;
            }
        }

        return res;
    }
};