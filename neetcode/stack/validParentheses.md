Valid Parentheses
Solved
You are given a string s consisting of the following characters: '(', ')', '{', '}', '[' and ']'.

The input string s is valid if and only if:

Every open bracket is closed by the same type of close bracket.
Open brackets are closed in the correct order.
Every close bracket has a corresponding open bracket of the same type.
Return true if s is a valid string, and false otherwise.

Example 1:

Input: s = "[]"

Output: true
Example 2:

Input: s = "([{}])"

Output: true

```
class Solution {
public:
    bool isValid(string s) {
        stack<char> st;
        unordered_map<char,char> map = {
            {')','('},
            {'}','{'},
            {']','['}
        };

        for(char c : s){
            if(map.count(c)){
                if(!st.empty() && st.top() == map[c])
                    st.pop();
                else
                    return 0;

            }
            else
                st.push(c);
        }
        return st.empty();
    }
};
```
