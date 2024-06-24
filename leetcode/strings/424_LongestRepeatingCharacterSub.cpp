class Solution {
public:
    int characterReplacement(string s, int k) {
        int l=0, r=0, x=0;
        unordered_map<char, int> m;

        for(r=0;r<s.size();r++){
            m[s[r]]++;
            x = max(x, m[s[r]]);
            if(r-l+1-x>k){
                m[s[l]]--;
                l++;
            }
        }
        return r-l;
    }
};