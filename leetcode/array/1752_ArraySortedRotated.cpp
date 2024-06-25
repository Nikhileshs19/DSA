class Solution {
public:
    bool check(vector<int>& nums) {
        int n = nums.size();
        int flag = 1;
        for(int x=0;x<n;x++){
            for(int i=0;i<n-1;i++){
                flag = 1;
                if(nums[(i+x)%n]>nums[(i+x+1)%n]){
                    flag = 0;
                    break;
                }   
            }
            if(flag) return 1;
        }
        return 0;
    }
};