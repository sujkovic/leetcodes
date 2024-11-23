//  Let n = s1 length, m = s2 length
//  We basically want to check every substring in s2 of length n,
//      checking if its a permutation of s1
//  To check if its a permutation, it just has to have the same count of all characters
//  So it's looking like we do a sliding window of length n within s2
//  Keep a map of each characters frequency, popping and pushing as we go along


//  e i d b a o o o    
//  l r              e:1, i:1
//    l r            i:1, d:1
//      l r          d:1, b:1
//        l r        b:1, a:1   -> return true

//  Hm only problem here is we would keep having to check if the map = s1
//      which would be O(n) i believe
//  going to code it out for now and try to optimize if possible

//  Solved in 16 min
//  Let n = s1 length, m = s2 length
//  Wrong:
//  Time - O(n * m) 
//  Space - O(m + n)
//      Nvm im dumb, forgot when dealing with maps of characters its size 26 so its constant :|
//  Right:
//  Time - O(m + n)
//  Space - O(1)

class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        //  Base case, if s1 is longer, not possible
        if (s1.length() > s2.length()) {
            return false;
        }
        unordered_map<char, int> map1;      //  O(26)
        unordered_map<char, int> map2;      //  O(26)

        //  Populate the maps initially
        for (int i = 0; i < s1.length(); i++) { //  O(n)
            map1[s1[i]]++;
        }

        for (int i = 0; i < s1.length(); i++) {  // O(n)
            map2[s2[i]]++;
        }

        if (map1 == map2) {
            return true;
        }

        int left = 0;
        int right = s1.length() - 1;

        while (right < s2.length() - 1) {       //  O(m)
            //  Take away the leftmost character
            map2[s2[left]]--;
            if (map2[s2[left]] == 0) {
                map2.erase(s2[left]);
            }
            left++;
            //  Add the right most character
            right++;
            map2[s2[right]]++;
        
            //  Check if permutation of 1
            if (map1 == map2) {                 //  O(26)
                return true;
            }
        }

        return false;
    }
};