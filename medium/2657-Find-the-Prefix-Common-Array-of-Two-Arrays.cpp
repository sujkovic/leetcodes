//  i think its literally just keep a set of numbers seen so far
//  loop through the arrays together
//  on each iteration
//      try to add a[i] and b[i] to the set, if either exists already,
//      common++
//      then add wtv common is at to res

//  Solved in 9 min
//      4 of that was I forgot the case of A[i] == B[i]
//  Time - O(n)
//  Space - O(n)

class Solution {
public:
    vector<int> findThePrefixCommonArray(vector<int>& A, vector<int>& B) {
        vector<int> res;
        unordered_set<int> seen;
        int commonCount = 0;

        for (int i = 0; i < A.size(); i++) {
            if (seen.find(A[i]) != seen.end()) {
                commonCount++;
            }
            if (seen.find(B[i]) != seen.end()) {
                commonCount++;
            }
            if (A[i] == B[i]) {
                commonCount++;
            }
            
            seen.insert(A[i]);
            seen.insert(B[i]);
            res.push_back(commonCount);
        }

        return res;
    }
};