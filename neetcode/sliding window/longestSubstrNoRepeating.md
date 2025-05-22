Longest Substring Without Repeating Characters
Solved
Given a string s, find the length of the longest substring without duplicate characters.

A substring is a contiguous sequence of characters within a string.

Example 1:

Input: s = "zxyzxyz"

Output: 3
Explanation: The string "xyz" is the longest without duplicate characters.

```
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int l=0, ans=0;
        unordered_map<char,int> m;
        for(int r=0;r<s.size();r++){
            if(m.find(s[r]) != m.end()){
                l = max(l, m[s[r]]+1);
            }
            m[s[r]] = r;
            ans = max(ans, r-l+1);

        }
        return ans;
    }
};
```
