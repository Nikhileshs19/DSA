Merge Two Sorted Linked Lists
You are given the heads of two sorted linked lists list1 and list2.

Merge the two lists into one sorted linked list and return the head of the new sorted linked list.

The new list should be made up of nodes from list1 and list2.

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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        if(!list1 && !list2) return nullptr;
        ListNode dummy(0);
        ListNode * node = &dummy;

        while(list1 && list2){
            if(list1->val >= list2->val){
                node->next = list2;
                list2 = list2->next;
            }
            else{
                node->next = list1;
                list1 = list1->next;
            }
            node = node->next;
        }
        if(list1){
            node->next = list1;
            list1 = list1->next;
        }
        else{
            node->next = list2;
            list2 = list2->next;
        }

        return dummy.next;


    }
};
```
