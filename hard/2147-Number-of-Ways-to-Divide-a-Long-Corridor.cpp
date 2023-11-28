//  base case 2 seats = 1 way, odd number of seats = 0 ways
//  do initial screen to make sure # seats even
//  loop through input array
//  every time you find two new seats
//      keep a count of the number of plants between those and the next seat, thats the # of ways for that section
//  since you could have like 10 seats, with different # ways in the area between each pair of two,
//      set result to result * cur number of seats


//  Time - O(n)
//      Two loops through input array of size n

//  Space - O(1)
//      No new data structure created

//  Solved in 20 minutes oh yeah
//  Side note I can name like 30 medium questions that were harder than this, 
//  not really sure how leetcodes difficulty rating works...


class Solution {
public:
    int getNumSeats(string &corridor) {
        int numSeats = 0;
        for (int i = 0; i < corridor.length(); i++) {
            if (corridor[i] == 'S') {
                numSeats++;
            }
        }
        return numSeats;
    }
    int numberOfWays(string corridor) {
        //  base case
        int numSeats = getNumSeats(corridor);
        if (numSeats == 2) {
            return 1;
        }
        if (numSeats % 2 == 1 || numSeats < 2) {
            return 0;
        }
        //  regular case
        numSeats = 0;
        int curNumPlants = 1;
        long result = 1;
        int mod = 1e9 + 7;

        for (int i = 0; i < corridor.length(); i++) {
            if (corridor[i] == 'S') {
                numSeats++;

                if (numSeats % 2 == 0) {
                    result = (result * curNumPlants) % mod;
                    curNumPlants = 1;
                }
            }
            if (corridor[i] == 'P' && numSeats % 2 == 0 && numSeats != 0) {
                curNumPlants++;
            }
        }

        return result;
    }
};