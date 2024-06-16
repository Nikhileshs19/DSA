class Solution {
public:
    bool isSubsequence(string s, string t) {
        int i=0,j=0;
        if(s=="")
            return true;
        for(int i=0;i<t.length();i++){
            
            if(t[i]==s[j]){
                j++;
            }
            if(j==s.length())
                return true;
        }
        return false;
    }
};