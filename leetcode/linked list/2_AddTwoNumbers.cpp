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
        int carry = 0;
        ListNode * newhead = new ListNode(0);
        ListNode * cur = newhead;
        while(l1 || l2 || carry){
            int digit1 = (l1)?l1->val:0;
            int digit2 = (l2)?l2->val:0;

            int sum = digit1+digit2+carry;
            int num = sum%10;
            carry = sum/10;
            ListNode * newnode = new ListNode(num);
            cur->next = newnode;
            cur = cur->next;

            l1 = l1?l1->next:NULL;
            l2 = l2?l2->next:NULL;
        }
        cur = newhead ->next;
        delete newhead;
        return cur;
    }
};