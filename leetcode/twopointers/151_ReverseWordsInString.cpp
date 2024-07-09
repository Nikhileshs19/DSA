class Solution {
public:
    string reverseWords(string s) {
        // Reverse the entire string
        reverse(s.begin(), s.end());
        
        int n = s.size();
        int i = 0, j = 0;
        
        while (i < n) {
            // Skip spaces
            while (i < n && s[i] == ' ') {
                i++;
            }
            
            if (i < n && j > 0) {
                s[j++] = ' ';
            }
            
            int start = j;
            // Reverse each word
            while (i < n && s[i] != ' ') {
                s[j++] = s[i++];
            }
            reverse(s.begin() + start, s.begin() + j);
        }
        
        // Resize the string to remove trailing spaces
        s.resize(j);
        return s;
    }
};
