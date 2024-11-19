//  Brute force try every subarray of length k

//  Finished in 9 min, TLE
//  Time - O(n * k)
//  Space - O(1)

/*
class Solution {
public:
    long long maximumSubarraySum(vector<int>& nums, int k) {
        long long maxSum = 0;

        for (int i = 0; i < nums.size() - k + 1; i++) {
            long long curSum = 0;
            bool areNumsDistinct = true;
            unordered_set<int> visited;
            for (int j = i; j < i + k; j++) {
                if (visited.find(nums[j]) != visited.end()) {
                    areNumsDistinct = false;
                    break;
                }
                
                visited.insert(nums[j]);
                curSum += nums[j];
            }

            if (areNumsDistinct) {
                maxSum = max(maxSum, curSum);
            }
        }

        return maxSum;
    }
};
*/

//  Optimization - Use sliding window, keep a windowsum and keep a hashmap of frequency of each #

//  1 5 4 2 9 9 9
//  l   r           sum 10, 1:1, 5:1, 4:1
//    l   r         sum 11, 5:1, 4:1, 2:1
//      l   r       sum 16, 4:1, 2:1, 9:1
//        l   r     sum 20, 2:1, 9:2         <- not valid, dont update best
//          l   r   sum 27, 9:3              <- not valid, dont update best

//  hm how would we know when to make it valid again though
//  could do while loop until we hit that duplicate index
//      but then we could hit another duplicate index..
//  i think ill just "brute force" that part for now and check the whole map if its invalid

//  left = 0, right = 0
//  while right < numsSize - 1
//      right++
//      map[right]++
//      sum += nums[right]
//      if (right - left + 2 != k)       (in the beginning when we're still making our window of size k)
//          continue
//      if (right == k - 1 && left == 0)    (first window, avoiding out of bounds)
//          if map contains no duplicates
//              update res
//          continue
//      map[left]--
//      sum -= nums[left]
//      left++
//      if map contains no duplicates
//          update result

//  Finished in 33 min, TLE
//  Still O(n * k)


/*
class Solution {
public:
    long long maximumSubarraySum(vector<int>& nums, int k) {
        long long maxSum = 0;
        long long sum = 0;
        unordered_map<int, int> freq;
        int left = 0;
        int right = -1;

        while (right < nums.size() - 1 || right == -1) {
            right++;
            freq[nums[right]]++;
            sum += nums[right];
            if (right + 1 < k) {
                continue;
            }
            if (!(right == k - 1 && left == 0)) {
                freq[nums[left]]--;
                sum -= nums[left];
                left++;
            }

            bool containsDuplicates = false;
            for (auto it = freq.begin(); it != freq.end(); it++) {
                if (it->second > 1) {
                    containsDuplicates = true;
                    break;
                }
            }

            if (!containsDuplicates) {
                maxSum = max(maxSum, sum);
            }
        }

        return maxSum;
    }
};
*/

//  Watched the first minute of the neetcode vid and heard him say k == size of map and that was all i needed to know
//  Added fix in 8 min
//  Time - O(n)
//  Space - O(k)

/*
class Solution {
public:
    long long maximumSubarraySum(vector<int>& nums, int k) {
        long long maxSum = 0;
        long long sum = 0;
        unordered_map<int, int> freq;
        int left = 0;
        int right = -1;

        while (right < nums.size() - 1 || right == -1) {
            right++;
            freq[nums[right]]++;
            sum += nums[right];

            if (right + 1 < k) {
                continue;
            }

            if (!(right == k - 1 && left == 0)) {
                freq[nums[left]]--;
                if (freq[nums[left]] == 0) {
                    freq.erase(nums[left]);
                }
                sum -= nums[left];
                left++;
            }

            if (freq.size() == k) {
                maxSum = max(maxSum, sum);
            }
        }

        return maxSum;
    }
};
*/


//  Clean up code  ~ 7 min

class Solution {
public:
    long long maximumSubarraySum(vector<int>& nums, int k) {
        long long maxSum = 0;
        long long sum = 0;
        unordered_map<int, int> freq;
        int left = 0;
        int right = 0;

        //  Initialize first window of size k
        while (right < k) {
            freq[nums[right]]++;
            sum += nums[right];
            right++;
        }

        //  if valid, update res
        if (freq.size() == k) {
            maxSum = sum;
        }

        //  main loop
        while (right < nums.size()) {
            freq[nums[right]]++;
            sum += nums[right];

            freq[nums[left]]--;
            if (freq[nums[left]] == 0) {
                freq.erase(nums[left]);
            }
            sum -= nums[left];

            if (freq.size() == k) {
                maxSum = max(sum, maxSum);
            }
            
            left++;
            right++;
        }

        return maxSum;
    }
};