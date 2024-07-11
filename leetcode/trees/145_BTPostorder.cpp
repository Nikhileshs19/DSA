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
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> ans;
        if(!root)
            return ans;
        stack<TreeNode*> s;
        TreeNode* cur = root;
        while(cur || !s.empty()){
            if(cur){
                s.push(cur);
                ans.push_back(cur->val);
                cur = cur->right;
            }
            else{
                cur = s.top();
                s.pop();
                cur = cur->left;
            }
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};



//Recursive
void postorder(Node* root, vector<int>& arr){
    // Base case: if root is null, return
    if(root==NULL){
        return;
    }
    // Traverse left subtree
    postorder(root->left, arr);
    // Traverse right subtree
    postorder(root->right, arr);
    // Visit the node
    // (append node's data to the array)
    arr.push_back(root->data);
}

// Function to get the postorder
// traversal of a binary tree
vector<int> postOrder(Node* root){
    // Create a vector to
    // store the traversal result
    vector<int> arr;
    // Perform postorder traversal
    // starting from the root
    postorder(root, arr);
    // Return the postorder
    // traversal result
    return arr;
}