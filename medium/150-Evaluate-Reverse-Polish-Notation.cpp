//  loop through tokens, pushing every number you see onto a stack
//  for arithmetic signs,
//      pop the current top two numbers
//      perform the operation
//      push the result 
//  return the top of the stack at the end

//  Time - O(n)
//  Space - O(n)

//  Solved in 9 minutes

class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> stk;

        for (int i = 0; i < tokens.size(); i++) {
            if (tokens[i] != "/" && tokens[i] != "*" && tokens[i] != "-" && tokens[i] != "+"){
                stk.push(stoi(tokens[i]));
            }
            else {
                int op1 = stk.top();
                stk.pop();
                int op2 = stk.top();
                stk.pop();

                if (tokens[i] == "+") {
                    stk.push(op1 + op2);
                }
                else if (tokens[i] == "-") {
                    stk.push(op2 - op1);
                } 
                else if (tokens[i] == "*") {
                    stk.push(op2 * op1);
                }
                else {
                    stk.push(op2 / op1);
                }
            }
        }

        return stk.top();
    }
};