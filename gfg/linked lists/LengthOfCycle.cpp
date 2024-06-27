int countNodesinLoop(struct Node *head)
{
    // Code here
    Node* slow = head;
    Node * fast = head;
    int count = 1;
    while(fast && fast->next){
        slow = slow->next;
        fast = fast->next->next;
        if(fast == slow){
            while(slow->next != fast){
                slow = slow->next;
                count++;
                
            }
            
            return count;
        }
    }
    return 0;
    
    
}