class Solution {
  public:
    int solve(int n, int m, vector<vector<int>>& grid) {
        vector<vector<vector<int>>> dp(n, vector<vector<int>>(m, vector<int>(m, -1)));
        return collectChocolates(grid, 0, 0, m - 1, dp);
    }
    int collectChocolates(vector<vector<int>>& grid, int i, int j1, int j2, vector<vector<vector<int>>>& dp) {
        int n = grid.size();
        int m = grid[0].size();
        
        if (j1 < 0 || j1 >= m || j2 < 0 || j2 >= m) {
            return -1e8; // Invalid move
        }
        
        if (i == n - 1) {
            if (j1 == j2) return grid[i][j1]; // Both robots end at the same cell
            else return grid[i][j1] + grid[i][j2]; // Both robots end at different cells
        }
        
        if (dp[i][j1][j2] != -1) return dp[i][j1][j2];
        
        int maxChocolates = 0;
        
        for (int move1 = -1; move1 <= 1; ++move1) {
            for (int move2 = -1; move2 <= 1; ++move2) {
                int newJ1 = j1 + move1;
                int newJ2 = j2 + move2;
                int currentChocolates = (j1 == j2) ? grid[i][j1] : grid[i][j1] + grid[i][j2];
                currentChocolates += collectChocolates(grid, i + 1, newJ1, newJ2, dp);
                maxChocolates = max(maxChocolates, currentChocolates);
            }
        }
        
        return dp[i][j1][j2] = maxChocolates;
    }
};