//  loop while n > 1, keeping a counter of loop iterations count
//      just do the cases given in the loop
//  return count

//  Solved in 6 minutes

//  Time - O(logn)
//      keep dividing n by 2
//  Space - O(1)
//      No new data structs

class Solution {
public:
    int numberOfMatches(int n) {
        int count = 0;
        while (n > 1) {
            if (n % 2 == 0) {
                count += n / 2;
                n /= 2;
            }
            else {
                count += (n - 1) / 2;
                n = (n - 1) / 2 + 1;
            }
        }
        return count;
    }
};