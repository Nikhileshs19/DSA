Remove Node From End of Linked List
Solved
You are given the beginning of a linked list head, and an integer n.

Remove the nth node from the end of the list and return the beginning of the list.

Example 1:

Input: head = [1,2,3,4], n = 2

Output: [1,2,4]
Example 2:

Input: head = [5], n = 1

Output: []

**Make sure to remember the cases where head has to be removed, use dummy pointing to head**

```
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

class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode * dummy = new ListNode(0,head);
        ListNode* cur = dummy,*skip = head;
        for(int i =0;i<n;i++){
            skip = skip->next;
        }
        while(skip){
            skip = skip->next;
            cur = cur->next;
        }
        cur->next = cur->next->next;
        return dummy->next;
    }
};
```
