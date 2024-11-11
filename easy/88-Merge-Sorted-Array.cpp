//  Solved in 7 min
//  O(m + n) time
//  O(m + n) space

/*
class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int count = 0;
        int nums1Size = m;
        int nums2Size = n;
        int nums1Index = 0;
        int nums2Index = 0;
        vector<int> res;

        while (count < m + n) {
            if (nums1Index < nums1Size && nums2Index < nums2Size &&
                nums1[nums1Index] < nums2[nums2Index]) {
                    res.push_back(nums1[nums1Index]);
                    nums1Index++;
                }
            else if (nums1Index < nums1Size && nums2Index < nums2Size &&
                nums1[nums1Index] >= nums2[nums2Index]) {
                    res.push_back(nums2[nums2Index]);
                    nums2Index++;
                }
            else if (nums1Index >= nums1Size) {
                res.push_back(nums2[nums2Index]);
                nums2Index++;
            }
            else {
                res.push_back(nums1[nums1Index]);
                nums1Index++;
            }

            count++;
        }

        nums1 = res;
    }
};
*/

//  O(1) space
//  start from the back of nums1, setting cur index to the cur biggest element

//  Solved in 3 min

class Solution
{
public:
    void merge(vector<int> &nums1, int m, vector<int> &nums2, int n)
    {
        int index = m + n - 1;
        m--;
        n--;

        while (index >= 0)
        {
            if (m >= 0 && n >= 0 && nums1[m] > nums2[n])
            {
                nums1[index] = nums1[m];
                m--;
            }
            else if (m >= 0 && n >= 0 && nums1[m] <= nums2[n])
            {
                nums1[index] = nums2[n];
                n--;
            }
            else if (m < 0)
            {
                nums1[index] = nums2[n];
                n--;
            }
            else
            {
                nums1[index] = nums1[m];
                m--;
            }

            index--;
        }
    }
};