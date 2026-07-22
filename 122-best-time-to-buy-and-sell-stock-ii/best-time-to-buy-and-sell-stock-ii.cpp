class Solution {
public:
    int solve(int idx, int canBuy, int& n, vector<int>& arr, vector<vector<int>> &dp) {
        if(idx == n - 1){
            if(!canBuy) {
                return arr[idx];
            }else{
                return 0;
            }
        }

        if(dp[idx][canBuy] != -1) return dp[idx][canBuy];
        int pro  = 0;
        if(canBuy) {
            int buy = -arr[idx] + solve(idx + 1, false, n, arr, dp);
            int notBuy = solve(idx + 1, true, n, arr, dp);
            pro = max(buy, notBuy);
        }
        else{
            int sell = +arr[idx] + solve(idx + 1, true, n, arr, dp);
            int notSell = solve(idx + 1, false, n, arr, dp);
            pro = max(sell, notSell);
        }
        return dp[idx][canBuy] = pro;
    }
    int maxProfit(vector<int>& arr) {
        int n = arr.size();
        vector<vector<int>> dp(arr.size(),vector<int>(2,-1));
        return solve(0,true, n, arr,dp);
    }
};