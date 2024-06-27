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
        // Create a dummy node to handle edge cases easily
        ListNode* dummy = new ListNode(0);
        dummy->next = head;
        
        // Initialize two pointers, both starting at the dummy node
        ListNode* first = dummy;
        ListNode* second = dummy;
        
        // Move the first pointer n+1 steps ahead to maintain the gap of n nodes between first and second
        for (int i = 0; i <= n; i++) {
            first = first->next;
        }
        
        // Move both pointers until the first pointer reaches the end of the list
        while (first != nullptr) {
            first = first->next;
            second = second->next;
        }
        
        // The second pointer is now at the node before the one to be deleted
        ListNode* nodeToDelete = second->next;
        second->next = second->next->next;
        
        // Free the memory of the deleted node
        delete nodeToDelete;
        
        // Store the new head of the list
        ListNode* newHead = dummy->next;
        
        // Free the memory of the dummy node
        delete dummy;
        
        return newHead;
    }
};
