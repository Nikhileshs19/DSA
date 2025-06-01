Same Binary Tree
Solved
Given the roots of two binary trees p and q, return true if the trees are equivalent, otherwise return false.

Two binary trees are considered equivalent if they share the exact same structure and the nodes have the same values.

Example 1:

Input: p = [1,2,3], q = [1,2,3]

Output: true
Example 2:

Input: p = [4,7], q = [4,null,7]

Output: false
Example 3:

Input: p = [1,2,3], q = [1,3,2]

Output: false

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
    bool isSameTree(TreeNode* p, TreeNode* q) {
        if(!p && !q) return 1;
        if(p && q && p->val == q->val) {
        return isSameTree(p->left,q->left) && isSameTree(p->right,q->right);
        }
        else return 0;
    }
};
```
