//  keep track of index in num, cur streak of repeating numbers, prev number, and result
//  loop while num != 0
//      if num[index] == prevNum
//          streak++
//          if streak == 3
//              result = num[index]
//      else
//          streak = 1
//      index++


//  Im dumb completely rushed through the question and thought the input was an int
//  Soo solved in 15 minutes

//  O(n) time (loop thru input string), O(1) space (no new data structs)

class Solution {
public:
    string largestGoodInteger(string num) {
        int streak = 1;
        int result = -1;
        for (int i = 1; i < num.length(); i++) {
            if (num[i] == num[i - 1]) {
                streak++;
                if (streak == 3) {
                    result = max(result, num[i] - '0');
                }
            }
            else {
                streak = 1;
            }
        }
        if (result == -1) {
            return "";
        }
        else {
            string res = "";
            res += ('0' + result);
            res += ('0' + result);
            res += ('0' + result);
            return res;
        }
    }
};