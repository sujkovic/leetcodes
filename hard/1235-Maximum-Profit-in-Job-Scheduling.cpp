//  took a quick look at hints cause im completely lost here, that helped a little
//  first, sort every job by its start time. will probably need a job struct and custom sort function
//  Run a dfs on each job
//      from each job, we can jump to any job that STARTS at or after the current one ENDS
//          to find these, we can binary search the array (got this idea from the hints)
//  return totalprofit
//
//  cache will be endTime : profit
//      can make vector of size maxEndTime, but i think hashmap would be better use of space here


//  spent 40 minutes attempting, got to 15/31 cases passed but smtn is still a little off, gonna look at vid
//  Bruh literally the only problem was that i was supposed to be using the curIndex to index the cache, not the endTime. that cost me a good 20 min rip
//  time to do binary search optimization

//  aight spent 15 min on this to get it working, still TLE on case 25/31.
//  Going to recode it more in line with neetcodes approach
/*
class Solution {
public:
    struct Job {
        int startTime;
        int endTime;
        int profit;
        Job(int &s, int &e, int &p) : startTime(s), endTime(e), profit(p) {}
        bool operator < (const Job &job) const {
            if (startTime == job.startTime) {
                if (profit == job.profit) {
                    return endTime <= job.endTime;
                }
                else {
                    return profit > job.profit;
                }
            }
            else {
                return startTime < job.startTime;
            }
        }
    };
    int binarySearch(vector<Job> &jobs, int startRange, int target) {
        int left = startRange;
        int right = jobs.size() - 1;

        while (left < right) {
            int middle = (left + right) / 2;
            if (jobs[middle].startTime < target) {
                left = middle + 1;
            }
            else if (jobs[middle].startTime > target) {
                right = middle - 1;
            }
            else {
                if (middle > 0 && jobs[middle].startTime == jobs[middle - 1].startTime) {
                    right = middle - 1;
                }
                else {
                    return middle;
                }
            }
        }
        return left;
    }
    int dfs(vector<Job> &jobs, unordered_map<int, int> &memo, int curIndex) {
        cout << "cur index " << curIndex << endl;
        if (memo.find(curIndex) != memo.end()) {
            return memo[curIndex];
        }
        int startIndex = binarySearch(jobs, curIndex + 1, jobs[curIndex].endTime);
        int res = dfs(jobs, memo, startIndex);
        res = max(res, jobs[curIndex].profit + res);
        memo[curIndex] = res;
        return res;
    }
    int jobScheduling(vector<int>& startTime, vector<int>& endTime, vector<int>& profit) {
        vector<Job> jobs;
        unordered_map<int, int> memo;
        int res = 0;

        for (int i = 0; i < startTime.size(); i++) {
            Job curJob(startTime[i], endTime[i], profit[i]);
            jobs.push_back(curJob);
        }

        sort(jobs.begin(), jobs.end());
        for (int i = 0; i < jobs.size(); i++) {
            res = max(res, dfs(jobs, memo, i));
        }
        
        return res;
    }
};
*/

//  TODO FOR IN THE MORNING
//  Reattempt this problem with the strat of include / dont include for each dfs call
//      should be light with fresh mind. also wont need the loop in main with this
//      keep the struct / binary search tho (might need to change search idk tho)


//  dfs logic
//  can either TAKE or NOT TAKE the current job
//  if we DONT TAKE IT, profit = dfs of the next job in order (ex jobs[i + 1])
//  if we DO TAKE IT, profit = curProfit + dfs of the next job that starts AT OR AFTER the cur one ends

//  Solved in 25 minutes this time, THE PROBLEM WAS MY BINARY SEARCH LOGIC BEING WRONG BRUH i was doing right = mid - 1, left = mid + 1, and initializing right to jobs.size - 1. looked at solutions right should have beeen jobs.size, and for right you do right = mid. i guess i need to review binary search :DDDDD

//  Time - O(nlogn)
//      sort input array of size n (nlogn), then search the leftmost path of a tree of size 2^n, since we're caching, 
//      so it just comes out to n (height of tree). but within each of those n calls, we need to search the jobs
//      array for the next job that starts at or after cur ends, which we use binary search for (logn), within each
//      call going down the tree, so time comp for dfs is nlogn
//  Space - O(n)
//      hashmap of size n to cache, vector of jobs of size n to reorganize the 3 input vecs

class Solution {
public:
    struct Job {
        int startTime;
        int endTime;
        int profit;
        Job(int &s, int &e, int &p) : startTime(s), endTime(e), profit(p) {}
        bool operator < (const Job &job) const {
            if (startTime == job.startTime) {
                if (profit == job.profit) {
                    return endTime <= job.endTime;
                }
                else {
                    return profit > job.profit;
                }
            }
            else {
                return startTime < job.startTime;
            }
        }
    };
    int binarySearch(vector<Job> &jobs, int startRange, int target) {
        int left = startRange + 1;
        int right = jobs.size();

        while (left < right) {
            int middle = (left + right) / 2;
            if (jobs[middle].startTime < target) {
                left = middle + 1;
            }
            else if (jobs[middle].startTime > target) {
                right = middle;
            }
            else {
                if (middle > 0 && jobs[middle].startTime == jobs[middle - 1].startTime) {
                    right = middle;
                }
                else {
                    return middle;
                }
            }
        }
        return left;
    }
    int dfs(vector<Job> &jobs, unordered_map<int, int> &memo, int curIndex) {
        if (curIndex >= jobs.size()) {
            return 0;
        }
        if (memo.find(curIndex) != memo.end()) {
            return memo[curIndex];
        }
        
        int nextValidIndex = binarySearch(jobs, curIndex, jobs[curIndex].endTime);
        int dontInclude = dfs(jobs, memo, curIndex + 1);
        int include = jobs[curIndex].profit + dfs(jobs, memo, nextValidIndex);
        int res = max(include, dontInclude);

        memo[curIndex] = res;
        return res;
    }
    int jobScheduling(vector<int>& startTime, vector<int>& endTime, vector<int>& profit) {
        vector<Job> jobs;
        unordered_map<int, int> memo;

        for (int i = 0; i < startTime.size(); i++) {
            Job curJob(startTime[i], endTime[i], profit[i]);
            jobs.push_back(curJob);
        }

        sort(jobs.begin(), jobs.end());
        
        return dfs(jobs, memo, 0);
    }
};

//  side note for myself
//  was confused on how this take/dont take method works for cases like the first example where you have the
//  40 and 70 jobs both starting at 3, like if you call one the other wouldnt get called
//  But it actually does
//  ex. call the 40 job.
//      we can include 40, this path returns 50 + 40 = 90
//      we can NOT include 40, which calls the next job in the array
//          since our binary search found the FIRST job in the array with start time 3 (say its 40), 
//          we still get to search 70 in this path
//      so now we can include 70, this path returns 50 + 70 = 120
//      or dont include 70, returns 50
//  and we see that the max here is the path 50 -> 70 = 120