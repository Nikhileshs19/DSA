Kth Smallest Integer in BST
Solved
Given the root of a binary search tree, and an integer k, return the kth smallest value (1-indexed) in the tree.

A binary search tree satisfies the following constraints:

The left subtree of every node contains only nodes with keys less than the node's key.
The right subtree of every node contains only nodes with keys greater than the node's key.
Both the left and right subtrees are also binary search trees.
Example 1:

Input: root = [2,1,3], k = 1

Output: 1
Example 2:

Input: root = [4,3,5,2,null], k = 4

Output: 5

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
 * };
 */

class Solution {
public:
    int kthSmallest(TreeNode* root, int k) {
        stack<TreeNode*> s;
        TreeNode * curr = root;
        while(!s.empty()||curr){
            while(curr){
            s.push(curr);
            curr = curr->left;
        }
        curr = s.top();
        s.pop();
        k--;
        if(k==0) return curr->val;
        curr = curr->right;
        }
        return -1;

    }
};
```
