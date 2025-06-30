106. Construct Binary Tree from Inorder and Postorder Traversal
     Solved
     Medium
     Topics
     premium lock icon
     Companies
     Given two integer arrays inorder and postorder where inorder is the inorder traversal of a binary tree and postorder is the postorder traversal of the same tree, construct and return the binary tree.

Example 1:

Input: inorder = [9,3,15,20,7], postorder = [9,15,7,20,3]
Output: [3,9,20,null,null,15,7]
Example 2:

Input: inorder = [-1], postorder = [-1]
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
    int postindex;
    unordered_map<int,int> map;
public:
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        map.clear();
        for(int i=0;i<inorder.size();i++)
            map[inorder[i]] = i;
        postindex = postorder.size()-1;
        return build(postorder,0,inorder.size()-1);
    }
    TreeNode* build(vector<int>&postorder, int start, int end){
        if(start > end) return nullptr;
        int rootval = postorder[postindex--];
        TreeNode* root = new TreeNode(rootval);
        int mid = map[rootval];
        root->right = build(postorder,mid+1,end);
        root->left = build(postorder,start,mid-1);

        return root;
    }
};
```
