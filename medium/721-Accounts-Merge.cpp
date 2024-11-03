//  Spent a good like 3 hours trying to understand the neetcode explanation going to try coding now

//  Make a Union find class
//  initialize parents array to size of accounts
//  The idea now is treat the index of each entry in accounts as like a primary key (i actually thought of this part on my own)

//  0 -> 0
//  1 -> 1
//  2 -> 2
//  3 -> 3

//  We'll make a map of email : accountIndex
//  So loop through the accounts array
//      Loop through the emails in the current account
//          if the email exists already in our hashmap, union the current account with the account at map[email]
//          else, just insert the email into the map with map[email] = cur account index

//  Map at this point
//  johnsmith@mail.com -> 0         this one is also in 1, but already exists when we see it there
//  john_newyork@mail.com -> 0
//  john00@mail.com -> 1
//  mary@mail.com -> 2
//  johnnybravo@mail.com -> 3

//  Disjoint subsets at this point
//  0 -> 0
//  1 -> 0
//  2 -> 2
//  3 -> 3
//  So now 1's parent is 0

//  At this point, we have our disjoint subsets all set up such that our nodes are account indexes,
//  and each accounts[accountIndex] that shares an email is connected in our graph as a subset
//  But these disjoint subsets only contain account indices, so now we need to map back to emails
//  So we'll make a new map of parentAccountIndex : associated emails
//  Now loop through our original map
//      find the parent of map[curEmail]
//      insert curEmail into newMap[parent]

//  newMap at this point                           (1's parent is 0)
//  0 -> johnsmith@mail.com, john_newyork@mail.com, john00@mail.com
//  2 -> mary@mail.com
//  3 -> johnnybravo@mail.com

//  Now that we've finished merging all the accounts, just need to format result
//  Make results vec
//  Loop through newMap
//      curString = newMap[i].first
//      Loop through the emails
//          curString += newMap[i].second[j]
//      results += curString
//  return results

//  ^^^ this thinking and writing took 25 minutes on the dot
//  Coded and accepted in 30 minutes on the dot
//  + union by rank in 5 minutes
//  Solved in 1 hour total :D

//  Time - O(nlogn)
//      Union and find operations come out to O(1) due to path compression and union by rank
//      so the time comes down to the main function
//      where the slowest operation is sorting within a loop, nlogn
//  Space - O(n)
//      Just storing copies of everything in the input array

//  I could be a bit clearer with splitting n into emails, accounts, etc but i am hungry and need to dip

class DSU
{
public:
    DSU(int size)
    {
        for (int i = 0; i < size; i++)
        {
            parent.push_back(i);
            rank.push_back(1);
        }
    }

    int findRoot(int node)
    {
        if (node == parent[node])
        {
            return node;
        }
        parent[node] = findRoot(parent[node]); //  path compression
        return parent[node];
    }

    bool unionSubset(int x, int y)
    {
        int parentX = findRoot(x);
        int parentY = findRoot(y);

        if (parentX == parentY)
        {
            return false; //  they're already connected
        }

        //  Union by rank (smaller subset gets absorberd into larger one)
        if (rank[parentX] > rank[parentY])
        {
            parent[parentY] = parentX;
            rank[parentX] += parentY;
        }
        else
        {
            parent[parentX] = parentY;
            rank[parentY] += parentX;
        }

        return true;
    }

private:
    vector<int> parent;
    vector<int> rank;
};

class Solution
{
public:
    vector<vector<string>> accountsMerge(vector<vector<string>> &accounts)
    {
        DSU dsu(accounts.size());
        unordered_map<string, int> emailToAccount;
        unordered_map<int, vector<string>> accountToEmails;
        vector<vector<string>> result;

        for (int i = 0; i < accounts.size(); i++)
        {
            for (int j = 1; j < accounts[i].size(); j++)
            {
                string curEmail = accounts[i][j];

                if (emailToAccount.find(curEmail) != emailToAccount.end())
                {
                    dsu.unionSubset(i, emailToAccount[curEmail]);
                }
                else
                {
                    emailToAccount[curEmail] = i;
                }
            }
        }

        for (auto it = emailToAccount.begin(); it != emailToAccount.end(); it++)
        {
            int curParent = dsu.findRoot(it->second);
            accountToEmails[curParent].push_back(it->first);
        }

        for (auto it = accountToEmails.begin(); it != accountToEmails.end(); it++)
        {
            string curAccountName = accounts[it->first][0];
            vector<string> curAccountEmails;
            vector<string> curAccountResult;

            for (int i = 0; i < it->second.size(); i++)
            {
                curAccountEmails.push_back(it->second[i]);
            }

            sort(curAccountEmails.begin(), curAccountEmails.end());
            curAccountResult.push_back(curAccountName);

            for (int i = 0; i < curAccountEmails.size(); i++)
            {
                curAccountResult.push_back(curAccountEmails[i]);
            }

            result.push_back(curAccountResult);
        }

        return result;
    }
};