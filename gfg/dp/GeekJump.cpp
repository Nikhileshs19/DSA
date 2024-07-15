class Solution {
  public:
    int minimumEnergy(vector<int>& height, int n) {
        int N = height.size();
        std::vector<int> dp(N, 0);
        
        // Base case: no energy required to stay on the first stair
        dp[0] = 0;
    
        // Fill the dp array
        for (int i = 1; i < N; ++i) {
            int jumpOne = dp[i - 1] + abs(height[i] - height[i - 1]);
            int jumpTwo = (i > 1) ? dp[i - 2] + abs(height[i] - height[i - 2]) : INT_MAX;
            dp[i] = std::min(jumpOne, jumpTwo);
        }
    
        // The minimum energy to reach the last stair
        return dp[N - 1];
    }
};