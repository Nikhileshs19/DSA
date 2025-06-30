108. Convert Sorted Array to Binary Search Tree
     Solved
     Easy
     Topics
     premium lock icon
     Companies
     Given an integer array nums where the elements are sorted in ascending order, convert it to a height-balanced binary search tree.

Example 1:

Input: nums = [-10,-3,0,5,9]
Output: [0,-3,9,-10,null,5]
Explanation: [0,-10,5,null,-3,null,9] is also accepted:

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
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        TreeNode* root = makeTree(nums,0,nums.size()-1);
        return root;

    }
    TreeNode* makeTree(vector<int> & nums, int start, int end){
        if(start>end) return nullptr;
        int m = start + (end-start)/2;
        TreeNode* node = new TreeNode(nums[m]);
        node->left = makeTree(nums,start,m-1);
        node->right = makeTree(nums,m+1,end);
        return node;
    }
};
```
