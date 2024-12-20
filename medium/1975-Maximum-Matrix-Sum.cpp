//  1 -1     1 1
// -1  1  -> 1 1

//  1  2  3        1 2 3
// -1 -2 -3   ->  -1 2 3
//  1  2  3        1 2 3

//  So the problem basically becomes make as many negatives positive as you can,
//  and prioritize the largest magnitudes first

//  checked the discussion, didn't rly get any meaningful hints but saw people saying this is way 
//      easier than it seems so literally just looked at the problem more simply and it worked lol

//  scratch all the above, i think you're basically guaranteed to be able 
//  to reduce the matrix down to either 1 or 0 negative numbers
//  and i think its literally just a matter of how many negative numbers are there
//  if its an even amount, you can always get to a matrix with no negatives
//  if its an odd number, you will have one negative, so pick the lowest abs val of a #

//  and first get the count of negatives, the total matrix absolute val sum, and the min abs val

//  22 min
//  failing this test case
//  -1  0 -1
//  -2  1  3
//   3  2  2
//  watched the neetcode vid to see why (i thought we had to check for zeroes or smtn)
//  and realized while watching it i just want the smallest abs value of ANY NUMBER, 
//  not just the smallest abs val of a negative, since we can flip any number we want 

class Solution {
public:
    long long maxMatrixSum(vector<vector<int>>& matrix) {
        int rows = matrix.size();
        int cols = matrix[0].size();

        int negativeCount = 0;
        long long sum = 0;
        int smallestMagnitude = INT_MAX;

        for (int row = 0; row < rows; row++) {
            for (int col = 0; col < cols; col++) {
                if (matrix[row][col] < 0) {
                    negativeCount++;
                }
                smallestMagnitude = min(smallestMagnitude, abs(matrix[row][col]));
                sum += abs(matrix[row][col]);
            }
        }

        if (negativeCount % 2 == 1) {
            return sum - (smallestMagnitude * 2);
        }

        return sum;
    }
};