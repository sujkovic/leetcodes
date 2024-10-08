//  create frequency map of how many of each number there are
//  create priority queue, adding all of them to it
//  pop off the top k elements of the priority queue and return them

class Solution
{
public:
    vector<int> topKFrequent(vector<int> &nums, int k)
    {
        unordered_map<int, int> freq;
        priority_queue<pair<int, int>> queue;
        vector<int> res;

        for (int i = 0; i < nums.size(); i++)
        {
            freq[nums[i]]++;
        }

        for (auto it = freq.begin(); it != freq.end(); it++)
        {
            queue.push({it->second, it->first});
        }

        while (k > 0)
        {
            res.push_back(queue.top().second);
            queue.pop();
            k--;
        }

        return res;
    }
};