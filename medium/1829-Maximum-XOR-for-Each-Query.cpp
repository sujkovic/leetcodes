//  00
//  01
//  01
//  11
//  __
//  11      <- XOR

//  a few examples for maximizixing xor
//  Given, k, result
//  11 -> 00 -> 11
//  10 -> 01 -> 11
//  01 -> 10 -> 11
//  00 -> 11 -> 11
//  So you just want to set all the bits in k to OPPOSITE the corresponding bit in og number
//  I think you could just loop through the og number, bitshifting to the right 1 in every iteration
//  Also keep track of the current bit place (starting at 0)
//      if the current bit is a 1
//          do nothing
//      else if its a 0
//          add 2^curBit to k
//  Repeat for size of nums, popping the last element every iteration

//  Finished in 21 min, TLE on 79/86

/*
class Solution {
public:
    vector<int> getMaximumXor(vector<int>& nums, int maximumBit) {
        vector<int> res;

        while (!nums.empty()) {
            int arrayXOR = nums[0];
            int curBit = 0;
            int k = 0;

            //  First calculate the xor of the array
            for (int i = 1; i < nums.size(); i++) {
                arrayXOR = arrayXOR ^ nums[i];
            }

            cout << arrayXOR << " ";
            while (curBit < maximumBit) {
                if (arrayXOR % 2 == 0) {
                    k += pow(2, curBit);
                }

                curBit++;
                arrayXOR = arrayXOR >> 1;
            }

            res.push_back(k);
            nums.pop_back();
        }

        return res;
    }
};
*/

//  Just realized you dont need the double loops, can just go one by one in the array
//  and get the result for the elements seen so far

//  Solved in 12 min

class Solution
{
public:
    vector<int> getMaximumXor(vector<int> &nums, int maximumBit)
    {
        vector<int> res;
        int curArrayXOR = -1;

        for (int i = 0; i < nums.size(); i++)
        {
            int k = 0;
            int curBit = 0;

            if (curArrayXOR == -1)
            {
                curArrayXOR = nums[i];
            }
            else
            {
                curArrayXOR = curArrayXOR ^ nums[i];
            }

            int curArrayXORCopy = curArrayXOR;

            while (curBit < maximumBit)
            {
                if (curArrayXORCopy % 2 == 0)
                {
                    k += pow(2, curBit);
                }

                curBit++;
                curArrayXORCopy = curArrayXORCopy >> 1;
            }

            res.push_back(k);
        }

        reverse(res.begin(), res.end());
        return res;
    }
};

//  Watched the neetcode vid and apprantley you can literally just xor with 2^maxbit - 1 ????????
//  i really dont understand how that works for the case of 1^1 which results in 0
//      which is suboptimal cause you'd want to do 1^0 which results in 1, and 1 > 0
//  but it works..either i need to study more or this question wording is horrible idek

/*
class Solution {
public:
    vector<int> getMaximumXor(vector<int>& nums, int maximumBit) {
        vector<int> res;
        int curArrayXOR = -1;

        for (int i = 0; i < nums.size(); i++) {
            int k = 0;
            int curBit = 0;

            if (curArrayXOR == -1) {
                curArrayXOR = nums[i];
            }
            else {
                curArrayXOR = curArrayXOR ^ nums[i];
            }

            res.push_back(res.push_back(curArrayXOR ^ ((int)pow(2, maximumBit) - 1)););
        }

        reverse(res.begin(), res.end());
        return res;
    }
};
*/