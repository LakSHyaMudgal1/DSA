class Solution {
public:
long long mod = 1e18;
int change(int amount, vector<int>& coins) {
        int n = coins.size();
        if (n == 0)
            return amount == 0;

        vector<vector<long long>> dp(n + 1, vector<long long>(amount + 1, 0));

        // return solve(coins,n-1,amount,dp);

        for (int i = 0; i < n; i++) {
            dp[i][0] = 1;
        }

        for (int j = 0; j <= amount; j++) {
            if (j % coins[0] == 0) {
                dp[0][j] = 1;
            } else
                dp[0][j] = 0;
        }

        for (int i = 1; i < n; i++) {
            for (int j = 0; j <= amount; j++) {
                long long take = 0;

                if (j >= coins[i])
                    take = dp[i][j - coins[i]];

                long long skip = dp[i - 1][j];

                dp[i][j] = (take + skip) % mod;
            }
        }

        return dp[n - 1][amount];
    }
};
