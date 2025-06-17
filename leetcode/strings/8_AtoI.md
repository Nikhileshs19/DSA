8. String to Integer (atoi)
   Solved
   Medium
   Topics
   premium lock icon
   Companies
   Implement the myAtoi(string s) function, which converts a string to a 32-bit signed integer.

The algorithm for myAtoi(string s) is as follows:

Whitespace: Ignore any leading whitespace (" ").
Signedness: Determine the sign by checking if the next character is '-' or '+', assuming positivity if neither present.
Conversion: Read the integer by skipping leading zeros until a non-digit character is encountered or the end of the string is reached. If no digits were read, then the result is 0.
Rounding: If the integer is out of the 32-bit signed integer range [-231, 231 - 1], then round the integer to remain in the range. Specifically, integers less than -231 should be rounded to -231, and integers greater than 231 - 1 should be rounded to 231 - 1.
Return the integer as the final result.

Example 1:

Input: s = "42"

Output: 42

Explanation:

The underlined characters are what is read in and the caret is the current reader position.
Step 1: "42" (no characters read because there is no leading whitespace)
^
Step 2: "42" (no characters read because there is neither a '-' nor '+')
^
Step 3: "42" ("42" is read in)

```
class Solution {
public:
    int myAtoi(string s) {
        int i=0, base=0,sign=1;
        while(s[i]==' ' ) i++;
        if (s[i] == '-' || s[i] == '+') {
            sign = 1 - 2 * (s[i++] == '-');
        }
        while(s[i] >= '0' && s[i]<='9'){
            if (base >  INT_MAX / 10 || (base == INT_MAX / 10 && s[i] - '0' > 7)) {
            if (sign == 1) return INT_MAX;
            else return INT_MIN;
        }
            base = 10*base + (s[i++]-'0');
        }
        return base * sign;
    }
};
```
