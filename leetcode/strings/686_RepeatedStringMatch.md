686. Repeated String Match
     Solved
     Medium
     Topics
     premium lock icon
     Companies
     Given two strings a and b, return the minimum number of times you should repeat string a so that string b is a substring of it. If it is impossible for b​​​​​​ to be a substring of a after repeating it, return -1.

Notice: string "abc" repeated 0 times is "", repeated 1 time is "abc" and repeated 2 times is "abcabc".

Example 1:

Input: a = "abcd", b = "cdabcdab"
Output: 3
Explanation: We return 3 because by repeating a three times "abcdabcdabcd", b is a substring of it.
Example 2:

Input: a = "a", b = "aa"
Output: 2

```
class Solution {
public:
    int repeatedStringMatch(string a, string b) {
        string repeated = a;
        int count = 1;

        // Keep appending `a` to itself until `b` could possibly fit
        while (repeated.length() < b.length()) {
            repeated += a;
            count++;
        }

        // Check if `b` is now a substring
        if (repeated.find(b) != string::npos) return count;

        // Try one more repeat in case b overlaps the end
        repeated += a;
        if (repeated.find(b) != string::npos) return count + 1;

        return -1;
    }
};
```
