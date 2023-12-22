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