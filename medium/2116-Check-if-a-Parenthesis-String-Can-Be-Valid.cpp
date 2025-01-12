//  recursive dfs
//  loop through both s and locked at the same rate
//  at any index i, if locked[i] is zero, continue
//      if locked[i] is 1, we can either change the cur paranthesis
//      or dont change it
//  once we hit the end, check if our cur string is valid
//  could do a helper function that just uses a stack

//  Finished in 13 min, TLE on case 7/258 lol
//  Time - O(2^n * n)
//      tree height n, branch factor 2, calling isValidParen (O(n)) at end of each branch
//  Space - O(2^n)
//      every recursive call makes a copy of the string s

/*
class Solution {
public:
    bool isValidParentheses(string s) {
        stack<bool> stack;

        for (int i = 0; i < s.length(); i++) {
            if (s[i] == '(') {
                stack.push(true);
            }
            else {
                if (!stack.empty()) {
                    stack.pop();
                }
                else {
                    return false;
                }
            }
        }

        if (stack.size() > 0) {
            return false;
        }
        return true;
    }
    bool dfs(string &locked, string s, int index) {
        if (index == s.length()) {
            return isValidParentheses(s);
        }

        bool dontChange = dfs(locked, s, index + 1);
        bool change = false;

        if (locked[index] == '0') {
            if (s[index] == '(') {
                s[index] = ')';
            }
            else {
                s[index] = '(';
            }

            change = dfs(locked, s, index + 1);
        }

        return change || dontChange;
    }
    bool canBeValid(string s, string locked) {
        return dfs(locked, s, 0);
    }
};
*/

//  Watched neetcode vid 2 hours ago, going to try again
//  His approach was use two stacks, and treat it as a stack problem no dp
//  freeCards stack, locked stack
//  ex.
//  index :    0 1 2 3 4 5
//  s :        ) ) ( ) ) )
//  locked :   0 1 0 1 0 0
//  combined : * ) * ) * *

//  freeCards: 0 2 4 5
//  locked:    1 3 

//  had to look at vid again to check the logic this problem is tough but basically
//  we want to iterate through the array in one pass, trying to close all ')'
//      meaning we push all '(' to the stack, and when we encounter a ')',
//          we pop from locked if its not empty, else pop from freecards
//          if both stacks are empty, we cant match it, return false
//  then, we might still have '(' left over that we need to close
//  so to do that, iterate through the stacks
//      if locked.top > freecards.top, not possible, return false
//      else pop both locked.top and freecards.top

//  Solved in idk probably 45 min including coding + trying to understand neetcode
//      compiled and accepted on second try just named locked stack same as input by accident
//  Time - O(n)
//  Space - O(n)

class Solution {
public:
    bool canBeValid(string s, string locked) {
        stack<int> lock;
        stack<int> free; 

        for (int i = 0; i < s.length(); i++) {
            //  First, check if cur position is locked or not
            if (locked[i] == '0') {
                free.push(i);
            }
            else {
                //  Then, check if cur position is opening or closing
                if (s[i] == '(') {
                    lock.push(i);
                }
                //  If closing, try to close with free card, then locked, else not valid
                else {
                    if (!lock.empty()) {
                        lock.pop();
                    }
                    else if (!free.empty()) {
                        free.pop();
                    }
                    else {
                        return false;
                    }
                }
            }
        }

        //  Finally, try to close any leftover '('
        while (!lock.empty()) {
            if (free.empty() || lock.top() > free.top()) {
                return false;
            }
            lock.pop();
            free.pop();
        }

        if (free.size() % 2 == 1) {
            return false;
        }

        return true;
    }
};