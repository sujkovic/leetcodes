//  Keep a start index, and needleIndex
//  Loop through haystack, for every iteration
//      if haystack[i] == needle[needleIndex]
//          if needleIndex == needleIndex.size -1
//              return startIndex
//          needleIndex++
//      else
//          startIndex = i
//          needleIndex = 0
//  return -1

//  Solved in 10 min


//  let n = haystack size, m = needle size

//  Time - O(n * m)
//      worst case we keep pushing i back over and over

//  Space - O(1)
//      no new data struct

class Solution {
public:
    int strStr(string haystack, string needle) {
        int startIndex = 0;
        int needleIndex = 0;

        for (int i = 0; i < haystack.size(); i++) {

            if (haystack[i] == needle[needleIndex]) {
                if (needleIndex == needle.length() - 1) {
                    return startIndex;
                }
                needleIndex++;
            }
            else {
                i = i - needleIndex;
                //  ^ needed to look at solutions to figure out i needed this line 
                //  basically can have sameish string on repeat so we accidentaly skip over the real start
                startIndex = i + 1;
                needleIndex = 0;
            }
        }
        
        return -1;
    }
};