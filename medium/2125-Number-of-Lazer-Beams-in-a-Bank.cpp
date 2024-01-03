//  keep track of lastValidCount and lastCount
//  loop thru input
//  for each row, get its lazer count, curCount
//      if curCount > 0
//          if lastLazerCount > 0
//              lastValidCount = lastCounT
//          else
//              res += curCount * lastValidCount
//      lastCount = curCount
//  return res
//  ^ realized you dont need half of that and that its way easier while coding

//  Time - O(m * n) - iterate through m*n input once
//  Space - O(1) - no new data structs

//  Solved in 16 min, overcomplicated it a little at first

class Solution {
public:
    int numberOfBeams(vector<string>& bank) {
        int lastCount = 0;
        int res = 0;

        for (int i = 0; i < bank.size(); i++) {
            int curCount = 0;

            for (int j = 0; j < bank[i].length(); j++) {
                if (bank[i][j] == '1') {
                    curCount++;
                }
            }
            
            if (curCount > 0) {
                res += (curCount * lastCount);
                lastCount = curCount;
            }
        }
        
        return res;
    }
};