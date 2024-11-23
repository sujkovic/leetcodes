//  1 2 3 4 5
//  3 4 5 1 2
//        i


//  station 1   station 2      station 3        station 4     station 5
//      1   x       2     x        3       x        4      ->     5
//      3           4              5                1             2
//                                                     now we have 3 gas when we arrive at station 5

//  im thinking first find the station with the highest gas/cost ratio
//  then just start from that one and go around 

//  Got this done in 15 min but doesnt pass test case 32 rip

/*
class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int mostGas = 0;
        int bestStation = 0;

        //  Find the most optimal starting point (most gas to cost)
        for (int i = 0; i < gas.size(); i++) {
            if (gas[i] - cost[i] > mostGas) {
                mostGas = gas[i] - cost[i];
                bestStation = i;
            }
        }

        int gasLevel = gas[bestStation] - cost[bestStation];
        int station = (bestStation + 1) % gas.size();

        while (station != bestStation) {
            gasLevel += gas[station] - cost[station];
            if (gasLevel < 0) {
                return -1;
            }
            station = (station + 1) % gas.size();
        }

        return bestStation;
    }
};
*/


//  Tbh neetcode vid didnt make a ton of sense
//  First you check if the total cost levels are greater than total gas levels
//  if so, return -1
//  Then the idea seems to be just go through the arrays together,
//  at each point get the current gas level (gas[i] - cost[i])
//  if it cant reach the end of the array, that value wont work, move on
//  Once we get a value that CAN reach the end of the array, apparantely
//  that means that thats the answer
//  that last part is the only thing that im not 100% on 

//  nevermind not exactly that

//  solved in 30 ig
//  O(n), O(1)

class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int totalGas = accumulate(gas.begin(), gas.end(), 0);
        int totalCost = accumulate(cost.begin(), cost.end(), 0);
        
        //  if more cost than gas in total array, not possible
        if (totalCost > totalGas) {
            return -1;
        }

        int gasLevel = 0;
        int res = 0;

        for (int station = 0; station < gas.size(); station++) {
            gasLevel += (gas[station] - cost[station]);

            if (gasLevel < 0) {
                gasLevel = 0;
                res = station + 1;
            }
        }

        return res;
    }
};