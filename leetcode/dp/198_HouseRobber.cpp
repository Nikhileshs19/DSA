class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n,0);
        dp[0] = nums[0];
        
        for(int i=1; i<n;i++){
            int jumpTwo = (i>1)?dp[i-2] + nums[i]:nums[i];
            int jumpThree = (i>2)? dp[i-3]+nums[i]:nums[i];
            dp[i] = max(jumpTwo, jumpThree);
        }

        return *max_element(dp.begin(),dp.end());
    }
};