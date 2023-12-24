//  had to watch a vid for this one damn

//  my original thought was start with a 1 and with a 0, checking the min # changes and returning min
//  now realized that the end result can literally only be 2 possible strings, 10101 or 01010 for wtv length
//  so can just keep a bool isCurCharOne and just keep checking that instead of comparing back and forth
//  also accoring to neetcode vid, only need 1 pass since the # for one soln is n - # for the other soln

//  Time - O(n) - single pass through input size n
//  Space - O(1) - no new data allocated

//  Spent around 20-30 minutes on this problem

class Solution {
public:
    int minOperations(string s) {
        int count = 0;
        bool isCurCharOne = false;

        for (int i = 0; i < s.length(); i++) {
            if ((isCurCharOne && s[i] == '1') || (!isCurCharOne && s[i] == '0')) {
                count++;
            }
            isCurCharOne = !isCurCharOne;
        }
        return min(count, (int)s.length() - count);
    }
};