class Solution {
public:
    string removeOuterParentheses(string s) {
        int num = 0, i=0;
        string ans;
        while(s[i]!='\0'){
            if(s[i]==')')
                num--;
            if(num>0){
                ans += s[i];
            }
            if(s[i]=='(')
                num++;
            i++;
        }
        return ans;
    }
};