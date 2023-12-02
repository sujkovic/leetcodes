//  make hashmap of char : frequency for the chars string
//  for each word in words, make the same hashmap for it
//  iterate through each words hashmap
//      check if frequency of each letter is <= its frequeucny in chars
//  if the words valid, inc result by its length
//  return result

//  let n is words size, m is longest string in word, t is chars length

//  Space - O(t + m)
//      since we make hashmaps of those sizes

//  Time - O(n * m)
//      loop through words vec, then through each word in it
//      and also through each words hashmap, worst case m

//  Solved in 10 min

class Solution
{
public:
    int countCharacters(vector<string> &words, string chars)
    {
        unordered_map<char, int> map;
        int result = 0;

        for (int i = 0; i < chars.length(); i++)
        {
            map[chars[i]]++;
        }

        for (int i = 0; i < words.size(); i++)
        {
            unordered_map<char, int> curMap;
            bool isCurValid = true;

            for (int j = 0; j < words[i].length(); j++)
            {
                curMap[words[i][j]]++;
            }

            for (auto letter : curMap)
            {
                if (letter.second > map[letter.first])
                {
                    isCurValid = false;
                    break;
                }
            }

            if (isCurValid)
            {
                result += words[i].length();
            }
        }

        return result;
    }
};