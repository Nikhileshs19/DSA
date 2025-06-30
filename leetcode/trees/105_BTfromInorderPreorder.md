105. Construct Binary Tree from Preorder and Inorder Traversal
     Solved
     Medium
     Topics
     premium lock icon
     Companies
     Given two integer arrays preorder and inorder where preorder is the preorder traversal of a binary tree and inorder is the inorder traversal of the same tree, construct and return the binary tree.

Example 1:

Input: preorder = [3,9,20,15,7], inorder = [9,3,15,20,7]
Output: [3,9,20,null,null,15,7]
Example 2:

Input: preorder = [-1], inorder = [-1]
Output: [-1]

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
    int preindex;
    unordered_map<int,int> map;
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        map.clear();
        for(int i=0;i<inorder.size();i++)
        map[inorder[i]] = i;
        preindex = 0;
        return build(preorder,0,inorder.size()-1);
    }

    TreeNode* build(vector<int>&preorder, int start, int end){
        if(start > end) return nullptr;
        int rootval = preorder[preindex++];
        TreeNode* root = new TreeNode(rootval);
        int mid = map[rootval];
        root->left = build(preorder,start,mid-1);
        root->right = build(preorder,mid+1,end);

        return root;
    }
};
```
