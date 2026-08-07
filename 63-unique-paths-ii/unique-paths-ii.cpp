class Solution {
public:
    int solve(int i, int j, vector<vector<int>>& arr, vector<vector<int>>& dp) {
        if(i < 0 || j < 0) return 0;
        if(arr[i][j] == 1) return 0;

        if(i == 0 && j == 0) return 1;

        if(dp[i][j] != -1) return dp[i][j];

        int left = solve(i, j - 1, arr, dp);
        int top = solve(i - 1, j, arr, dp);

        return dp[i][j] = left + top;
    }
    int uniquePathsWithObstacles(vector<vector<int>>& arr) {
        int m = arr.size();
        int n = arr[0].size();
        vector<vector<int>>dp(m, vector<int>(n, -1));
        return solve(m - 1, n - 1, arr, dp);
    }
};