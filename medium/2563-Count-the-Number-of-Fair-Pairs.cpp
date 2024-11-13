//  Brute force try every pair

//  Finished in 2 min, TLE

//  Time O(n^2), Space O(1)
/*
class Solution {
public:
    long long countFairPairs(vector<int>& nums, int lower, int upper) {
        int count = 0;

        for (int i = 0; i < nums.size(); i++) {
            for (int j = i + 1; j < nums.size(); j++) {
                int sum = nums[i] + nums[j];

                if (lower <= sum && sum <= upper) {
                    count++;
                }
            }
        }

        return count;
    }
};
*/

//  maybe we can do some sort of precomputing
//  (0, 0), (1, 1), (7, 2), (4, 3), (4, 4), (5, 5)

//  yeah still tle

//  at 12 min

/*
class Solution {
public:
    long long countFairPairs(vector<int>& nums, int lower, int upper) {
        int count = 0;
        vector<pair<int, int>> numsSorted;

        for (int i = 0; i < nums.size(); i++) {
            numsSorted.push_back({nums[i], i});
        }

        sort(numsSorted.begin(), numsSorted.end());

        for (int i = 0; i < numsSorted.size(); i++) {
            for (int j = 0; j < numsSorted.size(); j++) {
                int sum = numsSorted[i].first + numsSorted[j].first;

                if (sum > upper) {
                    break;
                }

                if (numsSorted[i].second < numsSorted[j].second && 
                    lower <= sum && sum <= upper) {
                        count++;
                }
            }
        }

        return count;
    }
};
*/

//  looked at hints but it seems like im on the right track and i should use 2 ptr

//  (0, 0), (1, 1), (7, 2), (4, 3), (4, 4), (5, 5)
//  (0, 0), (1, 1), (4, 3), (4, 4), (5, 5), (7, 2)
//   l       r                                      not valid, too small (right++)
//   l               r                              valid, ++
//   l                       r                      valid, ++
//   l                               r              valid, ++
//   l                                       r      not valid, too big (left++)
//           l       r                              valid, ++
//           l               r                      valid, ++
//           l                       r              valid, ++
//           l                               r      not valid, too big (left++)
//                   l       r                      not valid, too big, basically done here


//  30 min, apparantly this doesnt even work??!?
/*
class Solution {
public:
    long long countFairPairs(vector<int>& nums, int lower, int upper) {
        long long count = 0;
        vector<pair<int, int>> numsSorted;

        for (int i = 0; i < nums.size(); i++) {
            numsSorted.push_back({nums[i], i});
        }

        sort(numsSorted.begin(), numsSorted.end());

        int left = 0;
        int right = 1;

        while (left < numsSorted.size()) {
            if (numsSorted[left].first > upper) {
                break;
            }
            if (right >= numsSorted.size()) {
                left++;
                right = left + 1;
                continue;
            }

            int sum = numsSorted[left].first + numsSorted[right].first;

            if (lower <= sum && sum <= upper) {
                count++;
                right++;
            }
            if (sum < lower) {
                right++;
            }
            if (sum > upper) {
                left++;
                right = left + 1;
            }
        }

        

        return count;
    }
};
*/

//  Watched neetcode vid

//  First, sort nums
//  Then, for each element, we want to find the highest and lowest numbers to the right of it
//      that along with it, make a valid pair
//  The difference between those 2 numbers is the # of valid pairs 
//  Repeat for each number in nums
//  To get those high/low numbers, we can binary search

//  0, 1, 4, 4, 5, 7

//  Solved in 18min
//  This was tough tho i need to grind more of these kinds of problems
//      i'm struggling a bit with edge cases 
//  Time O(nlogn)
//  Space O(1)

class Solution {
public:
    int binarySearch(vector<int> &nums, int left, int right, int target) {
        while (left <= right) {
            int middle = (left + right) / 2;

            if (nums[middle] >= target) {
                right = middle - 1;
            }
            else {
                left = middle + 1;
            }
        }

        return right;
    }
    long long countFairPairs(vector<int>& nums, int lower, int upper) {
        sort(nums.begin(), nums.end());
        long long count = 0;

        for (int i = 0; i < nums.size() - 1; i++) {
            int leftBound = binarySearch(nums, i + 1, nums.size() - 1, lower - nums[i]);
            int rightBound = binarySearch(nums, i + 1, nums.size() - 1, upper - nums[i] + 1);
            count += rightBound - leftBound;
        }

        return count;

    }
};