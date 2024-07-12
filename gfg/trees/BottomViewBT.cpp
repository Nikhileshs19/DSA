class Solution {
  public:
    vector <int> bottomView(Node *root) {
        // Your Code Here
        vector<int> ans;
        if(!root)
            return ans;
        //Your code here
        map<int, int> m;
        queue<pair<Node*,int>> q;
        q.push({root,0});
        while(!q.empty()){
            auto it = q.front();
            q.pop();
            Node * cur = it.first;
            int line = it.second;
        
            m[line] = cur->data;
    
            
            if(cur->left)
                q.push({cur->left,line-1});
            if(cur->right)
                q.push({cur->right,line+1});
        }
        
        for(auto line : m){
            ans.push_back(line.second);
        }
        return ans;
    }
};