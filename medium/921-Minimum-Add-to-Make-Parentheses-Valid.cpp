//  ( ) ) )
//  ( )
//  ) )
//  keep stack
//  if (
//      push to stack
//  if )
//      if stack not empty
//          pop
//      else
//          add to counter
//  after done going through string
//  return stack size + counter

//  solved in like 4 minutes lol

class Solution
{
public:
    int minAddToMakeValid(string s)
    {
        stack<bool> stack;
        int count = 0;

        for (int i = 0; i < s.length(); i++)
        {
            if (s[i] == '(')
            {
                stack.push(true);
            }
            else
            {
                if (!stack.empty())
                {
                    stack.pop();
                }
                else
                {
                    count++;
                }
            }
        }

        return count + stack.size();
    }
};