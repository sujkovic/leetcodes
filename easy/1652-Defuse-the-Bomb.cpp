//  have the entire function be 3 cases
//  vector<int> res
//  case 1 - k > 0
//      for int i = 0 to code size - 1 in code    -> for each number
//          sum = 0
//          int kCount = 0
//          j = i + 1
//          while (kCount > 0)
//              if (j == numsSize)
//                  j = 0
//              sum += nums[j]
//              res[i] = sum
//              j++
//              kCount--
//          res[i] = sum
//  caes 2 - k < 0
//      same logic but j-- instead of ++ and change the out of bounds condition
//  case 3 - k == 0
//      just set the entire array to 0

//  Solved in 16 min
//      forgot to do k < 0 and k-- for case 2
//  Time - O(n * k)
//  Space - O(1)

/*
class Solution {
public:
    vector<int> decrypt(vector<int>& code, int k) {
        int length = code.size();
        vector<int> res(length, 0);
        if (k > 0) {
            for (int i = 0; i < length; i++) {
                int sum = 0;
                int kCount = k;
                int j = i + 1;

                while (kCount > 0) {
                    if (j == length) {
                        j = 0;
                    }

                    sum += code[j];
                    j++;
                    kCount--;
                }

                res[i] = sum;
            }
        }
        if (k < 0) {
            for (int i = 0; i < length; i++) {
                int sum = 0;
                int kCount = k;
                int j = i - 1;

                while (kCount < 0) {
                    if (j == -1) {
                        j = length - 1;
                    }

                    sum += code[j];
                    j--;
                    kCount++;
                }

                

                res[i] = sum;
            }
        }

        return res;
    }
};
*/

//  Going to optimize
//  5 7 1 4 3      k = 2,  sum = 20
//  8 5 7 8 12

//  ok i think you can just get the sum of the subarray of size k before/after i
//  so at i = 0, set res[i] to nextKSum - code[i]
//  ok i get it so we'll have a left and right pointer
//  our window will be of size k + 1
//  and our sum will be the current sum of that window
//  so for left = 0, 
//      windowSum = windowSum + code[right] - code[left] (move window forward 1)
//      res[left] = windowSum
//      right = (right + 1) % codeSize
//      left = (left + 1) % codeSize
//  we'll precompute the first window of size k before entering the main loop
//  iterating backwards would be right = (right + (codeSize - 1)) % codeSize


//  Solved in 40 min
//      again forgot that k is negative so just set it to its abs val for case 2
//  Time - O(n)
//  Space - O(1)

class Solution {
public:
    vector<int> decrypt(vector<int>& code, int k) {
        int codeSize = code.size();
        vector<int> res(codeSize, 0);
        if (k > 0) {
            int windowSum = 0;
            int left = 0;
            int right = k;
            int iterations = 0;

            //  Precompute first window of size k
            for (int i = 0; i < k; i++) {
                windowSum += code[i];
            }

            while (iterations < codeSize) {
                windowSum = windowSum + code[right] - code[left];
                res[left] = windowSum;
                //  iterate left and right by 1
                right = (right + 1) % codeSize;
                left = (left + 1) % codeSize; 
                iterations++;
            }
        }
        if (k < 0) {
            k = abs(k);
            int windowSum = 0;
            int right = 0;
            int left = (right + (codeSize - k)) % codeSize;
            int kCount = 0;
            int iterations = 0;

            //  Precompute first window of size k
            for (int i = 0; i != left; i = (i + (codeSize - 1)) % codeSize) {
                windowSum += code[i];
            }

            while (iterations < codeSize) {
                windowSum = windowSum + code[left] - code[right];
                res[right] = windowSum;
                //  iterate left and right by 1
                right = (right + (codeSize - 1)) % codeSize;
                left = (left + (codeSize - 1)) % codeSize; 
                iterations++;
            }
        }

        return res;
    }
};