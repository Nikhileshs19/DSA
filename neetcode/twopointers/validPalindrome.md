Valid Palindrome
Solved
Given a string s, return true if it is a palindrome, otherwise return false.

A palindrome is a string that reads the same forward and backward. It is also case-insensitive and ignores all non-alphanumeric characters.

Example 1:

Input: s = "Was it a car or a cat I saw?"

Output: true
Explanation: After considering only alphanumerical characters we have "wasitacaroracatisaw", which is a palindrome.

```
class Solution {
public:
    bool isPalindrome(string s) {
        int n = s.size();
        int left=0, right = n-1;
        while (left < right) {
            while (left < right && !isalnum(s[left])) {
                left++;
            }
            while (right > left && !isalnum(s[right])) {
                right--;
            }
            if (tolower(s[left]) != tolower(s[right])) {
                return 0;
            }
            left++;
            right--;
        }
        return 1;
    }
};
```
