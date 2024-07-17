class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        vector<vector<int>> dp(m, vector<int>(n, -1));
        return memoi(m,n,0,0,dp,grid);
    }
    int memoi(int m, int n, int i, int j, vector<vector<int>> &dp, vector<vector<int>>& grid){
        if(i == m-1 && j == n-1)
            return grid[m-1][n-1];
        if(i >= m || j >= n)
            return INT_MAX;
        if(dp[i][j] != -1)
            return dp[i][j];

        return dp[i][j] = grid[i][j] + min(memoi(m,n, i+1, j, dp, grid), memoi(m, n, i, j+1, dp, grid));
    }
};