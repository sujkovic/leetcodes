//  First, get the number of set bits in num2
//    can just do while num2, if numw2 % 2 == 1, setBits++, then num2 >>= 1
//  Then, get both the number of set bits in num1, and the total number of bits
//  actually we could honestly just store num2 as a vector of 0/1
//  then loop through the vec, converting all 1's to 0's for the # of setbits we have in num2 (from most sig to least)
//  then if there's still setbits left over, set 0'1s to wins again most sig to least
//  then if there's still setbits, add 1's to most sig 

//  Solved in 45 min
//      Had a bunch of mistakes with logic as can be seen by this ^ being different from the final solution
//      ig i also havent done a bit problem in months 
//  Time - O(1)
//      The loop iterations are just the # of bits in the input numbers which never exceeds 28
//  Space - O(1)
//      vector size never goes above 28

class Solution {
public:
    int getNumSetBits(int num) {
        int setBits = 0;

        while (num) {
            setBits += (num % 2);
            num = num >> 1;
        }
        
        return setBits;
    }
    vector<int> getVecNum(int num) {
        vector<int> vecNum;

        while (num) {
            vecNum.push_back(num % 2);
            num = num >> 1;
        }

        return vecNum;
    }
    int minimizeXor(int num1, int num2) {
        int setBits = getNumSetBits(num2);
        vector<int> vecNum1 = getVecNum(num1);
        vector<int> x(vecNum1.size(), 0);

        for (int i = x.size() - 1; i >= 0; i--) {
            if (setBits <= 0) {
                break;
            }
            if (vecNum1[i] == 1) {
                x[i] = 1;
                setBits--;
            }
        }


        //  if leftover setbits, we now want to place in least significant place to minimize number
        for (int i = 0; i < x.size(); i++) {
            if (setBits <= 0) {
                break;
            }
            if (vecNum1[i] == 0) {
                x[i] = 1;
                setBits--;
            }
        }

        //  And then if there are still set bits we just add them to the most significant since nothing else to do
        while (setBits) {
            x.push_back(1);
            setBits--;
        }

        int numPlace = 1;
        int result = 0;

        for (int i = 0; i < x.size(); i++) {
            result += x[i] * numPlace;
            numPlace *= 2;
        }

        return result;
    }
};