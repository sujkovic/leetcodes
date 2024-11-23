//  1 2 3 1
//  f f t f

//  1 2 1 3 5 6 4
//  f t f f f t f

//
//
// 6                   .
// 5               .
// 4                     .
// 3            .
// 2      .
// 1   .     . 
//     0  1  2  3  4  5  6   <- index in array
//  yeah i dont think this helped much lmao


//  only thing i can think of for logn is binary search but the input isnt sorted
//  maybe we could try just doing a binary search on the array and looking for 
//  the max val around the middle for our condition on going left/right

//  LMAO BRUH THAT WORKED 
//  i literally got to 10 min and figured theres no way my idea is right let me check discussion
//  first thing i see is compare nums[mid] and nums[mid + 1]
//  thats wild i still dont really understand why so im gonna watch the neetcode vid

//  Solved in 11 min
//  Time - O(n)
//  Space - O(1)

class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int left = 0;
        int right = nums.size() - 1;

        while (left <= right) {
            int middle = (left + right) / 2;
            if (middle + 1 == nums.size()) {
                break;
            }

            if (nums[middle] < nums[middle + 1]) {
                left = middle + 1;
            }
            else {
                right = middle - 1;
            }
        }
        return left;
    }
};


//  Ok kinda makes sense
//  So since we're given that nums[i] and nums[i + 1] will never be equal,
//  we know when we look at the middle in our bianry search, it will not equal
//  its left/right neighbors
//  so lets say we look at the smaller neighbor
//      if that entire side is then monotonically decreasing
//          we wont have a peak element
//      else
//          we MIGHT have a peak element if another one goes up, but not guaranteed
//  now look at the larger neighbor
//      if that entire side is then onotonically decreasing
//          that larger neighbor itself will be the peak element
//      else lets say the whole thing increases or zigzags
//          we are still guaranteed there will be a peak element
//              ex. zigzag there will obv be one
//              ex all increasing, the last element will be one since arr[arrsize] = -1

//  this is pretty cool im surprised i somewhat got to the answer 