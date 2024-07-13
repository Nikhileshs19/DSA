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
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        TreeNode * ans = new TreeNode(val);
        TreeNode * cur = root;
        TreeNode * prev = root;
        if(!root)
            return ans;
        while(cur){
            if(val > cur->val){
                prev = cur;
                cur = cur->right;
            }
            else{
                prev = cur;
                cur = cur->left;
            }
        }
        if(val > prev->val)
            prev->right = ans;
        else
            prev->left = ans;
        return root;
    }
};

TreeNode* insertIntoBST(TreeNode* root, int val) {
        if(!root) return new TreeNode(val);
        if(root->val > val) root->left = insertIntoBST(root->left, val);
        else root->right = insertIntoBST(root->right, val);
        return root;
    }