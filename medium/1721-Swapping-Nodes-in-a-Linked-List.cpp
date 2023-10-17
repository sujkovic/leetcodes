/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */


1 -> 2 -> 3 -> 4 -> 5

1 -> 4 -> 3 -> 2 -> 5

//  make copy of head
//  loop through list to determine length of list, len
//  loop through list again
//      on the kth iteration, save the cur element to a variable first
//      on the len - kth iteration, save the cur element to a variable second
//  loop through list again
//      on kth iteration, set cur to second
//      on len - kth iteration, set cur to first
//  return head

//  Time complexity: O(n)   -   Loop through list of length n three times
//  Space complexity: O(1)  -   Only using 3 variables, ptr to head, and 3 ints for first/second/len
//  Solved in 20 minutes


class Solution {
public:
    ListNode* swapNodes(ListNode* head, int k) {
        ListNode* list = head;
        int first;
        int second;
        int len = 1;
        while (list) {
            len++;
            list = list->next;
        }
        list = head;
        int it = 1;
        while (list) {
            if (it == k) {
                first = list->val;
            }
            if (it == (len - k)) {
                second = list->val;
            }
            it++;
            list = list->next;
        }
        ListNode* ptrToHead = new ListNode();
        ptrToHead->next = head;
        it = 1;
        while (head) {
            if (it == k) {
                head->val = second;
            }
            if (it == (len - k)) {
                head->val = first;
            }
            it++;
            head = head->next;
        }
        return ptrToHead->next;
    }
};