Encode and Decode Strings
Solved
Design an algorithm to encode a list of strings to a single string. The encoded string is then decoded back to the original list of strings.

Please implement encode and decode

Example 1:

Input: ["neet","code","love","you"]

Output:["neet","code","love","you"]
Example 2:

Input: ["we","say",":","yes"]

Output: ["we","say",":","yes"]

```
#include <string>
#include <sstream>

class Solution {
public:

    string encode(vector<string>& strs) {
        string s;
        for(const string& str : strs){
            s += to_string(str.size()) + "#" + str;
        }
        return s;
    }

    vector<string> decode(string s) {
        int i=0;
        vector<string> ans;
        while(i<s.length()){
            int j = i;
            while(s[j] != '#')
                j++;
            int l = stoi(s.substr(i,j-i));
            i=j+1;
            j=i+l;
            ans.push_back(s.substr(i,l));
            i=j;

        }
        return ans;
    }
};

```
