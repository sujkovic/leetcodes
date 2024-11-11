//  Solved in 5 min
//  O(n) time O(1) space

class Solution
{
public:
    string mergeAlternately(string word1, string word2)
    {
        bool addWord1 = true;
        int word1Index = 0;
        int word2Index = 0;
        string result = "";

        while (word1Index < word1.size() && word2Index < word2.size())
        {
            if (addWord1)
            {
                result += word1[word1Index];
                word1Index++;
            }
            else
            {
                result += word2[word2Index];
                word2Index++;
            }

            addWord1 = !addWord1;
        }

        if (word1Index != word1.length())
        {
            while (word1Index < word1.length())
            {
                result += word1[word1Index];
                word1Index++;
            }
        }
        if (word2Index != word2.length())
        {
            while (word2Index < word2.length())
            {
                result += word2[word2Index];
                word2Index++;
            }
        }

        return result;
    }
};