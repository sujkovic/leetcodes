//  if theyre dif lengths, return false
//  loop through the length of s
//      take the string up until the current index - 1 and append it to the string from cur index to the end
//      if it equals goal, return true
//  return false

//  Solved in 8 minutes
//  O(n^2) Time, O(n) Space

/*
class Solution {
public:
    bool rotateString(string s, string goal) {
        if (s.length() != goal.length()) {
            return false;
        }
        if (s == goal) {
            return true;
        }

        for (int i = 1; i < s.length(); i++) {
            string firstHalf = s.substr(0, i);
            string secondHalf = s.substr(i, s.length() - i);
            if (secondHalf + firstHalf == goal) {
                return true;
            }
        }

        return false;
    }
};
*/

//  O(1) Space
//  Took another idk 5 minutes

class Solution
{
public:
    bool rotateString(string s, string goal)
    {
        if (s.length() != goal.length())
        {
            return false;
        }
        if (s == goal)
        {
            return true;
        }

        for (int i = 1; i < s.length(); i++)
        {
            bool isEqual = true;
            int goalIndex = 0;

            for (int sIndex = i; sIndex < s.length(); sIndex++)
            {
                if (s[sIndex] != goal[goalIndex])
                {
                    isEqual = false;
                }
                goalIndex++;
            }

            for (int sIndex = 0; sIndex < i; sIndex++)
            {
                if (s[sIndex] != goal[goalIndex])
                {
                    isEqual = false;
                }
                goalIndex++;
            }

            if (isEqual)
            {
                return true;
            }
        }

        return false;
    }
};