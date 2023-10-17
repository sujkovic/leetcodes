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

class Solution {
public:
    vector<bool> checkArithmeticSubarrays(vector<int>& nums, vector<int>& l, vector<int>& r) {
        vector<bool> res;
        for (int i = 0; i < l.size(); i++) {
            vector<int> curNums(nums.begin() + l[i], nums.begin() + r[i]);
            bool isArithmeticSubarray = true;
            for (int j = 2; j < curNums.size(); j++) {
                if ((curNums[j] - curNums[j - 1]) != (curNums[j - 1] - curNums[j - 2])) {
                    isArithmeticSubarray = false;
                }
            }
            res.push_back(isArithmeticSubarray);
        }
        return res;
    }
};