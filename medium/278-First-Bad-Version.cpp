// The API isBadVersion is defined for you.
// bool isBadVersion(int version);

//  f f f t t
//  l       r
//      l   r
//        l r
//        lr

//  Binary search
//  int left = 1, right = n
//  int first

//  while (left <= right) 
//      middle = left+right / 2
//      if isBadVersion(middle)
//          left = mid + 1
//          update first
//      else
//          right - mid - 1
//  


//  Solved in 8 min
//      Had the if/else swapped at first, also mid overflowed so had to look up the other way
//  Time - O(logn)
//  Space - O(1)

class Solution {
public:
    int firstBadVersion(int n) {
        int left = 1;
        int right = n;
        int first = n;  //  can also get rid of this and return left (but not right)

        while (left <= right) {
            int mid = left + ((right - left) / 2);

            if (isBadVersion(mid)) {
                first = min(first, mid);
                right = mid - 1;
            }
            else {
                left = mid + 1;
            }
        }

        return left;
    }
};