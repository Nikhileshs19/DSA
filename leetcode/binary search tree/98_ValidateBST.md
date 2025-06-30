98. Validate Binary Search Tree
    Solved
    Medium
    Topics
    premium lock icon
    Companies
    Given the root of a binary tree, determine if it is a valid binary search tree (BST).

A valid BST is defined as follows:

The left subtree of a node contains only nodes with keys less than the node's key.
The right subtree of a node contains only nodes with keys greater than the node's key.
Both the left and right subtrees must also be binary search trees.

Example 1:

Input: root = [2,1,3]
Output: true

```
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };prev left right bool -> recurse
 */
class Solution {
public:
    bool isValidBST(TreeNode* root) {
        stack<TreeNode*> stack;
        TreeNode* pre = NULL;
        while (root || !stack.empty()) {
            while (root) {
                stack.push(root);
                root = root->left;
            }
            root = stack.top();
            stack.pop();
            if(pre && root->val <= pre->val) return false;
            pre = root;
            root = root->right;
        }
        return true;
    }
};
```
