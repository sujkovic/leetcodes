//  0 1
//  1 1
//  do nothing

//  0 1                                        1 1
//  1 0 -> flip the values in first column ->  0 0

//  0 0 0                                           1 1 0
//  0 0 1                                           1 1 1
//  1 1 0  -> flip the values in first 2 columns -> 0 0 0

//  first thing that comes to mind is dp, try every possible combination of flips
//  so first we can do a dfs function that at every point, either flips the current column or doesnt
//  and update the result (maxEqualRows)

//  Finished in 15 min
//  Given m rows, n columns
//  Time - O(2^n * m * n)
//  Space - O(n)

/*
class Solution {
public:
    void dfs(vector<vector<int>>& matrix, int &res, int col) {
        int numEqualRows = 0;

        for (int i = 0; i < matrix.size(); i++) {
            bool isRowEqual = true;

            for (int j = 1; j < matrix[0].size(); j++) {
                if (matrix[i][j] != matrix[i][j - 1]) {
                    isRowEqual = false;
                }
            }

            if (isRowEqual) {
                numEqualRows++;
            }
        }

        res = max(res, numEqualRows);

        if (col >= matrix[0].size()) {
            return;
        }

        //  dont flip the current column
        dfs(matrix, res, col + 1); 
        
        //  flip the current column
        for (int row = 0; row < matrix.size(); row++) {
            if (matrix[row][col] == 0) {
                matrix[row][col] = 1;
            }
            else {
                matrix[row][col] = 0;
            }
        }

        dfs(matrix, res, col + 1);
    }
    int maxEqualRowsAfterFlips(vector<vector<int>>& matrix) {
        int res = 0;
        dfs(matrix, res, 0);
        return res;
    }
};
*/

//  optimize

//  took a glance at discussion and saw some stuff about xor and hash maps

//  0 0 0                                           1 1 0
//  0 0 1                                           1 1 1
//  1 1 0  -> flip the values in first 2 columns -> 0 0 0

//  looking at this example, you can see row 2 and 3 are complements of each other
//  so what if we just checked the matrix for all "complements", which we could have 
//  different patterns of, and return the count of the most common one

//  To make it efficient, we can convert the matrix into a vector of binary numbers
//  and then keep a map of number : count
//  then loop through the input and if we see a number or its complement, increment the count

//  Then how do we get complement of a binary number
//  ex.
//  1 0 0 1
//  or it -> 
//  nvm easier if we just store it as a string

//  Pseudocode
//  map<string, int>
//  for row in rows
//      string curNum = ""
//      for col in cols
//          curNum += mat[row][col]
//      string complement = ""
//      for char in curNum
//          push the opposite of curChar to complement
//      if curNum or complement exists in map, incremenet it, otherwise insert it with val 1
//  loop through the map and return the highest count

//  Solved in 16 min
//      only compile error was a typo
//  Time - O(m * n)
//  Space - O(m * n);

class Solution {
public:
    int maxEqualRowsAfterFlips(vector<vector<int>>& matrix) {
        unordered_map<string, int> map;

        for (int row = 0; row < matrix.size(); row++) {
            string curNum = "";
            string complement = "";

            //  Get current row as a string
            for (int col = 0; col < matrix[0].size(); col++) {
                if (matrix[row][col] == 0) {
                    curNum += '0';
                }
                else {
                    curNum += '1';
                }
                
            }

            //  Get complement of current row
            for (int i = 0; i < curNum.size(); i++) {
                if (curNum[i] == '0') {
                    complement += '1';
                }
                else {
                    complement += '0';
                }
            }

            //  Check if cur row or its complement exist in our map
            if (map.find(curNum) != map.end()) {
                map[curNum]++;
            }
            else {
                map[complement]++;
            }
        }

        //  Get highest count of a row/its complement
        int res = 0;

        for (auto it = map.begin(); it != map.end(); it++) {
            res = max(res, it->second);
        }

        return res;
    }
};