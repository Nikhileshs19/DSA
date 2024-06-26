struct Node
{
    int data;
    Node* next;
    Node(int x) {  data = x;  next = NULL; }
}; 
class Solution {
  public:
    // Function to count nodes of a linked list.
    bool searchKey(int n, struct Node* head, int key) {
        // Code her
        for(int i=0;i<n;i++){
            if(head->data == key)
                return 1;
            head = head->next;
        }
        return 0;
    }
};
