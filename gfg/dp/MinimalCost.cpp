class Solution {
  public:
    int minimizeCost(vector<int>& height, int n, int k) {
        // Code here
        std::vector<int> dp(n, INT_MAX);
        
        // Base case: no energy required to stay on the first stair
        dp[0] = 0;
        
        for (int i = 1; i < n; ++i) {
            for (int j = 1; j <= k; ++j) {
                if (i - j >= 0) {
                    dp[i] = std::min(dp[i], dp[i - j] + std::abs(height[i] - height[i - j]));
                }
            }
        }
    
        // The minimum energy to reach the last stair
        return dp[n - 1];
    }
};