//  make vector of numbers from 1 to n
//  have an outer loop, while n.size() > 1
//      loop from cur ptr, incrementing through circle k times
//          once we hit k times, remove cur item, break from loop
//  return the only item left in vector


//  Time Complexity - O(n * k) 
//      Loop through loop of at most size n k times
//  Space Complexity - O(n)
//      Vector of n ints
//  Solved in 20 minutes

class Solution {
public:
    int findTheWinner(int n, int k) {
        vector<int> vec;
        int ptr = 0;

        for (int i = 1; i <= n; i++) {
            vec.push_back(i);
        }

        while (vec.size() > 1) {
            int count = 1;

            while (count < k) {
                ptr++;
                count++;

                if (ptr >= vec.size()) {
                    ptr = 0;
                }
            }

            vec.erase(vec.begin() + ptr);
            if (ptr >= vec.size()) {
                ptr = 0;
            }
        }
        
        return vec[0];
    }
};
