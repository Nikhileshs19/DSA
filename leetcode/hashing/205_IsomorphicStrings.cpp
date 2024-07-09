class Solution {
public:
    bool isIsomorphic(string s, string t) {
        if (s.size() != t.size()) {
            return false;
        }

        unordered_map<char, char> sToT;
        unordered_map<char, char> tToS;

        for (int i = 0; i < s.size(); ++i) {
            char cs = s[i];
            char ct = t[i];

            if (sToT.find(cs) != sToT.end()) {
                if (sToT[cs] != ct) {
                    return false;
                }
            } else {
                sToT[cs] = ct;
            }

            if (tToS.find(ct) != tToS.end()) {
                if (tToS[ct] != cs) {
                    return false;
                }
            } else {
                tToS[ct] = cs;
            }
        }

        return true;
    }
};
