//  target - 1 1 0

//  so to get a 1, you must have a zero and a one
//  to get a zero, you must have a one and one or zero and zero

//  ~ 8 min thinking ^

//  honestly had to watch the neetcode vid for this one
//  i did have some of the same ideas but couldnt connect them i thought thered be some trick
//  but its really nothing crazy just simulate making the array
//  what i didnt think of is that you can start with a 1 or a 0, that doesn't matter 
//  then the important part is when you wrap around, if you get a contradiction, you return false

//  ex.
//  given 1 1 0
//  init: 0
//  i = 0 -> curBit = 1 because we want a 1
//  i = 1 -> curBit = 0 because we want a 1
//  i = 2 -> our starting bit was 0, and our current bit is 0. here, we can not chose
//                                                      but it worked out so return true

//  Solved in 14 min
//      Wow i cant believe that compiled and accepted on first try
//  Time - O(n)
//  Space - O(1)

class Solution {
public:
    bool doesValidArrayExist(vector<int>& derived) {
        //  Let's say in our simulation we start with 0, then move forward 1, and thats our current bit
        int curBit = 0;

        for (int i = 0; i < derived.size(); i++) {
            if (i < derived.size() - 1) {
                if (derived[i] == 1) {
                    if (curBit == 1) {
                        curBit = 0;
                    }
                    else {
                        curBit = 1;
                    }
                }
                //  else we just do nothing since a ^ a = 0
            }
            //  last element case
            else {
                //  checking if curBit ^ 0 (first bit we chose) == derived[i]
                if (curBit ^ 0 == derived[i]) {
                    return true;
                }
            }
        }

        return false;
    }
};

//  damn you could solve this whole question with just return isarraysumeven