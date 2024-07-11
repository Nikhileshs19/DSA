class Solution {
public:
    string reverseParentheses(string s) {
        stack<char> s1, s2, ans, res;
        string x;
        for(int i=0;i<s.size();i++){
            if(s[i]==')'){
                while(ans.top()!='('){
                    char c = ans.top();
                    ans.pop();
                    s1.push(c);
                }
                ans.pop();
                while(s1.size()>0){
                    s2.push(s1.top());
                    s1.pop();
                }
                while(s2.size()>0){
                    // cout << s2.top() << " ";
                    ans.push(s2.top());
                    s2.pop();
                }
                
            }
            ans.push(s[i]);
        }
        while(ans.size()>0){
                    // cout << s2.top() << " ";
                    res.push(ans.top());
                    ans.pop();
                }
        while(res.size()>0){
            if(res.top()=='(' || res.top()==')')
                res.pop();
            else{
                x += res.top();
                res.pop();
            }
            // cout << ans.top();
            // ans.pop();
        }
        return x;
        
    }
};

    string reverseParentheses(string s) {
        int n = s.length();
        vector<int> opened, pair(n);
        for (int i = 0; i < n; ++i) {
            if (s[i] == '(')
                opened.push_back(i);
            if (s[i] == ')') {
                int j = opened.back();
                opened.pop_back();
                pair[i] = j;
                pair[j] = i;
            }
        }
        string res;
        for (int i = 0, d = 1; i < n; i += d) {
            if (s[i] == '(' || s[i] == ')')
                i = pair[i], d = -d;
            else
                res += s[i];
        }
        return res;
    }

        string reverseParentheses(string s) {
        vector<int> opened;
        string res;
        for (int i = 0; i < s.length(); ++i) {
            if (s[i] == '(')
                opened.push_back(res.length());
            else if (s[i] == ')') {
                int j = opened.back();
                opened.pop_back();
                reverse(res.begin() + j, res.end());
            } else {
                res += s[i];
            }
        }
        return res;
    }