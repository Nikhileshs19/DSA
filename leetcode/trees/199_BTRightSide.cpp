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
    vector<int> rightSideView(TreeNode* root) {
        vector<int> ans;
        if(!root)
            return ans;
        //Your code here
        map<int, int> m;
        queue<TreeNode*> q;
        q.push(root);
        int l = 1;
        while(!q.empty()){
            int n = q.size();
            l++;
            TreeNode *cur = q.front();
            for (int i = 0; i < n; ++i) {
                cur = q.front();
                q.pop();

                if (cur->left)
                    q.push(cur->left);
                if (cur->right)
                    q.push(cur->right);
            }
        
            m[l] = cur->val;

            
            if(cur->left)
                q.push(cur->left);
            if(cur->right)
                q.push(cur->right);
        }
        
        for(auto line : m){
            ans.push_back(line.second);
        }
        return ans;
    }
};