//  make res vec, loop through l&r arrays at same time, ex from 0 to l.size()
//          make copy of that segment and sort it
//          loop through new array from l[i] to r[i]
//              check if cur difference == last difference
//                  if not, push false to result vec, break out of loop
//          if we never pushed false, return true (use tracker variable)
//  return res vec

//  let r = r.size(), n = nums.size()
//  Time Complexity - O(r * nlogn)
//      outer loop r iterations (O(r))
//          in it, sort vec of up to size n (O(nlogn))
//          iterate through the vec of up to size n (O(n))
//  Space Complexity - O(n) - curNums array can be up to size n
//  Solved in 18 minutes

class Solution
{
public:
    vector<bool> checkArithmeticSubarrays(vector<int> &nums, vector<int> &l, vector<int> &r)
    {
        vector<bool> res;
        for (int i = 0; i < l.size(); i++)
        {
            vector<int> curNums(nums.begin() + l[i], nums.begin() + r[i]);
            bool isArithmeticSubarray = true;
            for (int j = 2; j < curNums.size(); j++)
            {
                if ((curNums[j] - curNums[j - 1]) != (curNums[j - 1] - curNums[j - 2]))
                {
                    isArithmeticSubarray = false;
                }
            }
            res.push_back(isArithmeticSubarray);
        }
        return res;
    }
};

//  BRUH APPARANTLEY I DID THIS TWICE BY ACCIDENT WHOOPS
//  heres my second run through i guess, surpsingly identical wow

//  Make res vec, subArr vec
//  Loop through l/r arrays
//  For each subarray
//      Copy the current subarray to a new vector and sort it
//      If the abs value of the difference betweeen every consecutive element is ==, add true to res vec, else false
//  Return res vec

//  Solved in 14 min

//  Time - O(n * nlogn)
//      Outer loop worst case n iterations
//      Within outer loop:
//          sort cur sub array is nlogn
//          loop through cur sub array is n at worst

//  Space - O(n)
//      Copy cur subArray to a new vec to sort it, worst case n (ex. l[i] = 0, r[i] = nums.size() - 1)

class Solution
{
public:
    vector<bool> checkArithmeticSubarrays(vector<int> &nums, vector<int> &l, vector<int> &r)
    {
        vector<bool> res;
        vector<int> subArray;
        int curSubArray = 0;
        int numSubArrays = l.size();

        while (curSubArray != numSubArrays)
        {
            subArray = vector<int>(nums.begin() + l[curSubArray], nums.begin() + r[curSubArray] + 1);
            sort(subArray.begin(), subArray.end());
            bool isArithmetic = true;

            for (int i = 2; i < subArray.size(); i++)
            {
                if ((subArray[i] - subArray[i - 1]) != (subArray[i - 1] - subArray[i - 2]))
                {
                    isArithmetic = false;
                    break;
                }
            }
            res.push_back(isArithmetic);
            subArray.clear();
            curSubArray++;
        }
        return res;
    }
};