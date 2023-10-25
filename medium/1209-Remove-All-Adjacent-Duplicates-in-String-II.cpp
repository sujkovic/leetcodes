//  init stack of pair<char, int>
//          basically keep track of the length of every repeating segment
//  make a global pair, init as {s[0], 1}
//  loop through s
//      if cur = prev, pair.second++
//      else 
//          stack.push(pair)
//          pair = {s[cur], 1}
//  push cur pair to stack
//  make new string newStr
//  while stack is empty
//      add stack.top().second % k of stack.top.first to newStr
//  add stack to a string, reverse, return



//  Time Complexity - O(n^2)
//  Space Complexity - O(n)
//  Solved in 15 min

class Solution {
public:
    string removeDuplicates(string s, int k) {
        stack<char> stack;
        bool duplicatesExist = true;

        while (duplicatesExist) {
            int count = 1;
            duplicatesExist = false;
            stack.push(s[0]);
            for (int i = 1; i < s.length(); i++) {
                stack.push(s[i]);
                if (s[i] == s[i - 1]) {
                    count++;
                }
                else {
                    count = 1;
                }

                if (count == k) {
                    duplicatesExist = true;

                    while (count > 0) {
                        stack.pop();
                        count--;
                    }
                    count = 0;
                }
            }
            string newStr = "";
            while (!stack.empty()) {
                newStr += stack.top();
                stack.pop();
            }
            reverse(newStr.begin(), newStr.end());
            s = newStr;
        }
        return s;
    }
};


//  ^^^ Time Limit Exceeded on leetcode

//  my optimized solution

//  Time/Space O(n)
//  Solved in one hour

class Solution {
public:
    string removeDuplicates(string s, int k) {
        stack<pair<char, int>> stack;

        for (int i = 0; i < s.length(); i++) {
            if (!stack.empty() && s[i] == stack.top().first) {
                pair<char, int> cur = stack.top();
                stack.pop();
                cur.second++;
                stack.push(cur);
                
            } else {
                stack.push({s[i], 1});
            }

            if (stack.top().second == k) {
                stack.pop();
            }
        }
        string res = "";

        while (!stack.empty()) {
            for (int i = 0; i < stack.top().second; i++) {
                res += stack.top().first;
            }
            stack.pop();
        }
        
        reverse(res.begin(), res.end());
        return res;
    }
};