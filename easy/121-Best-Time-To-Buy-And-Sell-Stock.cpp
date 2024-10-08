class Solution
{
public:
    int maxProfit(vector<int> &prices)
    {
        int curMin = prices[0];
        int res = 0;
        for (int i = 0; i < prices.size(); i++)
        {
            res = max(res, prices[i] - curMin);
            curMin = min(curMin, prices[i]);
        }

        return res;
    }
};