61. Rotate List
    Solved
    Medium
    Topics
    premium lock icon
    Companies
    Given the head of a linked list, rotate the list to the right by k places.

Example 1:

Input: head = [1,2,3,4,5], k = 2
Output: [4,5,1,2,3]
Example 2:

Input: head = [0,1,2], k = 4
Output: [2,0,1]

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
```
