/*Structure of the linked list node is as
struct Node {
  int data;
  struct Node * next;
  Node(int x) {
    data = x;
    next = NULL;
  }
}; */

class Solution{
  public:
    //Function to insert a node at the beginning of the linked list.
    Node *insertAtBegining(Node *head, int x) {
       // Your code here
       Node * newnode = new Node(x);
       if(!head)
        return newnode;
       newnode ->next = head;
       return newnode;
    }
    
    
    //Function to insert a node at the end of the linked list.
    Node *insertAtEnd(Node *head, int x)  {
       // Your code here
       Node * newnode = new Node(x);
       if(!head)
        return newnode;
        Node * cur = head;
        while(cur->next)
            cur = cur->next;
        
        cur->next = newnode;
        return head;
    }
};