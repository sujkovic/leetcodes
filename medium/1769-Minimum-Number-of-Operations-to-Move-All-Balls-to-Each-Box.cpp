//  Brute force
//  Basically the answer at each answer[i] is going to be 
//      the distance between i and all j such that boxes[j] == 1
//  for i = 0 to boxeslength - 1
//      curRes
//      for j = 0 to i - 1
//          if boxes[j] == 1
//              curRes += (i - j)
//      for j = i + 1 to boxeslength - 1
//          if boxes[j] == 1
//              curRes += (j - i)
//      answer[i] = curRes

//  Solved in 12 min
//      no idea why they accepted the n^2 solution theres gotta be a O(n) lol
//      half of that was debugging the fact that i was doing boxes[j] == 1 instead of == '1' :|
//      and then also did < i - 1 in the first inner loop instead of i but figured that out quick
//          since if i ran second test case, only the second half of output was wrong 
//  Time - O(n^2)
//  Space - O(1)

/*
class Solution {
public:
    vector<int> minOperations(string boxes) {
        vector<int> res;

        for (int i = 0; i < boxes.size(); i++) {
            int curRes = 0;
            cout << i << endl;

            for (int j = 0; j < i; j++) {
                if (boxes[j] == '1') {
                    curRes += (i - j);
                }
            }

            for (int j = i + 1; j < boxes.size(); j++) {
                if (boxes[j] == '1') {
                    curRes += (j - i);
                }
            }

            res.push_back(curRes);
        }

        return res;
    }
};
*/


//  Optimized

//  first thought is prefix sum (def biased cause the last 4 dailys have been prefix sum but o well)
//  ex.
//  boxes      0 0 1 0 1 1
//  prefixsum  0 0 1 1 2 3   <- wont work need to know distance
//  prefixsum  0 0 2 2 6 11  <- also wont work bc need to know # of 1 boxes, not just distance sum
//  prefixsum  (0 0) (0 0) (2 1) (2 1) (6 2) (11 3)   <- (total distance, # 1 boxes)
//  result    11 8 5 4 - 4

//  ^ spent 13 min on the above, dont think this is working

//  Watched the neetcode vid but it did not make much sense to me other than use prefix and postfix

//  boxes     0 0 1 0 1 1
//  prefix              0  -> build starting from right
//                      i  prefixsum = 0, balls = 1
//                    i    prefixsum = prefixsum + balls = 1, balls = 2
//                  i      prefixsum = prefixsum + balls = 3, balls = 2
//                i        prefixsum = prefixsum + balls = 5, balls = 3
//              i          prefixsum = prefixsum + balls = 8, balls = 3
//            i            prefixsum = prefixsum + balls = 11, balls = 3
//  postfix   0 0 0 1 2 4  -> build starting from left
//            i            postfixsum = postfixsum + balls = 0, balls = 0
//              i          postfixsum = postfixsum + balls = 0, balls = 0
//                i        postfixsum = postfixsum + balls = 0, balls = 1
//                  i      postfixsum = postfixsum + balls = 1, balls = 1
//                    i    postfixsum = postfixsum + balls = 2, balls = 2
//                      i  postfixsum = postfixsum + balls = 4, balls = 3

//  Ok after like 22 minutes of trying to understand the neetcode method i was lost 
//  so tried just renaming and rethinking it how i thought made sense and got it working woah

//  Solved in 13 min after going down my own thought process and variables
//      still total of like 13 + 22 + 13 ~= 48
//  Time - O(n)
//  Space - O(n)
//  Could do in O(1) space with using the result vec as prefixsum array 
//  and then just adding the postfixsum calculations directly to the prefixsum
//  but ive spent like an hour or 2 on this problem today im tapped out

class Solution {
public:
    vector<int> minOperations(string boxes) {
        vector<int> res;
        int curPrefixSum = 0;
        vector<int> prefixSum;
        int balls = 0;

        for (int i = 0; i < boxes.length(); i++) {
            curPrefixSum = curPrefixSum + balls;
            prefixSum.push_back(curPrefixSum);

            if (boxes[i] == '1') {
                balls++;
            }
        }

        int curPostfixSum = 0;
        vector<int> postfixSum;
        balls = 0;

        for (int i = boxes.length() - 1; i >= 0; i--) {
            curPostfixSum = curPostfixSum + balls;
            postfixSum.push_back(curPostfixSum);

            if (boxes[i] == '1') {
                balls++;
            }
        }

        reverse(postfixSum.begin(), postfixSum.end());

        for (int i = 0; i < postfixSum.size(); i++) {
            res.push_back(postfixSum[i] + prefixSum[i]);
        }

        return res;
    }
};