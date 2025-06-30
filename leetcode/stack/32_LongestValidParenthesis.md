32. Longest Valid Parentheses
    Solved
    Hard
    Topics
    premium lock icon
    Companies
    Given a string containing just the characters '(' and ')', return the length of the longest valid (well-formed) parentheses substring.

Example 1:

Input: s = "(()"
Output: 2
Explanation: The longest valid parentheses substring is "()".
Example 2:

Input: s = ")()())"
Output: 4
Explanation: The longest valid parentheses substring is "()()".
Example 3:

Input: s = ""
Output: 0

```
class Solution {
public:
    int longestValidParentheses(string s) {
        stack<int> st;
        st.push(-1);
        int ans = 0;
        if(s.size() == 0) return 0;
        for(int i=0;i<s.size();i++){
            int t = st.top();
            if(t!=-1 && s[i] == ')' && s[t] == '('){
                st.pop();
                ans = max(ans,i-st.top());
            }
            else st.push(i);
        }
        return ans;
    }
};
```
