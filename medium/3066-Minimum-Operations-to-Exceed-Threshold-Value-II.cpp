//  Sort the array
//  Keep a x and y variable, init to the first 2 values
//  add the formula to the first element in the array
//      then check 
//  actually no this might not work
//  i think a min heap might be better

//  ok first make a min heap of the nums array, and set 2 smallest vals as x and y
//  while the top of the heap is less than k,
//      pop it, apply formula to it
//      if it's now greater than x / y, update x / y accordingly
//      push it back to the heap
//      numOperations++

//  Solved in 22 min
//      I was overcomplicating the replacement logic with if else statements for no reason oops
//      Pretty happy with the result of this as my first leetcode in like a month tho lol
//  Time - O(nlogn)
//  Space - O(n)

class Solution {
    public:
        int minOperations(vector<int>& nums, int k) {
            if (nums.size() < 2) {
                return 0;
            }
    
            //  init heap
            priority_queue<long long, vector<long long>, greater<long long>> heap;
            for (int i = 0; i < nums.size(); i++) {
                heap.push(nums[i]);
            }
    
            //  init variables
            int numOperations = 0;
            long long x = heap.top();
            heap.pop();
            long long y = heap.top();
            heap.push(x);
    
            while (heap.top() < k) {
                //  replace the top element with the one derived from formula
                long long cur = (x * 2) + y;
                heap.pop();
                heap.pop();
                heap.push(cur);
    
                //  then update x and y
                x = heap.top();
                heap.pop();
                y = heap.top();
                heap.push(x);
    
                numOperations++;
            }
    
            return numOperations;
        }
    };