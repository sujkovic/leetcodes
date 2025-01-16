//  i think this is just a double for loop and keep xoring every pair 

//  Finished in 4 min, TLE damn
//  Time - O(m * n)
//  Space - O(1)

/*
class Solution {
public:
    int xorAllNums(vector<int>& nums1, vector<int>& nums2) {
        int totalXOR = 0;

        for (int i = 0; i < nums1.size(); i++) {
            for (int j = 0; j < nums2.size(); j++) {
                totalXOR = totalXOR ^ nums1[i] ^ nums2[j];
            }
        }

        return totalXOR;
    }
};
*/
//  ex. nums1 = [3, 6]  nums2 = [9, 1]
//         = [0011, 0101]    [1001, 0001]
//  0011 ^ 1001 = 1010
//  0011 ^ 0001 = 0010
//  0101 ^ 1001 = 1100
//  0101 ^ 0001 = 0100
//  Then xor all the results above, 1000
//  or, lets say we just xor all the numbers in one go
//  0011
//  0101
//  1001
//  0001
//  ----
//  1110
//  nope i dont think this works let me try it anyways tho incase i messed up
//  yeah nah, spent like 7 min on this
/*
class Solution {
public:
    int xorAllNums(vector<int>& nums1, vector<int>& nums2) {
        int totalXOR = 0;

        for (int i = 0; i < nums1.size(); i++) {
            totalXOR = totalXOR ^ nums1[i];
        }

        for (int i = 0; i < nums2.size(); i++) {
            totalXOR = totalXOR ^ nums2[i];
        }

        return totalXOR;
    }
};
*/

//  Wow watched the neetcode video and i probably wouldve never thought of this idea
//  Can explain it as, given array n and m, where the values are n1, n2...   m1, m2...
//  if we look at n1 for example, we have to do all the following operations
//  n1 ^ m1
//  n1 ^ m2
//   ....
//  n1 ^ mwhatever
//  now given the properties of xor, if we xor the same number with itself, we get zero
//  SO if the input array m is of EVEN LENGTH, n1 gets XORed with itself an EVEN amount of times,
//  which reduces this entire expression above to just ZERO
//  that is pretty cool
//  So the solution is basically if both arrays are even length, the answer is zero
//  if one is of odd length, the answer is the xor of all numbers in that array
//  and then if both are odd length, xor all the numbers O(m + n)

//  Solved in 12 min
//      Only thing i messed up was it should be that if nums2 is even, we ignore the OTHER array, not vice versa
//      messed up my math there
//  Time - O(m + n)
//  Space - O(1)

class Solution {
public:
    int xorAllNums(vector<int>& nums1, vector<int>& nums2) {
        bool nums1Even = !(nums1.size() % 2);
        bool nums2Even = !(nums2.size() % 2);
        int nums1XOR = 0;
        int nums2XOR = 0;

        if (nums1Even && nums2Even) {
            return 0;
        }

        //  only compute xor of an array if its length is odd
        if (!nums1Even) {
            for (int i = 0; i < nums2.size(); i++) {
                nums2XOR ^= nums2[i];
            }
        }
        if (!nums2Even) {
            for (int i = 0; i < nums1.size(); i++) {
                nums1XOR ^= nums1[i];
            }
        }

        return nums1XOR ^ nums2XOR;
    }
};