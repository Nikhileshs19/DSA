/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> ans;
        if(!root)
            return ans;
        stack<TreeNode*> s;
        TreeNode * cur = root;
        while(cur || !s.empty()){
            while(cur){
                s.push(cur);
                cur = cur ->left;
            }
            cur = s.top();
            s.pop();
            ans.push_back(cur->val);
            cur = cur->right;
        }
        return ans;
    }
};


//Recursive
void inorder(Node* root, vector<int> &arr){
    // If the current node is NULL
    // (base case for recursion), return
    if(root == nullptr){
        return;
    }
    // Recursively traverse the left subtree
    inorder(root->left, arr);
    // Push the current node's
    // value into the vector
    arr.push_back(root->data);
    // Recursively traverse 
    // the right subtree
    inorder(root->right, arr);
}

// Function to initiate inorder traversal
// and return the resulting vector
vector<int> inOrder(Node* root){
    // Create an empty vector to
    // store inorder traversal values
    vector<int> arr;
    // Call the inorder traversal function
    inorder(root, arr);
    // Return the resulting vector
    // containing inorder traversal values
    return arr;
}