//  brute force, idk if this can be optimized 
//  loop through from 1 to n, keeping a result and curDeposit
//      if n % 7 == 1
//          curDeposit -= 6
//      result += curDeposit
//  return result

//  Took 13 min, spent 10 of those debugging the fact that i was doing curDeposit -= 5

//  Time - O(n) - loop 0 to n
//  Space - O(1) - no new data struct

class Solution {
public:
    int totalMoney(int n) {
        int result = 0;
        int curDeposit = 0;
        for (int i = 0; i < n; i++) {
            curDeposit++;
            if ((i % 7 == 0) && i != 0) {
                curDeposit -= 6;
            }
            result += curDeposit;
        }
        return result;
    }
};