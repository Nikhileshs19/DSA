700. Search in a Binary Search Tree
     Solved
     Easy
     Topics
     premium lock icon
     Companies
     You are given the root of a binary search tree (BST) and an integer val.

Find the node in the BST that the node's value equals val and return the subtree rooted with that node. If such a node does not exist, return null.

Example 1:

Input: root = [4,2,7,1,3], val = 2
Output: [2,1,3]

```
class Solution {
public:
    TreeNode* searchBST(TreeNode* root, int val) {
        if(!root)
            return NULL;
        if(root->val == val)
            return root;
        return (val>root->val)?searchBST(root->right,val):searchBST(root->left,val);
    }
};
```
