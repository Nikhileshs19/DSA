/* a Node of the doubly linked list 
struct Node
{
  int data;
  struct Node *next;
  struct Node *prev;
  Node(int x) { data = x; next = prev = NULL; }
}; */

//Function to insert a new node at given position in doubly linked list.
void addNode(Node *head, int pos, int data)
{
   // Your code here
   Node * ins = new Node(data);
   Node * cur = head;
   for(int i=0;i<pos;i++){
       if(!cur)
        return;
        cur = cur->next;
   }
    ins->next = cur->next;
    ins->prev = cur;
    if (cur->next != nullptr) {
        cur->next->prev = ins;
    }
    cur->next = ins;

}