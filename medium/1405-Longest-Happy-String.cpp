// ex. a = 1, b = 1, c = 7
//                                                     -
//                a                              b                                      c
//      aa      ab       ac           ba         bb          bc               ca        cb           cc
//      x  aba x abc  aca acb acc baa bab bac    x       bca bcb bcc     caa cab cac  cba cbb cbc    x
//                             x   x                              x       x                x

//  Solved in 50 minutes but memory limit exceeded
//  just checked neetcode and realized you're not even supposed to do dp bruh

/*
class Solution {
public:
    string dfs(int a, int b, int c, string str, string &res) {
        string aRes = str;
        string bRes = str;
        string cRes = str;
        string curBest = str;

        if (a > 0) {
            if(str.length() < 2 || (str.length() >= 2) && !((str[str.length() - 1] == 'a') && (str[str.length() - 2] == 'a'))) {
                aRes = dfs(a - 1, b, c, str + "a", res);
            }
        }
        if (b > 0) {
            if(str.length() < 2 || (str.length() >= 2) && !((str[str.length() - 1] == 'b') && (str[str.length() - 2] == 'b'))) {
                bRes = dfs(a, b - 1, c, str + "b", res);
            }
        }
        if (c > 0) {
            if(str.length() < 2 || (str.length() >= 2) && !((str[str.length() - 1] == 'c') && (str[str.length() - 2] == 'c'))) {
                cRes = dfs(a, b, c - 1, str + "c", res);
            }
        }

        //  get the longest of ares, bres, cres
        if (aRes.length() > bRes.length()) {
            if (aRes.length() > cRes.length()) {
                curBest = aRes;
            }
            else {
                curBest = cRes;
            }
        }
        else {
            if (bRes.length() > cRes.length()) {
                curBest = bRes;
            }
            else {
                curBest = cRes;
            }
        }

        //  update result
        if (curBest.length() > res.length()) {
            res = curBest;
        }

        return curBest;
    }
    string longestDiverseString(int a, int b, int c) {
        string res = "";
        dfs(a, b, c, "", res);
        return res;
    }
};
*/

//  Max heap

//  keep a max heap of the characters and their remaining counts
//  while the heap is not empty
//      if the last 2 chars of res are not the same as top of heap char
//          push cur char to res
//          pop cur char from top of heap, decrement by 1, push it back
//      else
//          pop top of heap and put it in a temp variable
//          if the heap is now empty
//              return res
//          else
//              pop cur char from top of heap, decrement by 1, push it back
//              push back the original top of heap in temp

//  Solved in 17 min

class Solution
{
public:
    string longestDiverseString(int a, int b, int c)
    {
        string res = "";
        priority_queue<pair<int, char>> queue;
        if (a > 0)
        {
            queue.push({a, 'a'});
        }
        if (b > 0)
        {
            queue.push({b, 'b'});
        }
        if (c > 0)
        {
            queue.push({c, 'c'});
        }

        while (!queue.empty())
        {
            pair<int, char> curPair = queue.top();
            queue.pop();

            if ((res.length() < 2) || (res.length() >= 2 &&
                                       !((res[res.length() - 1] == curPair.second) && res[res.length() - 2] == curPair.second)))
            {
                res += curPair.second;
                curPair.first--;
            }
            else
            {
                if (queue.empty())
                {
                    return res;
                }
                else
                {
                    pair<int, char> moreCurPair = queue.top();
                    queue.pop();
                    res += moreCurPair.second;
                    moreCurPair.first--;

                    if (moreCurPair.first > 0)
                    {
                        queue.push(moreCurPair);
                    }
                }
            }

            if (curPair.first > 0)
            {
                queue.push(curPair);
            }
        }

        return res;
    }
};