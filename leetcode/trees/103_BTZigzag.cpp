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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        if (!root)
            return ans;

        queue<TreeNode*> q;
        q.push(root);
        int l = 0;
        while (!q.empty()) {
            int n = q.size();
            vector<int> level;  // Vector to store the current level's elements
            l++;
            for (int i = 0; i < n; ++i) {
                TreeNode* cur = q.front();
                q.pop();
                level.push_back(cur->val);
                
                if (cur->left)
                    q.push(cur->left);
                if (cur->right)
                    q.push(cur->right);
            }
            if(l%2==0)
                reverse(level.begin(),level.end());

            ans.push_back(level);  // Add the current level to the answer
        }

        return ans;
    }
};