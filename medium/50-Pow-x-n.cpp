//  First check if n is negative
//  Keep a bool ^ and do 1 / result at the end if so
//  Then set n to positive to make calculations easier
//  Power of a number is just the number x, multipied by itself n times
//  Base case n = 0 -> result = 1
//  Base case x = 0 -> result = 0

//  For the calculation
//  double res = x
//  while (n > 1)
//      res *= x
//  return res

//  Solved in 12 min, TLE
//  Time - O(n)
//  Space - O(1)

/*
class Solution {
public:
    double myPow(double x, int n) {
        double res = x;
        bool isNegative = false;

        // Base cases - x = 0, n = 0, n is negative
        if (n < 0) {
            isNegative = true;
            n = abs(n);
        }
        if (x == 0) {
            return 0;
        }
        if (n == 0) {
            return 1;
        }

        while (n > 1) {
            res *= x;
            n--;
        }

        if (isNegative) {
            res = 1 / res;
        }

        return res;
    }
};
*/


//  Had to watch the neetcode vid for the hint but you can split up the work into a logn time complexity
//  ex. x = 2 n = 10
//  this becomes 2 * 2 * 2 * 2 * 2 * 2 * 2 * 2 * 2 * 2
//  = 2^5 * 2^5
//  = 2^3 * 2^2 * 2^3 * 2^2
//  basically can just call recursively and memoize
//  recursivePow(x, n)
//      if x == 0 return 0
//      if n == 0 return 1
//      if n == 1 return x
//
//      int half = n / 2
//      bool odd = n % 2 == 1    (c++ divsion rounds down, so in the case of odd number, add 1 to one of the calls)
//      return recursivePow(x, half) * recursivePow(x, half + odd)

//  Finished in 10 min, TLE
//  Time O(n)
//  Space O(n)

/*
class Solution {
public:
    double recursivePow(double x, int n) {
        if (x == 0) {
            return 0;
        }
        if (n == 0) {
            return 1;
        }
        if (n == 1) {
            return x;
        }

        int half = n / 2;
        bool odd = (n % 2 == 1);
        return recursivePow(x, half) * recursivePow(x, half + odd);
    }
    double myPow(double x, int n) {
        int isNNegative = (n < 0);
        n = abs(n);
        double res = recursivePow(x, n);
        return isNNegative ? (1 / res) : res;
    }
};
*/

//  Memoize
//  This fails the case of x = 2, n = -2147483648 by outputting 1 instead of 0, im lost

/*
class Solution {
public:
    double recursivePow(unordered_map<int, double> &memo, double x, long n) {
        if (x == 0) {
            return 0;
        }
        if (n == 0) {
            return 1;
        }
        if (n == 1) {
            return x;
        }
        if (memo.find(n) != memo.end()) {
            return memo[n];
        }

        int half = n / 2;
        bool odd = (n % 2 == 1);
        memo[n] = recursivePow(memo, x, half) * recursivePow(memo, x, half + odd);
        return memo[n];
    }
    double myPow(double x, int n) {
        if (n < INT_MIN) {
            return 0;
        }
        unordered_map<int, double> memo;
        int isNNegative = (n < 0);
        n = abs(n);
        double res = recursivePow(memo, x, (long)n);
        return isNNegative ? (1 / res) : res;
    }
};
*/


//  Total time spent after watching the neetcod vid is about 20 min
//  Redid it his way thinking something might be wrong with mine, 
//  just to realize its because n was overflowing and all i had to do 
//  was make the n parameter in my recursive function a long, and cast 
//  the n to a long when we originally call it
//  That caused me 12 min of confusion
//  But my code works just as efficiently 

class Solution {
public:
    double recursivePow(double x, long n) {
        if (n == 0) {
            return 1;
        }

        double half = recursivePow(x, n / 2);
        bool odd = (n % 2 == 1);
        return odd ? x * half * half : half * half;
    }
    double myPow(double x, int n) {
        if (x == 0) {
            return 0;
        }
        if (n == 0) {
            return 1;
        }

        int isNNegative = (n < 0);
        n = abs(n);
        double res = recursivePow(x, (long)(n));
        return isNNegative ? (1 / res) : res;
    }
};
