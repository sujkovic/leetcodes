//                                        ""
//                      a,                                   ,
//         a, b                a,                   ab                 ,
//  a, b, a   a, b,     a, ba       a,      ab, a      ab,       aba,        ,
//     x

//  keep a string currentSubstring, a set currentString, and an index
//  at each point in the decision tree (each dfs call), push the current
//  character to currentSubstring, then the decision is either
//      push currentSubstring to currentString and then reset currentSubstring
//      dont push currentSubstring, keep going through the string
//  once you hit end of the string return the size of the set currentString
//  and if you ever encounter a duplicate in the set return 0

//  Solved in 24 minutes :D 
//  Time - O(2^n) where n = input string size
//  Space - Leetcode says O(n) but i feel like it should be (2^n) since each call has its own set

class Solution
{
public:
    int dfs(string &s, unordered_set<string> curString, string curSubstring, int index)
    {
        if (index == s.length())
        {
            cout << endl;
            return curString.size();
        }

        curSubstring += s[index];
        int dontInclude = dfs(s, curString, curSubstring, index + 1);
        int include;
        if (curString.find(curSubstring) != curString.end())
        {
            include = 0;
        }
        else
        {
            curString.insert(curSubstring);
            curSubstring = "";
            include = dfs(s, curString, curSubstring, index + 1);
        }

        return max(include, dontInclude);
    }
    int maxUniqueSplit(string s)
    {
        unordered_set<string> curString;
        return dfs(s, curString, "", 0);
    }
};