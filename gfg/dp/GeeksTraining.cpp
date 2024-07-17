class Solution {
  public:
    int maximumPoints(vector<vector<int>>& points, int n) {
        // Code here
        std::vector<std::vector<int>> dp(n, std::vector<int>(4, -1));
        return maxPointsUtil(n - 1, 3, points, dp);
    }
    int maxPointsUtil(int day, int lastActivity, std::vector<std::vector<int>>& points, std::vector<std::vector<int>>& dp) {
        // Base case
        if (day == 0) {
            int maxPoints = 0;
            for (int activity = 0; activity < 3; ++activity) {
                if (activity != lastActivity) {
                    maxPoints = std::max(maxPoints, points[0][activity]);
                }
            }
            return maxPoints;
        }
    
        // Check if result is already computed
        if (dp[day][lastActivity] != -1) {
            return dp[day][lastActivity];
        }
    
        int maxPoints = 0;
        for (int activity = 0; activity < 3; ++activity) {
            if (activity != lastActivity) {
                int pointsToday = points[day][activity] + maxPointsUtil(day - 1, activity, points, dp);
                maxPoints = std::max(maxPoints, pointsToday);
            }
        }
    
        return dp[day][lastActivity] = maxPoints;
    }


};



//Tabulation

int maxMeritPoints(std::vector<std::vector<int>>& points, int n) {
    // Initialize dp array
    std::vector<std::vector<int>> dp(n, std::vector<int>(3, 0));
    
    // Base case: on the first day
    dp[0][0] = points[0][0];
    dp[0][1] = points[0][1];
    dp[0][2] = points[0][2];
    
    // Fill the dp array
    for (int i = 1; i < n; ++i) {
        dp[i][0] = points[i][0] + std::max(dp[i-1][1], dp[i-1][2]);
        dp[i][1] = points[i][1] + std::max(dp[i-1][0], dp[i-1][2]);
        dp[i][2] = points[i][2] + std::max(dp[i-1][0], dp[i-1][1]);
    }
    
    // The maximum merit points on the last day
    return std::max({dp[n-1][0], dp[n-1][1], dp[n-1][2]});
}