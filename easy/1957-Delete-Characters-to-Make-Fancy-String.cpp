//  loop through the string
//      if index >= 2 and cur character equals the last 2 characters
//          continue
//      add cur character to result

//  Solved in 3 min
//      O(n) both

class Solution
{
public:
    string makeFancyString(string s)
    {
        string result = "";

        for (int i = 0; i < s.length(); i++)
        {
            if (i >= 2 && s[i] == s[i - 1] && s[i] == s[i - 2])
            {
                continue;
            }
            result += s[i];
        }

        return result;
    }
};