//  6,   11, 6
//  17 / 6 ~= 2.9

//  7,    15, 10, 10
//  35 / 7 = 5

//  yea this doesnt work as i expected

//  10 min

/*
class Solution {
public:
    int minimizedMaximum(int n, vector<int>& quantities) {
        if (quantities.size() == n) {
            return *max_element(quantities.begin(), quantities.end());
        }
        float sum = accumulate(quantities.begin(), quantities.end(), 0);
        return ceil(sum / n);
    }
};
*/


//  im thinking we should sort the array
//  and be greedy with picking the biggest products to split up first
//  ex. 6,   11, 6
//  6, 5, 6
//  3, 3, 2, 3, 3, 3
//  ex. 7    15, 10, 10
//  10, 10, 8, 7

//  we could use a max heap
//  while n >= 0
//      pop the top of the heap
//      split it in two and add them back to the heap
//  return the min val from the heap

//  ok realized this ALSO wont work bc it only divides by 2, and you can divide by other numbers

/*
class Solution {
public:
    int minimizedMaximum(int n, vector<int>& quantities) {
        priority_queue<int> heap;

        for (int i = 0; i < quantities.size(); i++) {
            heap.push(quantities[i]);
        }

        while (heap.size() != n) {
            int top = heap.top();
            cout << top << " ";
            heap.pop();
            int half = top / 2;

            if (top % 2 == 1) {
                heap.push(half);
                heap.push(half + 1);
            }
            else {
                heap.push(half);
                heap.push(half);
            }
        }

        return heap.top();
    }
};
*/



//  Want to find optimal way to split up items per store
//  hypothetically could have anywhere from 1 to max val in quantities stores
//  ex. 11, 6     6 stores
//  1 -> 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1 -> 11 stores
//  2 -> 2, 2, 2, 2, 2, 1, 2, 2, 2 -> 9 stores
//  3 -> 3, 3, 3, 2, 3, 3 -> 6 stores   -> answer
//  4 -> 4, 4, 3, 4, 2 -> 6 stores but not minimized
//  5 -> 5, 5, 1, 5, 1 -> ^ same
//  6 -> 6, 5, 6 -> 3 stores

//  Brute force - try all
//  Finished in 10 min, TLE
//  O(maxVal * q size)

/*
class Solution {
public:
    int minimizedMaximum(int n, vector<int>& quantities) {
        int maxVal = 0;
        for (int i = 0; i < quantities.size(); i++) {
            maxVal = max(maxVal, quantities[i]);
        }

        for (int i = 1; i <= maxVal; i++) {
            long long numStores = 0;
            for (int j = 0; j < quantities.size(); j++) {
                numStores += ceil(quantities[j] / double(i));
            }

            if (numStores <= n) {
                return i;
            }
        }

        return -1;
    }
};
*/

//  if you look at the example i used above, we just want to find the smallest
//  value to divide the items by such that there's at least n stores
//  we can binary search for that number in the range 1 to max val in quantities
//  then compute the total number of stores for that number
//  if numstores > n
//      explore to the right
//  else
//      explore to the left and update result

class Solution {
public:
    int minimizedMaximum(int n, vector<int>& quantities) {
        int maxVal = *max_element(quantities.begin(), quantities.end());

        int left = 1;
        int right = maxVal;
        int res = maxVal;

        while (left <= right) {
            int middle = (left + right) / 2;
            long long numStores = 0;
            
            for (int j = 0; j < quantities.size(); j++) {
                numStores += ceil(quantities[j] / double(middle));
            }

            if (numStores <= n) {
                right = middle - 1;
                res = middle;       //  my problem was i was doing max(middle, res) here which always takes the biggest value (not optimal)
            }
            else {
                left = middle + 1;
            }
        }

        return res;
    }
};