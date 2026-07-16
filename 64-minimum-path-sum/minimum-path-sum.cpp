class Solution {
public:
    int solve(int i, int j, vector<vector<int>>& grid, vector<vector<int>>& dp) {
        
        if(i == 0 && j == 0) return grid[i][j];
        if(dp[i][j] != -1) return dp[i][j];

        int left = INT_MAX;
        if(j > 0) left = grid[i][j] + solve(i, j - 1, grid, dp);

        int top = INT_MAX;
        if(i > 0) top = grid[i][j] + solve(i - 1, j, grid, dp);

        return dp[i][j] = min(left, top);
    }
     int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<int>> dp(m, vector<int>(n , -1));

        return solve(m - 1, n - 1, grid, dp);
    }
};