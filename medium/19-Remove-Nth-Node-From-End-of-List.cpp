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

//  Make a copy of the head ptr, lets call it cur
//  Iterate through the list until null just to count # items in list (length)

//  nodeToBeDeleted = length - n
//  isFirstNode = ...
//  if isFirstNode, return head->next

//  iterate through the list until null
//      if n == 1
//          if cur->next->next == nullptr
//              cur->next = nullptr
//          else
//              cur->next = cur->next->next
//          break
//      n--
//      cur = cur->next
//  return head

//  Solved in 15 minutes, CODE RAN AND WAS ACCEPTED WITHOUT A SINGLE TYPO OR ANYTHING
//      im so cracked omg
//  Time - O(n)
//  Space - O(1)

class Solution
{
public:
    ListNode *removeNthFromEnd(ListNode *head, int n)
    {
        ListNode *cur1 = head;
        int listLength = 0;
        while (cur1 != nullptr)
        {
            listLength++;
            cur1 = cur1->next;
        }

        int nodeToBeDeleted = listLength - n;
        if (nodeToBeDeleted == 0)
        {
            return head->next;
        }

        ListNode *cur2 = head;
        while (cur2 != nullptr)
        {
            if (nodeToBeDeleted == 1)
            {
                if (cur2->next->next == nullptr)
                {
                    cur2->next = nullptr;
                }
                else
                {
                    cur2->next = cur2->next->next;
                }
                break;
            }
            nodeToBeDeleted--;
            cur2 = cur2->next;
        }

        return head;
    }
};