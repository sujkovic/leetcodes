//  Solved December 21st, 2023

//  make a onss vec and a zeroes vec
//  for zeroes, starting from left
//      keep track of num zeroes seen so far at cur index
//  for ones, starting from right
//      keep track of num ones seen so far at cur index
//  have a res var that keeps track of best place to split
//  loop through these vecs in opposite order
//  on each iteration
//      update res with max(res, zerose[i] + ones[i + 1])

//  Time - O(n) - iterate through input of size n twice
//  Space - O(n) - two new vecs, both of size n 

//  Solved in 12 minutes

class Solution {
public:
    int maxScore(string s) {
        int len = s.length();
        int onesCount = 0;
        int zeroesCount = 0;
        int left = 0;
        int right = len - 1;
        int res = 0;

        vector<int> zeroes(len, 0);
        vector<int> ones(len, 0);

        for (; left < s.length(); left++) {
            if (s[left] == '0') {
                zeroesCount++;
            }
            if (s[right] == '1') {
                onesCount++;
            }
            zeroes[left] = zeroesCount;
            ones[right] = onesCount; 
            right--;
        }

        for (int i = 0; i < zeroes.size() - 1; i++) {
            res = max(res, zeroes[i] + ones[i + 1]);
        }

        return res;
    }
};


//  Solved January 1st, 2025

//  want to maximize zeroes in left and ones in right
//  looks like you could do a prefix sum to keep track of the current zeroSum and current oneSum
//  ex.
//  input   0 1 1 1 0 1
//  zeroSum 1 1 1 1 2 2
//  oneSum  0 1 2 3 3 4
//  so at any index i, say we start at i = 1, cur score is zeroSum[i - 1] + oneSum[n - 1] - oneSum[n]

//  Solved in 19 min
//      Was basically done at 8 min but my formula was just a little off and the fix i made was also wrong
//      i just had to think for a sec and instead tried brute forcing 
//  Time - O(n)
//  Space - O(n)

/*
class Solution {
public:
    int maxScore(string s) {
        int maxScore = 0;
        int curZeroSum = 0;
        int curOneSum = 0;
        vector<int> zeroSum;
        vector<int> oneSum;

        for (int i = 0; i < s.length(); i++) {
            if (s[i] == '0') {
                curZeroSum++;
            }
            else {
                curOneSum++;
            }

            zeroSum.push_back(curZeroSum);
            oneSum.push_back(curOneSum);
        }

        for (int i = 1; i < s.length(); i++) {
            int curScore = zeroSum[i - 1] + oneSum[s.length() - 1] - oneSum[i - 1];
            maxScore = max(maxScore, curScore);
        }

        return maxScore;        
    }
};
*/

//  Forgot you can optimize the space here since you dont need a whole vector
//  can just get the total count of 1s beforehand, and initialize zero count to zero
//  then iterate through the array, incrementing zero when you see zero, and decrementing 1 for 1
//  and update the cur max
//  ex.
//  0 1 1 1 0 1
//  i            1, 4
//    i          1, 3
//      i        1, 2
//        i      1, 1
//          i    2, 1

//  Solved in 5 min
//  Time - O(n)
//  Space - O(1)

class Solution {
public:
    int maxScore(string s) {
        int maxScore = 0;
        int zeroes = 0;
        int ones = 0;

        for (int i = 0; i < s.length(); i++) {
            if (s[i] == '1') {
                ones++;
            }
        }

        for (int i = 0; i < s.length() - 1; i++) {
            if (s[i] == '0') {
                zeroes++;
            }
            else {
                ones--;
            }

            maxScore = max(maxScore, zeroes + ones);
        }

        return maxScore;
    }
};