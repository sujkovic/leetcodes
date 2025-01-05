//  First thought is just loop through shifts
//  loop through s for j = shifts[i][0] to shifts[i][1]
//      if shifts[i][2] == 1
//          if s[j] == 'z'
//              s[j] = 'a'
//          else
//              s[j]++
//      else
//          if s[j] == 'a'
//              s[j] = 'z'
//          else
//              s[j]--

//  Finished in 7 min, TLE
//  Time - O(n^2 * s) where n = slength, s = shiftslength
//  Space - O(1)

/*
class Solution {
public:
    string shiftingLetters(string s, vector<vector<int>>& shifts) {
        for (int i = 0; i < shifts.size(); i++) {
            int start = shifts[i][0];
            int end = shifts[i][1];
            int forwards = shifts[i][2];

            for (int j = start; j <= end; j++) {
                if (forwards) {
                    if (s[j] == 'z') {
                        s[j] = 'a';
                    }
                    else {
                        s[j]++;
                    }
                }
                else {
                    if (s[j] == 'a') {
                        s[j] = 'z';
                    }
                    else {
                        s[j]--;
                    }
                }
            }
        }

        return s;
    }
};
*/


//  Ok this is a thought i originally had but thought it might 
//  not work for this problem but i think it will, just changed a bit
//  keep a sum of shifts for each index in s
//  then at the end, just perform that amount of operations on s at each indices shift count
//      aka just do modulo arithmetic to take it from O(n) to O(1)

//  Bruh this is still TLE?? took 20 min
//      compiled on first try no errors, but forgor to account for negative, took 10 min
//  Time - O(n * s)
//  Space - O(s)

/*
class Solution {
public:
    string shiftingLetters(string s, vector<vector<int>>& shifts) {
        vector<int> shiftCounts(s.length(), 0);

        //  init shift counts at each index of s
        for (int i = 0; i < shifts.size(); i++) {
            for (int j = shifts[i][0]; j <= shifts[i][1]; j++) {
                if (shifts[i][2]) {
                    shiftCounts[j]++;
                }
                else {
                    shiftCounts[j]--;
                }
            }
        }
        
        //  Calculate the new char at each index of s
        for (int i = 0; i < s.length(); i++) {
            if ((s[i] - 'a') + shiftCounts[i] < 0) {
                int charInt = s[i] - 'a';
                charInt = abs(charInt + 1 + shiftCounts[i]) % 26;
                s[i] = 'z' - charInt;
            }
            else {
                int charInt = s[i] - 'a';
                charInt = (charInt + shiftCounts[i]) % 26;
                s[i] = 'a' + charInt;
            }
        }

        return s;
    }
};
*/

//  also my accounting for negatives was pretty ugly and way overthought, switched to neetcodes
//  method of just always add 26 
//  

/*
class Solution {
public:
    string shiftingLetters(string s, vector<vector<int>>& shifts) {
        vector<int> shiftCounts(s.length(), 0);

        //  init shift counts at each index of s
        for (int i = 0; i < shifts.size(); i++) {
            for (int j = shifts[i][0]; j <= shifts[i][1]; j++) {
                if (shifts[i][2]) {
                    shiftCounts[j]++;
                }
                else {
                    shiftCounts[j]--;
                }
            }
        }
        
        //  Calculate the new char at each index of s
        for (int i = 0; i < s.length(); i++) {
            int charInt = s[i] - 'a';
            charInt = (charInt + shiftCounts[i] + 26) % 26;
            s[i] = 'a' + charInt;
        }

        return s;
    }
};
*/

//  Dang watched the neetcode vid and theres way more to this problem
//  So my modulo logic still stands, but we can optimize that n^2 part
//  of initializing the precomputation
//  instead, we can use prefix sum in the following sense:
//  lets say we have slength = 5, and the shift [2, 4, 1]
//     og array index =  0 1 2 3 4
//              index  = 0 1 2 3 4 5
//      prefixSumArray = 0 0 0 0 0 0
//                     = 0 0 -1 0 0 1
//  basically for the end index of a shift, we want EVERYTHING at and before
//  that index to be incremented by 1
//  but to account for the start index and not incrementing things before it,
//  we put a -1 at the index before the start index of that shift, so that
//  everything at and before the index before the start index gets 1 subtracted from it,
//  offsetting the + 1 
//  and we just keep doing this
//  so in the end we can then iterate through the prefixsumarray backwards,
//  keeping a diff variable of our current +/-
//  so add the current cell to the dif, then thats the final value for that cell
//  then my final loop remains unchanged


//  Solved in 25 min
//      Compiled first try with no issues in 17 min but only 30/39 cases passed????
//      ok it was just a negative shift issue had to do modulo twice
//      honestly just looked at the solutions for that line since i did not understand
//  Time - O(n)
//  Space - O(n)

class Solution {
public:
    string shiftingLetters(string s, vector<vector<int>>& shifts) {
        vector<int> prefixSum(s.length() + 1, 0);
        
        for (int i = 0; i < shifts.size(); i++) {
            if (shifts[i][2]) {
                prefixSum[shifts[i][1] + 1]++;
                prefixSum[shifts[i][0]]--;
            }
            else {
                prefixSum[shifts[i][1] + 1]--;
                prefixSum[shifts[i][0]]++;
            }
        }

        int dif = 0;

        for (int i = prefixSum.size() - 1; i >= 0; i--) {
            dif += prefixSum[i];
            prefixSum[i] = dif;
        }

        for (int i = 0; i < s.length(); i++) {
            int charInt = s[i] - 'a';
            charInt = (charInt + (prefixSum[i + 1] % 26 + 26)) % 26;
            //  original line vvvvvvv
            //  charInt = (charInt + prefixSum[i + 1] + 26) % 26;
            s[i] = 'a' + charInt;
        }

        return s;
    }
};

//  Spent a total of an hour and 5 minutes on this problem all things included
//  thinking, coding, checking neetcode vid, checking solns 