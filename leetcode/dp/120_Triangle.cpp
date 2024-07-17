class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int m = triangle.size(), n = triangle[m-1].size();
        vector<vector<int>> dp (m, vector<int>(n, -1));
        return memoi(m, n, 0, 0, dp, triangle);
    }
    int memoi(int m, int n, int i, int j, vector<vector<int>> &dp, vector<vector<int>>& grid){
        if(i == m-1)
            return grid[i][j];
        if(i >= m || j >= n || j<0 || j > i)
            return INT_MAX;
        if(dp[i][j] != -1)
            return dp[i][j];

        return dp[i][j] = grid[i][j] + min(memoi(m,n, i+1, j, dp, grid), memoi(m, n, i+1, j+1, dp, grid));
    }
};