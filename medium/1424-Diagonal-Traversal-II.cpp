//  for each diagonal line, the sum of the indices of the elements on that line are equal
//  ex. first diag 0, 0 = 0
//  second diag 1,0 0,1 = 1
//  third diag 2,0 1,1 0,2 = 2
//  push them to a vector<pair<int, pair<int, int>>
//  first int = diag index
//  second int = index within that diag
//  third int = actual val

//  wow i flew through this question, 15 minutes flat at 1:30 AM

//  Time - hm either O(m * n) or O (x * ylogy) where x = numDiags, y = biggest diag vec size
//  cause you need to sort every vec within the diags vec, might be worse than
//  the double for loop to iterate through input

//  Space - O (m * n)
//  Basically making a copy of the input matrix

class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& nums) {
        vector<vector<int>> diags;
        //  find biggest row
        int biggestRow = 0;
        for (int i = 0; i < nums.size(); i++) {
            biggestRow = max(biggestRow, (int)nums[i].size());
        }
        //  init diags vec
        int numDiags = nums.size() + biggestRow - 1;
        for (int i = 0; i < numDiags; i++) {
            vector<int> vec;
            diags.push_back(vec);
        }
        //  add to diags vec
        for (int i = 0; i < nums.size(); i++) {
            for (int j = 0; j < nums[i].size(); j++) {
                diags[i + j].push_back(nums[i][j]);
            }
        }
        //  reverse each diag
        for (int i = 0; i < numDiags; i++) {
            reverse(diags[i].begin(), diags[i].end());
        }
        //  add from sorted diags vec to result vec
        vector<int> res;
        for (int i = 0; i < numDiags; i++) {
            for (int j = 0; j < diags[i].size(); j++) {
                res.push_back(diags[i][j]);
            }
        }
        return res;
    }
};