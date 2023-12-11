//  iterate through array, keeping track of the number of occurences of the current element
//  if num occurences / arr.size() > .25, return the num

//  Solved in 4 minutes

//  Time - O(n) - one pass through input arr
//  Space - O(1) - no added data structs

class Solution {
public:
    int findSpecialInteger(vector<int>& arr) {
        int freq = 1;
        for (int i = 1; i < arr.size(); i++) {
            if (arr[i] == arr[i - 1]) {
                freq++;
            }
            else {
                freq = 1;
            }
            if ((double)freq / (double)arr.size() > .25) {
                return arr[i];
            }
        }
        return arr[0];
    }
};