//  1  2  3  4
//  1  2  6  24    prefix product
//  24 24 12 4     postfix product
//  24 12 8 6      answer

//  got to like 10 min and checked neetcode array, i was so close 
//  apparantley each res is prefix[i - 1] * postfix[i + 1]
//  i did not think of that

//  Solved in 22 min ^including that
//  Time - O(n)
//  Space - O(n)

/*
class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> prefix(nums.size(), 1);
        vector<int> postfix(nums.size(), 1);
        vector<int> res;
        int left = 0;
        int right = nums.size() - 1;
        prefix[left] = nums[left];
        postfix[right] = nums[right];
        left++;
        right--;

        while (left < nums.size()) {
            prefix[left] = prefix[left - 1] * nums[left];
            postfix[right] = postfix[right + 1] * nums[right];
            left++;
            right--;
        }

        for (int i = 0; i < prefix.size(); i++) {
            cout << prefix[i] << " " << postfix[i] << endl;
        }

        for (int i = 0; i < nums.size(); i++) {
            int curPostfix = 1;
            int curPrefix = 1;

            if (i != 0) {
                curPrefix = prefix[i - 1];
            }
            if (i != nums.size() - 1) {
                curPostfix = postfix[i + 1];
            }

            res.push_back(curPrefix * curPostfix);
        }

        return res;
    }
};
*/

//  Optimize space to O(1)
//  They mention in the follow up to solve in O(1) and that the output array doesnt count 
//  so that is most likely a hint to use the output array


//  1  2  3  4
//  1  2  6  24    prefix product
//  24 24 12 4     postfix product
//  24 12 8 6      answer

//  ok i think you could store the current prefix product in a variable
//  and always have the prefix product 1 behind our current index
//  so precompute the postfix product into the result array
//  and scan through it using the previous prefix variable, and next postfix

//  precompute postfix into result in one pass
//  initialize a prefix variable to 1
//  for int i = 0 to numsSize - 2 in nums
//      res[i] = prefix * res[i + 1]
//      prefix = prefix * nums[i]
//  return res

//  Solved in 12 min - DID NOT LOOK AT ANY HINT FOR THIS ONE other than the given one in the problem W
//      forgot to loop backwards for initializing postfix and forgot case in setting res of i == numssize - 1
//  Time - O(n)
//  Space - O(1)

class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int postfix = 1;
        vector<int> res(nums.size(), 1);

        for (int i = nums.size() - 1; i >= 0; i--) {
            postfix = postfix * nums[i];
            cout << postfix << endl;
            res[i] = postfix;
        }

        int prefix = 1;

        for (int i = 0; i < nums.size(); i++) {
            if (i == nums.size() - 1) {
                res[i] = prefix;
                continue;
            }
            res[i] = prefix * res[i + 1];
            prefix = prefix * nums[i];
        }

        return res;
    }
};