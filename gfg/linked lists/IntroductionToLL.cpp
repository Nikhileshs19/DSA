// User function Template for C++

/*class Node {
public:
    int data;
    Node* next;
  
    // Default constructor
    Node()
    {
        data = 0;
        next = NULL;
    }
  
    // Parameterised Constructor
    Node(int data)
    {
        this->data = data;
        this->next = NULL;
    }
};*/

class Solution {
  public:
    Node* constructLL(vector<int>& arr) {
        // code here
        Node * head = new Node(arr[0]);
        Node * cur = head;
        for(int i=1;i<arr.size();i++){
            Node * newnode = new Node(arr[i]);
            cur->next = newnode;
            cur = cur->next;
        }
        return head;
        
    }
};