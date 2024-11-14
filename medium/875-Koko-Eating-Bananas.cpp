//  if piles size == h, k = biggest pile
//  looks like we want to split up the biggest piles
//  11, 7, 6, 3     h = 8
//  4, 4, 3, 4, 3, 3, 3, 3
//  ^ idk how to get this tho

//  ok checked neetcode vid, gonna try brute force
//  k can be any value from 1 to the max value in piles
//  ex. 100, 1, 1, 1     h = 4    ->   k = 100
//  ex. 4                h = 4    ->   k = 1

//  ex. 3, 6, 7, 11    h = 8
//  k = 1 -> 27 hours to eat all bananas
//  k = 2 -> 2 + 3 + 4 + 6 = 15 hours
//  k = 3 -> 1 + 2 + 3 + 4 = 10 hours
//  k = 4 -> 1 + 2 + 2 + 3 = 8 hours -> return

//  Finished in ~15 min, TLE
//  O(piles size * max pile) time

/*
class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int pilesMax = 0;
        for (int i = 0; i < piles.size(); i++) {
            pilesMax = max(pilesMax, piles[i]);
        }

        for (float i = 1; i <= pilesMax; i++) {
            long long numHours = 0;
            for (int j = 0 ; j < piles.size(); j++) {
                numHours += ceil(float(piles[j]) / i);
            }

            if (numHours <= h) {
                return i;
            }
        }

        return -1;
    }
};
*/


//  now how can we optimize the above solution
//  ok so looking at the example i worked through, we see that the result k 
//  is at about halfway through the possible values
//  so instead of looping through all k values, then calculating the sum,
//  we could binary search through through the k values
//  and for each iteration of binary search, calcuate the sum, 
//  and narrow down our search range based on that

//  Solved in 20 min
//      work on edge cases like int overflow and DONT use floats, use double
//  Time - O(log(maxPile) * piles size)
//  Space - O(1)

class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int pilesMax = 0;
        for (int i = 0; i < piles.size(); i++) {
            pilesMax = max(pilesMax, piles[i]);
        }

        int left = 1;
        int right = pilesMax;
        int res = pilesMax;

        while (left <= right) {
            int mid = (right + left) / 2;
            long long totalHours = 0;

            //  calculate current k
            for (int i = 0; i < piles.size(); i++) {
                totalHours += ceil(double(piles[i]) / mid);
            }

            if (totalHours <= h) {
                right = mid - 1;
                res = min(res, mid);
            }
            else {
                left = mid + 1;
            }
        }

        return res;
    }
};