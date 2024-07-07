class Solution {
public:
    int myAtoi(string s) {
        long long ans = 0, sign = 1, flag = 1;
        for(int i=0;i<s.size();i++){
            if(flag && s[i]==' ')
                continue;
            else if(flag && (s[i]=='-' ||s[i]=='+')){
                if(s[i]=='-')
                    sign = -1;
                flag = 0;
            }
            else if(s[i]>='0' && s[i]<='9'){
                int digit = s[i] - '0';
                if (ans > (INT_MAX - digit) / 10) {
                    return (sign == 1) ? INT_MAX : INT_MIN;
                }

                ans = ans * 10 + digit;
                flag = 0;
            }
            else
                break;
        }
        if (ans * sign >= INT_MAX) {
            return INT_MAX;
        } 
        else if (ans * sign <= INT_MIN) {
            return INT_MIN;
        }
        else return ans*sign;
    }
};