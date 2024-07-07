class Solution
{
    public:
    //Function to sort a linked list of 0s, 1s and 2s.
    Node* segregate(Node *head) {
       int count[3] = {0,0,0};
       Node * cur = head;
       while(cur){
           count[cur->data]++;
           cur = cur->next;
       }
       int i = 0; 
        cur = head; 
     
        while (cur) 
        { 
            if (count[i] == 0) 
                ++i; 
            else
            { 
                cur->data = i; 
                --count[i]; 
                cur = cur->next; 
            } 
        } 
        return head;
    }
};