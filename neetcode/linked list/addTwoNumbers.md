Add Two Numbers
Solved
You are given two non-empty linked lists, l1 and l2, where each represents a non-negative integer.

The digits are stored in reverse order, e.g. the number 123 is represented as 3 -> 2 -> 1 -> in the linked list.

Each of the nodes contains a single digit. You may assume the two numbers do not contain any leading zero, except the number 0 itself.

Return the sum of the two numbers as a linked list.

Example 1:

Input: l1 = [1,2,3], l2 = [4,5,6]

Output: [5,7,9]

Explanation: 321 + 654 = 975.

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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int carry = 0, val=0;
        ListNode* dummy = new ListNode();
        ListNode* cur = dummy;

        while(l1 && l2){
            val = l1->val + l2->val + carry;
            carry = val/10;
            val = val%10;
            cur->next = new ListNode(val);
            cur = cur->next;
            l1 = l1->next;
            l2 = l2->next;
        }
        while(l1 || l2){
            if(!l2){
                val = l1->val+carry;
                carry=val/10;
                val = val%10;
                cur->next = new ListNode(val);
                cur = cur->next;
                l1 = l1->next;
            }
            else if(!l1){
                val = l2->val+carry;
                carry=val/10;
                val = val%10;
                cur->next = new ListNode(val);
                cur = cur->next;
                l2 = l2->next;
            }
        }
        if(carry){
            cur->next = new ListNode(carry);
        }
        return dummy->next;
    }
};
```
