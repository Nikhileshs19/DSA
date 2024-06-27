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
    ListNode* deleteMiddle(ListNode* head) {
        if(!head || !(head->next))
            return NULL;
        ListNode* fast = head;
        ListNode *slow = head;
        if(fast->next)
            fast = fast->next->next;
        while(fast && fast->next){
            fast = fast->next->next;
            slow = slow->next;
        }
        fast = slow->next;
        if(fast)
        slow->next = fast->next;
        else
            slow->next = NULL;
        delete(fast);
        return head;
    }
};