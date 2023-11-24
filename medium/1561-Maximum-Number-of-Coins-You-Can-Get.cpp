//  sort input array
//  loop through array, for every iteration
//      pop smallest element
//      pop largest element
//      add largest element to total and pop it
//  return total

//  Solved in 10 min (tried to use heap at first, didn't read the part ab bob picking min)

//  Time - O(nlogn)
//      sort is nlogn, loop is n

//  Space - O(1)
//      no new data structs

class Solution {
public:
    int maxCoins(vector<int>& piles) {
        sort(piles.begin(), piles.end());
        int total = 0;
        int left = 0;
        int right = piles.size() - 1;

        while (left < right) {
            right--;
            total += piles[right];

            right--;
            left++;
        }

        return total;
    }
};