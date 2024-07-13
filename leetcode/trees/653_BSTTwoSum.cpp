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
    unordered_set<int> s;
    bool findTarget(TreeNode* root, int k) {
        inorder(root);
        for(auto it:s){
            if(s.find(k-it)!=s.end() && !(it*2==k))
                return 1;
            
        }
        return 0;
    }
    void inorder(TreeNode* root){
    // If the current node is NULL
    // (base case for recursion), return
    if(root == nullptr){
        return;
    }
    // Recursively traverse the left subtree
    inorder(root->left);
    // Push the current node's
    // value into the vector
    s.insert(root->val);
    // Recursively traverse 
    // the right subtree
    inorder(root->right);
}
};