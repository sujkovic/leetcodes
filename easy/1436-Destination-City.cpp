//  add all source cities to hashmap with their count of occurences
//  iterate thru hashmap, return destination city that isnt in map

//  Time - O(n) - iterate thru input size n onc
//  Space - O(n) - hashmap of cities

//  Solved in under 5 min

class Solution
{
public:
    string destCity(vector<vector<string>> &paths)
    {
        unordered_map<string, int> map;
        for (int i = 0; i < paths.size(); i++)
        {
            map[paths[i][0]]++;
        }
        for (int i = 0; i < paths.size(); i++)
        {
            if (map.find(paths[i][1]) == map.end())
            {
                return paths[i][1];
            }
        }
        return "";
    }
};