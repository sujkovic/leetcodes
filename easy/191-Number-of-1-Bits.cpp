//  make a while loop for n != 0
//      if n % 2 == 1, increment res by 1
//      shift n right by 1
//  return res

//  Time - O(logn)
//      keep dividing integer n by 2
//  Space - O(1)
//      no new data structs

//  Solved in 1 minute 30 seconds lol

class Solution
{
public:
    int hammingWeight(uint32_t n)
    {
        int result = 0;
        while (n != 0)
        {
            if (n % 2 == 1)
            {
                result++;
            }
            n = n >> 1;
        }
        return result;
    }
};