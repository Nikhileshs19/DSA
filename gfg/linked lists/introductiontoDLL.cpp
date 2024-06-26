class Node{
public:
    Node* prev;
    int data;
    Node* next;
 
    Node()
    { 
        prev = NULL; 
        data = 0;
        next = NULL;
    }
    
    Node(int value)
    { 
        prev = NULL; 
        data = value;
        next = NULL;
    }
};

class Solution {
  public:
    Node* constructDLL(vector<int>& arr) {
        // code here
        Node * head = new Node(arr[0]);
        Node * p = new Node();
        p = head;
        for(int i=1;i<arr.size();i++){
            Node * newnode = new Node(arr[i]);
            newnode->prev = p;
            p->next = newnode;
            p = newnode;
        }
        return head;
    }
};