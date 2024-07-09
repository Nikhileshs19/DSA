class Solution {
public:
    string largestOddNumber(string num) {
        if(num[num.size()-1]%2==1)
            return num;
        int i = num.size()-1;
        while(i>=0 && num[i]%2==0){
            i--;
        }
        num.erase(i+1);
        return num;

    }
};