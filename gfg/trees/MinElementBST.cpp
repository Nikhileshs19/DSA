class Solution {
  public:
    int minValue(Node* root) {
        // Code here
        if(!root)
            return NULL;
        if(!root->left)
            return root->data;
        return min(root->data,minValue(root->left));
    }
};