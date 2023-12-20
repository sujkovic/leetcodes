//  find 2 smallest numbers in prices
//  return money - those numbers

//  Time - O(n) - two passes thru array of size n
//  Space - O(1) - no nwe data struct

//  Solved in 6 min

class Solution
{
public:
    int buyChoco(vector<int> &prices, int money)
    {
        int minOne = INT_MAX;
        int minOneIndex = 0;
        int minTwo = INT_MAX;
        int moneyLeft;

        for (int i = 0; i < prices.size(); i++)
        {
            if (prices[i] < minOne)
            {
                minOne = prices[i];
                minOneIndex = i;
            }
        }

        for (int i = 0; i < prices.size(); i++)
        {
            if (prices[i] < minTwo && i != minOneIndex)
            {
                minTwo = prices[i];
            }
        }

        moneyLeft = money - minOne - minTwo;
        if (moneyLeft >= 0)
        {
            return moneyLeft;
        }
        else
        {
            return money;
        }
    }
};