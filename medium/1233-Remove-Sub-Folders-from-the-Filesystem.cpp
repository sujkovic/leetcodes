//  Given "/a", "/a/b", "/c/d", "/c/d/e", "/c/f"
//  if you sort it lexicographically, parents will always come before children
//  so insert the first string into the result vec, then
//  for folder in folders
//      if the last folder in result has same prefix
//          continue
//      else
//          push cur folder to result

//  Solved in 16 minutes
//  Time - O(m * n) where m = folder.size() and n is the length of the largest string in folder
//  Space - O(n) - temp strings in the loop

class Solution
{
public:
    vector<string> removeSubfolders(vector<string> &folder)
    {
        sort(folder.begin(), folder.end());
        vector<string> result;
        result.push_back(folder[0]);

        for (int i = 1; i < folder.size(); i++)
        {
            string prevString = result[result.size() - 1];
            string startOfCur = folder[i].substr(0, prevString.length());

            if (prevString.length() > folder[i].length())
            {
                result.push_back(folder[i]);
                continue;
            }
            if ((startOfCur != prevString) || (folder[i].length() > prevString.length() && folder[i][prevString.length()] != '/'))
            {
                result.push_back(folder[i]);
            }
        }

        return result;
    }
};

//  Gonna try trie implementation later