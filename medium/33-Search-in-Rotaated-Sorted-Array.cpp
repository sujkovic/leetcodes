//  Attempted in November 2023 ??? i guess i just gave up lmao

//  need to find pivot index
//  binary search for the pivot index, then binary search again for target value

//  make left and right ptr
//  while left <= right
//      if nums[middle] < nums[middle + 1]


//  4 5 6 7 0 1 2
//  7 0 
//  
//  Time Complexity - 
//  Space Complexity - 
//  Solved in 

/*
class Solution {
public:
    int search(vector<int>& nums, int target) {

    }
};
*/

//  Solved in February 2025

//  basically want to find the pivot aka biggest number
//  can use modified binary search
//  look at the left, middle, and right number
//      if middle > left
//          res = mid
//          left = mid + 1
//      if middle < left
//          right = mid - 1
//      middle == left
//          res = mid
//          break
//  return the index after

//  1 2 3 4 5
//  2 3 4 5 1
//  3 4 5 1 2
//  4 5 1 2 3
//  5 1 2 3 4

/*
class Solution {
public:
    int search(vector<int>& nums, int target) {
        int left = 0;
        int right = nums.size() - 1;
        int res = 0;

        while (left < right) {
            int mid = (left + right) / 2;
            
            if (mid > left) {
                res = mid;
                left = mid + 1;
            }
            else {
                right = mid - 1;
            }
        }

        if (res == nums.size() - 1) {
            return 0;
        }
        return res;
    }
};
*/

//  Redoing next day

//  i think you can just check if target is between left and mid or between right and mid
//  ex. 
//  4 5 6 7 0 1 2     target = 0
//  is 4 <= 0 <= 7 or is 

//  nah scratch that spent ab 5min here then watched neetcode

//  This is similar to find min in rotated sorted array
//  check if we are in the left sorted portion first
//      if we are, check if target is within it (left <= target <= right)
//          if it is, explore left
//          else explore right
//      if we arent, explore right

//  Solved in 15min
//      Submitted at 9 min but had to update code for 3 test cases
//      basically just had to beef up the inner if/else statements
//      then just change < to <= for outer
//  Time - O(logn)
//  Space - O(1)

class Solution {
    public:
        int search(vector<int>& nums, int target) {
            int left = 0;
            int right = nums.size() - 1;
    
            while (left <= right) {
                if (left == right) {
                    if (nums[left] == target) {
                        return left;
                    }
                    break;
                }
    
                int mid = (left + right) / 2;
    
                if (nums[mid] == target) {
                    return mid;
                }
    
                if (nums[left] <= nums[mid]) {  //  this must be <= for the case [0, 1] t = 1
                    if (nums[left] <= target && target < nums[mid]) {
                        right = mid - 1;
                    }
                    else {
                        left = mid + 1;
                    }
                }
                else {
                    if (nums[mid] < target && target <= nums[right]) {
                        left = mid + 1;
                    }
                    else {
                        right = mid - 1;
                    }
                }
            }
    
            return -1;
        }
    };
    
    //  I guess the logic can be broken down to:
    //  check which side (left/right) is sorted
    //      within the sorted one, check if target is in it or not
    
    //  since if we are in a sorted left half, the right may or may not be sorted, but
    //      that doesnt matter atm since if we know the left half is sorted, we just need to check
    //      if the target exists in the left half then update left/right accordingly
    //  and if we are not in a sorted left half, the right half MUST be sorted
    //      so do the same logic for the left half ^ check if target exists in right half