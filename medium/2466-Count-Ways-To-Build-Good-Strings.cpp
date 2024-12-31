//  looks like dp and they basically gave us the branch condition for the dfs solution
//  ex. low = 3, high = 3, zero = 1, one = 1
//                                                  []
//                             0                                             1
//                 00                        01                   10                       11
//      000                001      010           011     100           101      110              111
//       |                  |        |         valid    too big      too big   too big         too big
//     .....
//  so each iteration we'll update our curnum to:
//      zero -> num << zero
//      one -> loop for one iterations, each iterationg do num + 1, num << 1
//  we will also need some way to break out of the branch of only zeroes somehow
//  will leave that for last cause im not entirely sure (maybe keep track of # bits)

//  bruh 25 minutes in my code is just not working so i watched the neetcode vid and realized i misread 
//  the instructions thinking low and high were the values of the number not the length it bruh

/*
#define MODULO (% (1000000000 + 7))

class Solution {
public:
    int dfs(int &low, int &high, int &zero, int &one, int numBits, int num, int &res) {
        // 
        cout << num << endl;
        if (num > high || pow(2, numBits + 1) > 10000) {
            return 0;
        }
        if (low <= num && num <= high) {
            res++;
        }

        int appendZero = num << zero;
        int appendOne = num;
        while (one) {
            appendOne += 1;
            appendOne << 1;
            one--;
        }
        return dfs(low, high, zero, one, numBits + 1, appendZero, res) + 
                dfs(low, high, zero, one, numBits + 1, appendOne, res);
    }
    int countGoodStrings(int low, int high, int zero, int one) {
        int res = 0;
        dfs(low, high, zero, one, 0, 0, res);
        return res;
    }
};
*/

//                                                 []
//                          0                                                   1
//           00                         01                      10                          11
//     000         001          010           011       100           101           110          111
//  so the answer is just 8 since there are 8 possible strings of length 3
//  so we really just need to keep track of a length variable 
//  base cases
//      length is between low and high -> res += 1
//      length > high -> return

//  Finished in 6 min, TLE
//  Time - O(2^high)
//  Space - O(high)

/*
#define MODULO (1000000000 + 7)

class Solution {
public:
    void dfs(int &low, int &high, int &zero, int &one, int length, long long &res) {
        if (length > high) {
            return;
        }
        if (low <= length && length <= high) {
            res++;
        }

        dfs(low, high, zero, one, length + zero, res);
        dfs(low, high, zero, one, length + one, res);
    }
    int countGoodStrings(int low, int high, int zero, int one) {
        long long res = 0;
        dfs(low, high, zero, one, 0, res);
        return res % MODULO;
    }
};
*/

//  Memoize
//  Solved in 9 minutes
//      had to rewrite the function to return a value cause i did it the lazy way originally
//      and had to add another modulo to the main return
//  Time - O(high)
//  Space - O(high)

#define MODULO (1000000000 + 7)

class Solution {
public:
    int dfs(int &low, int &high, int &zero, int &one, int length, vector<int> &memo) {
        if (length > high) {
            return 0;
        }

        if (memo[length] != -1) {
            return memo[length];
        }

        bool isLengthValid = (low <= length && length <= high) ? true : false;
        int appendZero = dfs(low, high, zero, one, length + zero, memo) % MODULO;
        int appendOne = dfs(low, high, zero, one, length + one, memo) % MODULO;

        memo[length] = isLengthValid + appendZero + appendOne;
        return memo[length];
    }
    int countGoodStrings(int low, int high, int zero, int one) {
        vector<int> memo(high + 1, -1);
        return dfs(low, high, zero, one, 0, memo) % MODULO;
    }
};