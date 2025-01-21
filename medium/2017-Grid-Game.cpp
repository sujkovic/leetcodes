//  looks like we're going to basically treat the grid as 2 arrays
//  find the prefix sums of the 2 arrays
//  then find the point at which it becomes more optimal to switch to the second array
//  i think just the transition is going to be a tricky edge case since you basically get an extra cell

//  ex. og -> prefix
//  2 5 4  ->  2 7 11
//  1 5 1  ->  1 6 7

//  i = 0 ->   sum1 = 11 - 2 = 9, sum2 = 7 - 1 = 6, so keep first
//  i = 1 ->   sum1 = 11 - 7 = 4, sum2 = 7 - 6 = 1
//  nah this no work

//  oo what if we keep the total sums of the arrays as a variable, then on each iteration we do :
//      if were on arr1 :
//          sum1 -= arr1[i]
//          arr1[i] = 0
//          then if sum2 > sum1
//              we move down to arr2
//              arr2[i] = 0
//      else
//          arr2[i] = 0

//  Finished in 18 min and then failed the 4th test case but i have zero clue why and the discussion isnt helping gonna check neetcode

/*
class Solution {
public:
    long long gridGame(vector<vector<int>>& grid) {
        bool movedDown = false;
        long long sum1 = 0;
        long long sum2 = 0;

        //  init total sums
        for (int i = 0; i < grid[0].size(); i++) {
            sum1 += grid[0][i];
            sum2 += grid[1][i];
        }
        cout << sum1 << " " << sum2 << endl << endl;
        //  perform robot 1's simulation
        for (int i = 0; i < grid[0].size(); i++) {
            if (!movedDown) {
                sum1 -= grid[0][i];
                if (sum1 < sum2) {
                    movedDown = true;
                    cout << "moving down...\n";
                    sum2 -= grid[1][i];
                }
            }
            else {
                sum2 -= grid[1][i];
            }
            cout << sum1 << " " << sum2 << endl;
        }

        return max(sum1, sum2);
    }
};
*/
//  20  3 20 17  2 12 15 17  4 15       125
//  20 10 13 14 15  5  2  3 14  3       90

//  ok watched neetcode still not really sure why this greedy approach doesnt work 
//  but basically you have to just try every combination, ex:
//  2 5 4
//  1 5 1

//  x 5 4
//  x x x    -> robot2 sum = 9

//  x x 4
//  1 x x    -> robot2 sum = 4

//  x x x
//  1 5 x    -> robot2 sum = 6

//  get total sum1 first, init sum2 to 0
//  iterate through grid
//      sum1 -= arr1[i]
//      sum2 += arr2[i]  
//      curMin = min(curMin, sum1, sum2)
//  stop 1 iteration short

//  Solved in 25 min
//      Had to modify my approach above a bit cause it wasnt accurately simulating, off by 1
//      Then spent like 5 min cause i forgot i have to cast the 0 in accumulate
//  Time - O(n)
//  Space - O(1)

class Solution {
public:
    long long gridGame(vector<vector<int>>& grid) {
        long long sum1 = accumulate(grid[0].begin(), grid[0].end(), (long long)0) - grid[0][0];
        long long sum2 = 0;
        long long res = sum1;

        for (int i = 1; i < grid[0].size(); i++) {
            sum1 -= grid[0][i];
            sum2 += grid[1][i - 1];
            res = min(res, max(sum1, sum2));
        }

        return res;
    }
};

//  1 3 1 15      20
//  1 3 3 1       8