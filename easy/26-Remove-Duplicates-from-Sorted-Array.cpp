#include <stdlib.h>
using namespace std;
//  Create new vector for unique vals, call it vec
//  push nums[0] to vec
//  loop through nums, starting at index 1
//      if nums[i] != nums[i - 1], push it to vec, else continue
//  set the first k values of nums to the values of vec from 0 to vec.size()
//  return vec.size()

//  let n = nums.size(), k = # unique vals
//  Time Complexity - O(n), looping through array of size n and array of size k
//  Space Complexity - O(n), worst case every element is unique
//  Solved in 7 minutes

//  update you can optimize space complexity to O(1) by using two pointer

class Solution
{
public:
    int removeDuplicates(vector<int> &nums)
    {
        int ptr = 1;
        for (int i = 1; i < nums.size(); i++)
        {
            if (nums[i - 1] != nums[i])
            {
                nums[ptr] = nums[i];
                ptr++;
            }
        }
        return ptr;
    }
};