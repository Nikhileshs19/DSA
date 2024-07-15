class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        if(n<2) return n? nums[0]:0;
        return max(rec(nums, n, 0, n-2),rec(nums,n,1,n-1));
    }
    int rec(vector<int>&nums,int n, int l, int r){
        vector<int> dp(n,0);
        dp[l] = nums[l];
        for(int i=l+1; i<=r;i++){
            int jumpTwo = (i>l+1)?dp[i-2] + nums[i]:nums[i];
            int jumpThree = (i>l+2)? dp[i-3]+nums[i]:nums[i];
            dp[i] = max(jumpTwo, jumpThree);
        }
        return *max_element(dp.begin(),dp.end());
    }
};