class Solution {
public:
    string mergeAlternately(string word1, string word2) {
        int m = word1.size();
        int n = word2.size();
        string result = "";

        for (int i = 0; i < max(m, n); i++) {
            if (i < m) {
                result.push_back(word1[i]);
            }
            if (i < n) {
                result.push_back(word2[i]);
            }
        }

        return result;
    }
};


class Solution {
public:
    string mergeAlternately(string word1, string word2) {
        int n=word1.length();
        int m=word2.length();
        
        int i=0, j=0;
        string res = "";
        
        while(i<n || j<m){
            if(i<n){
                res += word1[i++];
            }
            if(j<m){
                res += word2[j++];
            }
        }
        return res;
    }
};