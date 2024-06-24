class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_set<char> set;
        int l = s.length();
        int i = 0, j = 0, ans = 0;
        
        while (i < l && j < l) {
            if (set.find(s[j]) == set.end()) {
                // Character s[j] is not in the set, add it
                set.insert(s[j]);
                j++;
                ans = max(ans, j - i);
            } else {
                // Character s[j] is in the set, remove s[i] from the set and increment i
                set.erase(s[i]);
                i++;
            }
        }
        return ans;
    }
};