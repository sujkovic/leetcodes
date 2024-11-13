//  3 5 2 1 6 4
//  3 5 1 6 2 4

//  had to check discussions for this but it seems like the odd indicies are maximized
//  and the even indices are minimized
//  so could just sort the array normally and then put the first half in the even indices
//  and the second half in the odd indices

//  Solved in 8 min
//  Time - O(nlogn)

/*
class Solution {
public:
    void wiggleSort(vector<int>& nums) {
        vector<int> numsCopy = nums;
        sort(numsCopy.begin(), numsCopy.end());
        int numsCopyIt = 0;

        for (int i = 0; i < nums.size(); i = i + 2) {
            nums[i] = numsCopy[numsCopyIt];
            numsCopyIt++;
        }
        for (int i = 1; i < nums.size(); i = i + 2) {
            nums[i] = numsCopy[numsCopyIt];
            numsCopyIt++;
        }
    }
};
*/


//  For O(n) solution, only hint i saw was to be greedy along with odd/evens
//  ex. 
//   < > < > <
//  3 5 2 1 6 4
//  i
//    i
//      i
//        i -> not valid, so swap
//  3 5 1 2 6 4
//          i
//            i

//   < > < > < >
//  8 3 0 4 6 2 1
//    i             swap
//  3 8 0 4 6 2 1
//      i
//        i
//          i      swap
//  3 8 0 6 4 2 1
//            i    swap
//  3 8 0 6 2 4 1
//              i  done

//  Had it done in like 8 minutes and then spent 12 minutes confused just to realize
//  i was doing nums[i] % 2 instead of i % 2...

//  O(n) time, O(1) space

class Solution {
public:
    void wiggleSort(vector<int>& nums) {
        for (int i = 1; i < nums.size(); i++) {

            if (i % 2 == 1) {
                if (nums[i - 1] > nums[i]) {
                    swap(nums[i], nums[i - 1]);
                }
            }
            else {
                if (nums[i - 1] < nums[i]) {
                    swap(nums[i], nums[i - 1]);
                }
            }
        }
    }
};