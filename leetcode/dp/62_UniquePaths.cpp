class Solution {
public:
    int uniquePaths(int m, int n) {
        vector<vector<int>> dp(m, vector<int>(n,-1));
        return memoi(m,n,0,0,dp);
    }
    int memoi(int m, int n, int i, int j, vector<vector<int>> &dp){
        if(i == m-1 && j == n-1)
            return 1;
        if(i >= m || j >= n)
            return 0;
        if(dp[i][j] != -1)
            return dp[i][j];

        return dp[i][j] = memoi(m,n, i+1, j, dp) + memoi(m, n, i, j+1, dp);
    }
};