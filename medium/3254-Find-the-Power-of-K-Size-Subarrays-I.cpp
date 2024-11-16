//  Brute force, try every subarray of size k, computing the power on the spot
//  for i = 0 to nums size in nums
//      isSorted = true
//      endIndex = i + k
//      if endIndex out of bounds
//          break
//      for j = i + 1 to endIndex
//          if nums[j] <= nums[j - 1]
//              isSorted = false
//      if not sorted,
//          res += -1
//      else
//          res += nums[endIndex]

//  Solved in 11 min
//  Time - O(n * k)
//  Space - O(1)

/*
class Solution {
public:
    vector<int> resultsArray(vector<int>& nums, int k) {
        vector<int> res;

        for (int i = 0; i < nums.size(); i++) {
            bool isSorted = true;
            int endIndex = i + k - 1;
            if (endIndex >= nums.size()) {
                break;
            }

            for (int j = i + 1; j <= endIndex; j++) {
                if (nums[j] != nums[j - 1] + 1) {
                    isSorted = false;
                    break;
                }
            }

            if (isSorted) {
                res.push_back(nums[endIndex]);
            }
            else {
                res.push_back(-1);
            }
        }

        return res;
    }
};
*/

//  1 2 3 4 3 2 5   k = 3
//  w w w w l l l

//  2 2 2 2 2       k = 4
//  w l l l l

//  3 2 3 2 3 2     k = 2
//  w l w l w l

//  could try doing an initial scan to precompute the "streaks" of consecutiveness
//  and then scan through the array again, checking if streaks[i] == true (except for first index)

//  vector<bool> streaks(nums size, l);
//  for num in nums (starting at 1)
//     if curnum == prevnum + 1
//          set streaks at cur to true
//  for i = 1 to nums size in nums
//      if i >= k - 1       (once weve checked an entire subarray of size k)

//  nevermind i dont think this would work
//  looked at discussion and theyre saying sliding window whoops


//  can just keep a left and right pointer
//  left = 0, right = 1
//  while right < nums size
//      if curnum != prevnum + 1
//          left = right
//      if right - left >= k - 1
//          push nums[right] to res
//      else if (right >= k - 1)
//          push -1 to res
//      right++

//  1 2 3 4 3 2 5   k = 3
//  l r
//  l   r           push 3
//  l     r         push 4
//          lr      push -1
//          l r     push -1
//            l r   push -1

//  Solved in 28 min
//      dont forget to account for edge cases (arr size 1)
//  Time - O(n)
//  Space - O(1)

class Solution {
public:
    vector<int> resultsArray(vector<int>& nums, int k) {
        vector<int> res;
        int left = 0;
        int right = 0;

        while (right < nums.size()) {
            if (right != 0 && nums[right] != nums[right - 1] + 1) {
                left = right;
            }
            if (right - left >= k - 1) {
                res.push_back(nums[right]);
            }
            else if (right >= k - 1) {
                res.push_back(-1);
            }

            right++;
        }

        return res;
    }
};