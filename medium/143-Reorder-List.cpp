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

//  not sure if this is allowed but my thought process is make a copy of the list
//  reverse the copy
//  then iterate through the lists going back and forth until you hit the middle

//  Reverse linked list

//  revList = head
//  prev = nullptr
//  while revList
//      ListNode temp = revList->next
//      revList->next = prev
//      prev = revList
//      revList = temp


//  Reorder list

//  while (listLength)
//      if even iteration
//          headNext = head->next;
//          head->next = revHead
//          head = head->next
//          revHead = revHead->next
//      if odd iteration
//          head->next = headNext
//          head = head->next

/*
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        ListNode* revList = head;
        ListNode* prev = nullptr;
        
        while (revList != nullptr) {
            cout << revList->val << endl;
            ListNode* temp = revList->next;
            revList->next = prev;
            prev = revList;
            revList = temp;
        }

        return prev;
    }

    int getListLength(ListNode* head) {
        ListNode* node = head;
        int length = 0;

        while (node != nullptr) {
            length++;
            node = node->next;
        }

        cout << "list length " << length << endl;
        return length;
    }

    void reorderList(ListNode* head) {
        int listLength = getListLength(head);
        ListNode* revHead = reverseList(head);
        ListNode* temp = nullptr;
        ListNode* temp2 = head;
        while (temp2) {
            cout << temp2->val << endl;
            temp2 = temp2->next;
        }

        while (listLength > 0) {
            if (listLength % 2 == 0) {
                cout << "even, curnode" << head->val << endl;
                temp = head->next;
                head->next = revHead;
                head = head->next;
                revHead = revHead->next;
            }
            else {
                cout << "odd, curnode" << head->val << endl;
                head->next = temp;
                head = head->next;
            }

            listLength--;
        }

    }
};
*/


//  Going to restart since this appraoch didnt rly work cause i needed to make a copy 
//  before reversing the list but idk if you're "allowed" since its kinda changing values?
//  Also this is just a mess

//  Going to try the slow/fast pointer method to find the middle of the list,
//  Then in place reverse the second half of the list

//  initialize slow pointer to head, fast pointer to head->next
//  while (!(fast->next is null or fast is null))
//      slow = slow->next
//      fast = fast->next->next
//  for both odd/even length lists, slow will now be at the end of first half
//  so increment slow by 1, and then reverse the rest of the list in place
//  also want to set slows next to null
//  temp = slow
//  slow = slow->next
//  temp->next = nullptr
//  prev = null
//  while (slow not null)
//      temp = slow->next
//      slow->next = prev
//      prev = slow
//      slow = temp
//  now prev will be the end of our list, aka the start of our reversed list
//  and head will be the start of our normal list
//  bool forwards = true
//  revHead = prev
//  keep a headNext and revNext to save next's when we point to the other side of list
//  while (head && revHead)
//      if forwards
//          headNext = head->next
//          revNext = revHead->next
//          head->next = revHead
//          head = head->next
//      else
//          head->next = revHead;
//          head = head->next


//  Got to this in 40 min but again that last while loop is just wrong 
//  asked chatgpt whats wrong and the code it showed me looked way cleaner 
//  so going to just redo that loop following the same idea

/*
class Solution {
public:
    void reorderList(ListNode* head) {
        ListNode* slow = head;
        ListNode* fast = head->next;

        while (!(fast == nullptr || fast->next == nullptr)) {
            slow = slow->next;
            fast = fast->next->next;
        }
        ListNode* tempSlow = slow;
        slow = slow->next;
        tempSlow->next = nullptr;

        ListNode* prev = nullptr;

        while (slow != nullptr) {
            ListNode* temp = slow->next;
            slow->next = prev;
            prev = slow;
            slow = temp;
        }

        bool forwards = true;
        ListNode* revHead = prev;
        ListNode* headNext = head;
        ListNode* revNext = revHead;

        while (revHead != nullptr && head != nullptr) {
            cout << head->val << " ";
            if (forwards) {
                headNext = head->next;
                head->next = revHead;
                head = head->next;
            }
            else {
                revNext = revHead->next;
                head->next = headNext;
                head = head->next;
            }

            forwards = !forwards;
        }

    }
};
*/


//  Solved in 47 min (+7 on the last part)
//      Honestly did horrible on this was just super confused
//      Idk if its me or if this is just a really confusing problem cause other linked list
//      questions ill fly through but i guess will review these a bit more
//  Tine - O(n)
//  Space - O(1)

class Solution {
public:
    void reorderList(ListNode* head) {
        //  Base case size 1 return 
        if (head->next == nullptr) {
            return;
        }

        //  Use fast/slow pointer to find midpoint of list and split list in two
        ListNode* slow = head;
        ListNode* fast = head->next;

        while (!(fast == nullptr || fast->next == nullptr)) {
            slow = slow->next;
            fast = fast->next->next;
        }

        //  Set the end of first half list to nullptr for later use
        ListNode* tempSlow = slow;
        slow = slow->next;
        tempSlow->next = nullptr;

        ListNode* prev = nullptr;

        //  Reverse the second half of the list
        while (slow != nullptr) {
            ListNode* temp = slow->next;
            slow->next = prev;
            prev = slow;
            slow = temp;
        }

        bool forwards = true;

        ListNode* end = prev;
        ListNode* start = head;
        //  Will need to keep track of the next's since we'll be overwriting
        ListNode* startNext = start->next;
        ListNode* endNext = end->next;

        //  Reorder the list
        while (start && end) {
            //  Save both side's next pointers
            startNext = start->next;
            endNext = end->next;

            //  Reorder the lists so front points to back, back points to front
            start->next = end;
            end->next = startNext;

            //  increment both ends to the next pointers we saved above
            start = startNext;
            end = endNext;
        }
    }
};

//  Kinda understand it now
//  I think for a problem like this you really need to draw it out on paper