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

//  we start at 1s place, then go to 10s, then 100s, etc.
//  so first, iterate through the 2 given lists
//  on every iteration, increment the place by * 10, multiply cur digit by it,
//      and add that to the current number total
//  after iterating thru both lists add the numbers to get our target
//  then, iterate through the number of places in the target, constructing a new list
//  set cur node to the current number % 10 and then subtract that amount from curnum
//  keep going til cur num = 0

//  cool this is just broken and will not work so im gonna redo using the carry bit method
//  spent 42min, failed at test case 32
/*
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int num1 = 0;
        int num2 = 0;
        long long curPlace = 1;

        while (l1 != nullptr) {
            num1 += l1->val * curPlace;
            curPlace *= 10;
            l1 = l1->next;
        }

        curPlace = 1;
        while (l2 != nullptr) {
            num2 += l2->val * curPlace;
            curPlace *= 10;
            l2 = l2->next;
        }

        int target = num1 + num2;
        curPlace = 10;
        ListNode* resHead = new ListNode();
        ListNode* res = resHead;

        if (target == 0) {
            return new ListNode(0);
        }

        while (target > 0) {
            //  807 -> 807 % 10
            //
            cout << target << endl;
            ListNode* curNode = new ListNode(0);

            if (target % curPlace * 10 != 0) {
                curNode->val = (target % curPlace * 10) / curPlace;
            }

            cout << curNode->val << endl;

            target -= (target % curPlace);
            curPlace *= 10;

            res->next = curNode;
            res = res->next;
        }

        return resHead->next;
    }
};
*/

//  1
//  2 4 3
//  5 6 4
//  _____
//  8 0 7

//  loop while l1 != null, l2 != null, and carry bit > 0
//      if both lists not null,
//          res = l1 val + l2 val
//      elif list1 null
//          res = l2 val
//      elif list2 null
//          res = l1 val
//      res += carry bit
//      if (res >= 10)
//          carry bit = true
//          res = res % 10
//      cur node val = res

//  Solved in 12 min
//  Time - O(m + n) (list lengths)
//  Space - O(1)

class Solution
{
public:
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2)
    {
        ListNode *resHead = new ListNode();
        ListNode *res = resHead;
        bool carryBit = false;

        while (l1 != nullptr || l2 != nullptr || carryBit)
        {
            int curVal = 0;
            if (l1 && l2)
            {
                curVal = l1->val + l2->val;
                l1 = l1->next;
                l2 = l2->next;
            }
            else if (l1 == nullptr && l2 == nullptr)
            {
                //  skips the next 2 cases
            }
            else if (l1 == nullptr)
            {
                curVal = l2->val;
                l2 = l2->next;
            }
            else
            {
                curVal = l1->val;
                l1 = l1->next;
            }

            curVal += carryBit;
            if (curVal >= 10)
            {
                carryBit = true;
                curVal = curVal % 10;
            }
            else
            {
                carryBit = false;
            }

            ListNode *newNode = new ListNode(curVal);
            res->next = newNode;
            res = res->next;
        }

        return resHead->next;
    }
};