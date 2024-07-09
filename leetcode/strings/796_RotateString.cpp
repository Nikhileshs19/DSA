class Solution {
public:
    bool rotateString(string s, string goal) {
        string temp;
        for(int i=0;i<s.size();i++){
            temp = s;
            reverse(temp.begin(),temp.end());
            reverse(temp.begin(),temp.begin()+i);
            reverse(temp.begin()+i,temp.end());
            cout << temp << endl;
            if(temp == goal)
                return 1;
        }
        return 0;
    }
};

class Solution {
public:
    bool rotateString(string s, string goal) {
        if(s.size()!=goal.size())return false;
        string new_s=goal+goal;
        return new_s.find(s)!=string::npos;
    }

};