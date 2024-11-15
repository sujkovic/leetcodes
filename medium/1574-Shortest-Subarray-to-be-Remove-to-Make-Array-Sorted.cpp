//  1, 2, 3, 10, 4, 2, 3, 5
//  1  2  2  2   2  2  3  5    <- get cur min starting from right

//  5, 4, 3, 2, 1
//  1  1  1  1  1

//  1 2 3
//  1 2 3

//  so precompute the minimums by iterating backwards from end of arr
//  then loop thorugh arr,
//      if arr[i] > mins[i]
//          res++

//  1, 2, 3, 10, 0, 7, 8, 9      <- doesnt work for this case might need new approach
/*
class Solution {
public:
    int findLengthOfShortestSubarray(vector<int>& arr) {
        vector<int> minimums(arr.size(), 0);
        int curMin = arr[arr.size() - 1];
        int res = 0;

        for (int i = arr.size() - 1; i >= 0; i--) {
            curMin = min(curMin, arr[i]);
            minimums[i] = curMin;
        }

        for (int i = 0; i < arr.size(); i++) {
            cout << minimums[i] << " ";
            if (arr[i] > minimums[i]) {
                res++;
            }
        }

        return res;
    }
};
*/


//  Looked at hint for this but since we want the longest nondecreasing subarray, we then want to
//  look for the longest nonincreasing subarray

//  at this point 25 min

/*
class Solution {
public:
    int findLengthOfShortestSubarray(vector<int>& arr) {
        int count = 1;
        int res = 1;

        for (int i = 1; i < arr.size(); i++) {
            if (arr[i] < arr[i - 1]) {
                count++;
                res = max(res, count);
            }
            else {
                count = 1;
            }
        }

        if (res == arr.size()) {
            return res - 1;
        }
        if (res == 1) {
            return 0;
        }

        return res;
    }
};
*/

//  Watched neetcode vid half an hour ago and reattempting
//  so basically need to account for three cases,
//      find the longest nondecreasing subarray from the beginning
//      find the longest nonincreasing subarray from the end
//      use two pointer to find the smallest nondecreasing subarray in the middle of those two ^

//  1, 2, 3, 10, 4, 1, 2, 3
//  L        R               case 1 -> size 4, so would need to remove arr of size 8 - 4 = 4
//  1, 2, 3, 10, 4, 1, 2, 3
//                  L     R  case 2 -> size 3, remove arr of size 8 - 3 = 5
//  1, 2, 3, 10, 4, 1, 2, 3
//  L                     R
//  L                  R
//  L               R
//     L               R
//        L               R  case 3 -> 6
//  so return the minimum of the 3 cases, case 2      


//  1, 2, 3, 10, 9, 3, 4
//  L        R            case 1, need to remove arr size 3
//  1, 2, 3, 10, 9, 3, 4  
//                  L  R  case 2, need to remove arr size 5
//  1, 2, 3, 10, 9, 3, 4
//  l                  r  1 < 4, l++
//     l               r  2 < 4, l++
//        l            r  3 < 4, l++
//        l         r     10 < 4, l-- and r--


//  actually scratch all that im making my own solution
//  so the first two cases give you the largest element in the first nondecreasing
//  subarray and its index, and the second case gives you the smallest element
//  in the first nonincreasing subarray from the right and its index
//  so, we can START two pointer from those 2 indices, and try to find the smallest
//  chunk of the middle to take out, so that the array from case 1 + from case 2
//  is sorted

//  1, 2, 3, 10, 9, 3, 4
//           l      r     l > r, not valid
//        l         r     -> arr to be removed size 2
//  1, 2, 3, 10, 9, 3, 4
//           l         r
//  how do we know which way to explore tho
//  could just try every combo?
//  or go all the way one way or the other
//  ok this might not work..


//  alright checked the top solution and i just have to modify the algo a bit
//  so instead of starting from the case 1 high and case 2 low, we want to start
//  the left at 0, and the right at case 2 low
//  then we keep incrementing the left until its greater than the element at right
//  in that case, we want to increment right to broaden our window
//  and then i think if at any point the left decrements, we need to end there
//  so i guess our loop case would be while left < case 1 high

//  1, 2, 3, 4, 3, 2, 3, 4, 5, 6, 5, 3, 5, 6, 7
//  l                                r
//     l                             r
//        l                          r
//           l                         r      <- length of this range is result
//             break, nums[l + 1] < nums[l]


//  Solved, total of 1 hour 40 min spent just sitting on this screen
//  this problem was kind of insane
//  Time O(n) Space O(1)

class Solution {
public:
    int findLengthOfShortestSubarray(vector<int>& arr) {
        int leftMax = arr[0];
        int rightMin = arr[arr.size() - 1];
        int leftMaxIndex = 0;
        int rightMinIndex = arr.size() - 1;

        for (int i = 0; i < arr.size(); i++) {
            if (arr[i] >= leftMax) {
                leftMax = arr[i];
                leftMaxIndex = i;
            }
            else {
                break;
            }
        }

        //  array is already sorted
        if (leftMaxIndex == arr.size() - 1) {
            return 0;
        }

        for (int i = arr.size() - 1; i >= 0; i--) {
            if (arr[i] <= rightMin) {
                rightMin = arr[i];
                rightMinIndex = i;
            }
            else {
                break;
            }
        }

        int left = 0;
        int right = rightMinIndex;

        int leftRes = arr.size() - leftMaxIndex - 1;
        int rightRes = rightMinIndex;
        int midRes = arr.size();
        //  ^ want to return the smallest of these 3

        while (left <= leftMaxIndex && right < arr.size()) {
            if (arr[left] <= arr[right]) {
                left++;
                midRes = min(midRes, right - left);
            }
            else {
                right++;
            }
            
        }

        return min(midRes, min(leftRes, rightRes));
    }
};