//  initialize a stack and an int maxDepth
//  loop through s
//      if s[i] == '(', push to the stack
//      if s[i] == ')', pop from the stack
//      whenever you push to the stack, check set maxDepth to max(maxDepth, stack.size())
//  return maxDepth

//  let n = s.length()
//  Time Complexity - O(n), we iterate through input string once
//  Space Complexity - O(n), worst case the entire input is parenthesis
//  Solved in 5 minutes oh yeah

class Solution {
public:
    int maxDepth(string s) {
        stack<bool> stack;
        int maxDepth = 0;
        for (int i = 0; i < s.length(); i++) {
            if (s[i] == '(') {
                stack.push(true);
                maxDepth = max(maxDepth, (int)stack.size());
            } 
            if (s[i] == ')') {
                stack.pop();
            }
        }
        return maxDepth;
    }
};