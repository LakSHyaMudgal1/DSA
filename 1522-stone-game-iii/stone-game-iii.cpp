class Solution {
public:
    int solve(int idx, int n, vector<int>& arr, vector<int>& dp) {
        if(idx >= n) return 0;

        int t1 = INT_MIN;

        if(dp[idx] != INT_MIN) return dp[idx];

        t1 = arr[idx] - solve(idx + 1, n, arr, dp);
        if(idx + 1 < n) t1 = max(t1, arr[idx] + arr[idx + 1] - solve(idx + 2, n, arr, dp));
        if(idx + 2 < n) t1 = max(t1, arr[idx] + arr[idx + 1] + arr[idx + 2] - solve(idx + 3, n, arr, dp));

        return dp[idx] = t1;
        }
    string stoneGameIII(vector<int>& arr) {
        int n = arr.size();
        vector<int> dp(n, INT_MIN);

        int ans = solve(0, n, arr, dp);

        if(ans > 0) return "Alice";
        else if(ans == 0) return "Tie";
        return "Bob";
    }
};