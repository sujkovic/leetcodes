//  loop through words
//      init bool isPalindrome = true
//      for each word in words, iterate from left and right at same time
//          check if char at left and right equal
//          if not, isPal = false, break
//      if isPal true, return the word
//  return ""

//  Time - O(m * n) - loop through n words of size m
//  Space - O(1)

//  Solved in 4 minutes

class Solution {
public:
    string firstPalindrome(vector<string>& words) {
        for (int i = 0; i < words.size(); i++) {
            bool isPalindrome = true;
            int left = 0;
            int right = words[i].length() - 1;

            while (left <= right) {
                if (words[i][left] != words[i][right]) {
                    isPalindrome = false;
                    break;
                }

                left++;
                right--;
            }

            if (isPalindrome) {
                return words[i];
            }
        }

        return "";
    }
};