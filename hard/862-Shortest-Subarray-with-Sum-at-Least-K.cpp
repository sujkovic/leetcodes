//  Brute force, try every subarray
//  int shortest = nums size + 1
//  for int i = 0 to nums size - 1 in nums
//      curSubarraySum = 0
//      for int j = i to nums size - 1 in nums
//          curSubarraySum += nums[j]
//          if cursubarray sum >= k
//              update shortest if needed and break
//  return shortest

//  Finished in 7 min, TLE
//  Time - O(n^2)
//  Space - O(1)

/*
class Solution {
public:
    int shortestSubarray(vector<int>& nums, int k) {
        int shortest = nums.size() + 1;

        for (int i = 0; i < nums.size(); i++) {
            int curSubarraySum = 0;

            for (int j = i; j < nums.size(); j++) {
                curSubarraySum += nums[j];

                if (curSubarraySum >= k) {
                    shortest = min(shortest, j - i + 1);
                    break;
                }
            }
        }

        if (shortest == nums.size() + 1) {
            return -1;
        }
        return shortest;
    }
};
*/

//  now need to optimize
//  could try sliding window maybe

//  2 -1 1 2 -1 2    k = 3
//  2  1 2 4  3 5
//  5  3 4 3  1 2



//  Ok scratch all the above, watched neetcode explanation for like the 3rd time today
//  so we want to loop through the array and keep a minheap
//  as we go through the array, add each {prefixSum, index} to the min heap
//  and on each iteration, we want to check 
//  if the current prefix sum - the top of heap's prefixsum >= k, (aka if we shorten the current subarray)
//      pop it from the heap and update result
//      ^ also this should be a while loop bc can have many heap items that fill the condition
//  

//  -1 2 -1 2 3     k = 3

//  Solved in 30 min
//      - forgot the base case of updating the min before the loop (ex. 1 element and its greater than k)
//      - had to use long long for prefixsum and for the queue storing prefix sums, check constraints!
//  Time - O(nlogn) - loop is n, pushing to a heap is logn
//  Space - O(n) - heap

/*
class Solution {
public:
    int shortestSubarray(vector<int>& nums, int k) {
        priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<pair<long long, int>>> heap;
        long long prefixSum = 0;
        int minArray = nums.size() + 1;


        for (int i = 0; i < nums.size(); i++) {
            prefixSum += nums[i];
            if (prefixSum >= k) {
                minArray = min(minArray, i + 1);
            }

            //  while we are able to shorten the array, shorten it
            while (!heap.empty() && prefixSum - heap.top().first >= k) {
                minArray = min(minArray, i - heap.top().second);
                heap.pop();
            }
            heap.push({prefixSum, i});
        }


        if (minArray == nums.size() + 1) {
            return -1;
        }

        return minArray;
    }
};
*/

//  We can optimize even further with a monotonic increasing stack approach
//  But technically stack wouldnt work, since we want the minimum, and with a 
//  monotonic increasing stack the top will be the maximum
//  So instead, we can use a deque
//      every iteration, push to the front, but check
//          if the 
//      minimize the window if possible
//  We iterate through the array, and for each iteration
//      add curnum to cursum
//      if curSum >= k
//          update minsubarray
//      while cursum - deque back sum >= k
//          update min to i - deque back index if possible
//          pop deque back
//      push cursum, i to front of heap

//  -1 2 -1 2 3     k = 3

//  84 -37 32 40 95
//  84
//     47
//        79
//  ^ can explain the monotonic increasing validation with this case
//  on i = 1, towards the end of the for loop, 
//  our current sum is 47, but the current sum for the last element we
//  added to the deque is 84, so since our sum decreased from the last time,
//  the last element we added caused us to have a decreasing deque, which we dont want
//  So, while we have decreasing elements, pop them
//  we only care about increasing values.
//  then just add the current element as usual, and the next iteration will check
//  if it was decreasing

//  Solved in 14 min
//      had to look back at neetcode vid for the validation monotonic
//      increasing part at the end of the for loop (the last while loop)

class Solution {
public:
    int shortestSubarray(vector<int>& nums, int k) {
        deque<pair<long long, int>> deq;
        long long curSum = 0;
        int minArraySize = nums.size() + 1;

        for (int i = 0; i < nums.size(); i++) {
            curSum += nums[i];
            if (curSum >= k) {
                minArraySize = min(minArraySize, i + 1);
            }

            while (!deq.empty() && curSum - deq.back().first >= k) {
                minArraySize = min(minArraySize, i - deq.back().second);
                deq.pop_back();
            }

            while (!deq.empty() && curSum < deq.front().first) {
                deq.pop_front();
            }
            deq.push_front({curSum, i});
        }

        if (minArraySize == nums.size() + 1) {
            return -1;
        }

        return minArraySize;
    }
};