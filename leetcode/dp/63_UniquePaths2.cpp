class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m = obstacleGrid.size(), n = obstacleGrid[0].size();
        if(obstacleGrid[m-1][n-1] == 1)
            return 0;
        vector<vector<int>> dp(m, vector<int>(n,-1));
        return memoi(m,n,0,0,dp, obstacleGrid);
    }
    int memoi(int m, int n, int i, int j, vector<vector<int>> &dp, vector<vector<int>>& grid){
        if(i == m-1 && j == n-1)
            return 1;
        if(i >= m || j >= n)
            return 0;
        if(grid[i][j] == 1)
            return 0;
        if(dp[i][j] != -1)
            return dp[i][j];

        return dp[i][j] = memoi(m,n, i+1, j, dp, grid) + memoi(m, n, i, j+1, dp, grid);
    }
};
