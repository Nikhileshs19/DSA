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
    ListNode* rotateRight(ListNode* head, int k) {
        int n= 1;
        if(!head)
            return head;
        ListNode * cur = head;
        while(cur->next){
            cur = cur->next;
            n++;
        }
        cur->next = head;
        for(int i=0;i<(n-(k%n));i++){
            head = head->next;
            cur = cur->next;
        }
        cur->next = NULL;
        return head;
    }
};