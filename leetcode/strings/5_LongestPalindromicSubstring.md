5. Longest Palindromic Substring
   Solved
   Medium
   Topics
   premium lock icon
   Companies
   Hint
   Given a string s, return the longest palindromic substring in s.

Example 1:

Input: s = "babad"
Output: "bab"
Explanation: "aba" is also a valid answer.
Example 2:

Input: s = "cbbd"
Output: "bb"

```
class Solution {
public:
    string longestPalindrome(string s) {
        if(s.length() <2) return s;
        int maxLen = 1;
        int start = 0, end = 0;
        vector<vector<bool>> dp(s.length(),vector<bool>(s.length(),false));
        for(int i =0;i<s.length();++i){
            dp[i][i] = true;
            for(int j = 0;j<i;++j){
                if(s[j] == s[i] && (i-j <=2 || dp[j+1][i-1])){
                    dp[j][i] = 1;
                    if(i - j + 1 > maxLen){
                        maxLen = i-j+1;
                        start = j;
                        end = i;
                    }
                }
            }
        }
        return s.substr(start,end - start + 1);
    }
};
```
