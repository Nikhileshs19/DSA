class Solution{

public:
    int floor(Node* root, int x) {
        if (root == NULL) return -1;
        int floor = -1;
        while(root){
            if(root->data==x)
                return x;
            if(x > root->data){
                floor = root->data;
                root = root->right;
            }
            else{
                root = root->left;
            }
        }
        return floor;
    // Your code here
    }
};