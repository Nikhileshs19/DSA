145. Binary Tree Postorder Traversal
     Solved
     Easy
     Topics
     premium lock icon
     Companies
     Given the root of a binary tree, return the postorder traversal of its nodes' values.

Example 1:

Input: root = [1,null,2,3]

Output: [3,2,1]

Explanation:

Example 2:

Input: root = [1,2,3,4,5,null,8,null,null,6,7,9]

Output: [4,6,7,5,2,9,8,3,1]

Explanation:

Example 3:

Input: root = []

Output: []

Example 4:

Input: root = [1]

Output: [1]

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
```
