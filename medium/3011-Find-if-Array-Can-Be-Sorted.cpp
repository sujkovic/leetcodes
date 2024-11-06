//  first make another array corresponding to each nums set bits
//  ex.
//  8 4 2 30 15
//  1 1 1 4  4
//  looks like you can just iterate through nums,
//      look at the current streak of set bits, if there is one, and sort it
//  return true if the array is sorted, else false

//  1 2 3 4 5
//  1 1 2 1 2       -> sorts the first two, then does nothing to the rest

//  3 16 8 4 2
//  2 1  1 1 1     -> sorts the last 4, results in 3 2 4 8 16, false

//  Solved in 29 minutes
//  Time - O(n * nlogn)
//  Space - O(n) - creating extra arrays to sort

/*
class Solution {
public:
    int getNumSetBits(int num) {
        int numSetBits = 0;
        while (num > 0) {
            if (num % 2 == 1) {
                numSetBits++;
            }
            num = num >> 1;
        }

        return numSetBits;
    }
    bool canSortArray(vector<int>& nums) {
        vector<int> setBits;
        for (int i = 0; i < nums.size(); i++) {
            setBits.push_back(getNumSetBits(nums[i]));
        }

        int curStreak = 1;
        for (int i = 1; i <= nums.size(); i++) {
            if (i != nums.size() && setBits[i] == setBits[i - 1]) {
                curStreak++;
            }
            else {
                if (curStreak >= 2) {
                    vector<int> curSubArray;
                    for (int j = i - curStreak; j < i; j++) {
                        curSubArray.push_back(nums[j]);
                    }

                    sort(curSubArray.begin(), curSubArray.end());
                    int curSubArrayIt = 0;
                    for (int j = i - curStreak; j < i; j++) {
                        nums[j] = curSubArray[curSubArrayIt];
                        curSubArrayIt++;
                    }
                }

                curStreak = 1;
            }
        }

        for (int i = 1; i < nums.size(); i++) {
            if (nums[i] < nums[i - 1]) {
                return false;
            }
        }

        return true;
    }
};
*/

//  Optimize

//  Given a contiguous block, you cant move elements between it and another block
//  So, instead of sorting every contiguous block, find the max/min value of it
//  If the min value of the cur block > max value of prev block, we can not sort the array

//  Solved in about 8 minutes

//  Time - O(n)
//  Space - O(n)

/*
class Solution {
public:
    int getNumSetBits(int num) {
        int numSetBits = 0;
        while (num > 0) {
            if (num % 2 == 1) {
                numSetBits++;
            }
            num = num >> 1;
        }

        return numSetBits;
    }
    bool canSortArray(vector<int>& nums) {
        vector<int> setBits;
        for (int i = 0; i < nums.size(); i++) {
            setBits.push_back(getNumSetBits(nums[i]));
        }

        int curMax = nums[0];
        int curMin = nums[0];
        int prevMax = INT_MIN;

        for (int i = 1; i <= nums.size(); i++) {
            if (i != nums.size() && setBits[i] == setBits[i - 1]) {
                curMin = min(curMin, nums[i]);
                curMax = max(curMax, nums[i]);
            }
            else {
                if (curMin < prevMax) {
                    return false;
                }
                if (i == nums.size()) {
                    break;
                }

                prevMax = curMax;
                curMax = nums[i];
                curMin = nums[i];
            }
        }

        return true;
    }
};
*/

//  Can also get rid of the set bit cache and just calculate it when needed
//  I'm not really sure what the time complexity would be consider in this case
//  Im thinking O(n * log(biggest number in array))
//  so i think the trade off would be worth the O(n) -> O(1) change in space

class Solution
{
public:
    int getNumSetBits(int num)
    {
        int numSetBits = 0;
        while (num > 0)
        {
            if (num % 2 == 1)
            {
                numSetBits++;
            }
            num = num >> 1;
        }

        return numSetBits;
    }
    bool canSortArray(vector<int> &nums)
    {
        int curMax = nums[0];
        int curMin = nums[0];
        int prevMax = INT_MIN;

        for (int i = 1; i <= nums.size(); i++)
        {
            if (i != nums.size() && getNumSetBits(nums[i]) == getNumSetBits(nums[i - 1]))
            {
                curMin = min(curMin, nums[i]);
                curMax = max(curMax, nums[i]);
            }
            else
            {
                if (curMin < prevMax)
                {
                    return false;
                }
                if (i == nums.size())
                {
                    break;
                }

                prevMax = curMax;
                curMax = nums[i];
                curMin = nums[i];
            }
        }

        return true;
    }
};