class Solution {
  public:
    Node* deleteNode(Node* head, int x) {
        // Your code here
        if(!head)
            return NULL;
        
        Node * p = head;
        Node * cur = head;
        if(x==1)
            return head->next;
        for(int i=0;i<x-1;i++){
            p = cur;
            if(!cur->next)
                return head;
            cur = cur->next;
        }
        
        if(cur->next){
            p->next = cur->next;
            cur->next->prev = p;
        }
        else 
            p->next = NULL;
        return head;
        
    }
};