//  Brute force i think
//  Make set, generate all possible strings of length n from 0 to n - 1 and add them to set
//  Remove all strings from set that are in nums vec
//  Return any string in set

//  Solved in 30 min (zoned out for half the time i spent working on it tbh)

//  Time complexity - O(n)
//  Loop of size n, as well as n recursive calls
//  Since we know there's only n elements, we dont actually need to find 2^n combinations, just n + 1 at most
//  Set limit to log2(nums.size()) so we only do 2^log2(n) recursive calls which is just n

//  Space complexity - O(n)
//  Max depth of recursive call stack is n, max set size is also n

class Solution
{
public:
    void generateStrings(unordered_set<string> &set, int &limit, int curIndex, string curString)
    {
        if (curIndex == limit)
        {
            return;
        }
        curString[curIndex] = '0';
        set.insert(curString);
        generateStrings(set, limit, curIndex + 1, curString);

        curString[curIndex] = '1';
        set.insert(curString);
        generateStrings(set, limit, curIndex + 1, curString);
    }
    string findDifferentBinaryString(vector<string> &nums)
    {
        unordered_set<string> set;
        int limit = ceil(log2(nums.size())) + 1;
        string originalString = "";

        for (int i = 0; i < nums.size(); i++)
        {
            originalString += "0";
        }

        generateStrings(set, limit, 0, originalString);

        for (int i = 0; i < nums.size(); i++)
        {
            if (set.find(nums[i]) != set.end())
            {
                set.erase(nums[i]);
            }
        }

        for (auto &it : set)
        {
            return it;
        }

        return "";
    }
};
