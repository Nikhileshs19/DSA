int findCeil(Node* root, int input) {
    if (root == NULL) return -1;
    int ceil = -1;
    while(root){
        if(root->data==input)
            return input;
        if(input > root->data){
            root = root->right;
        }
        else{
            ceil = root->data;
            root = root->left;
        }
    }
    return ceil;
    // Your code here
}