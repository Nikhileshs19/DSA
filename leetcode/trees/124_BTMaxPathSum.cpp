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
    int maxPathSum(TreeNode* root) {
        int s=INT_MIN;
        maxSum(root, s);
        return s>root->val?s:root->val;
    }

    int maxSum(TreeNode* root, int &s) {
        if(!root) return 0;
        int l = max(0,maxSum(root->left, s));
        int r = max(0,maxSum(root->right, s));
        s = max(l + r + root->val, s);
        return max(l,r) + root->val;
    }
};