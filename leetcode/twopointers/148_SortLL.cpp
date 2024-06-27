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
    ListNode* sortList(ListNode* head) {
        if(!head || !(head->next))
            return head;
        ListNode *temp = NULL;
        ListNode *slow = head;
        ListNode *fast = head;
        while(fast && fast->next){
            temp = slow;
            fast = fast->next->next;
            slow = slow->next;
        }
        temp->next = NULL;
        ListNode *fh = sortList(head);
        ListNode *sh = sortList(slow);
        return mergeList(fh,sh);
    }

    ListNode * mergeList(ListNode* fh, ListNode *sh){
        ListNode*newnode = new ListNode(0);
        ListNode * cur = newnode;
        while(fh && sh){
            if(fh->val >= sh->val){
                cur ->next = sh;
                sh = sh->next;
            }
            else{
                cur->next = fh;
                fh = fh->next;
            }
            cur = cur->next;
        }
        if(fh){
            cur->next = fh;
            fh = fh->next;
        }
        if(sh){
            cur->next = sh;
            sh = sh->next;
        }
        return newnode->next;
    }
};