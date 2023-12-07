//  start from right of string, find index of first odd number
//  return the string from 0 to that index

//  Time - O(n) - loop thru input
//  Space - O(1) - no new data struct

//  Solved in 5 min

class Solution
{
public:
    string largestOddNumber(string num)
    {
        int index = -1;
        for (int i = num.size() - 1; i >= 0; i--)
        {
            if ((num[i] - '0') % 2 == 1)
            {
                index = i;
                break;
            }
        }

        if (index == -1)
        {
            return "";
        }

        string res = "";
        for (int i = 0; i <= index; i++)
        {
            res += num[i];
        }
        return res;
    }
};