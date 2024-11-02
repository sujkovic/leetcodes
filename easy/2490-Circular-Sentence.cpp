//  if first char != last char
//      return false
//  set bool isCircular to true
//  loop through the string
//      if cur is a space and we are not at the last index
//          if the last and next char are equal
//              continue
//          else
//              isCircular = false
//  return isCircular

//  Solved in 5 min
//  Time O(n) Space O(1)

class Solution
{
public:
    bool isCircularSentence(string sentence)
    {
        if (sentence[0] != sentence[sentence.size() - 1])
        {
            return false;
        }

        bool isCircular = true;
        for (int i = 0; i < sentence.size(); i++)
        {
            if (sentence[i] == ' ')
            {
                if (i != sentence.size() - 1 && sentence[i - 1] == sentence[i + 1])
                {
                    continue;
                }
                isCircular = false;
            }
        }

        return isCircular;
    }
};