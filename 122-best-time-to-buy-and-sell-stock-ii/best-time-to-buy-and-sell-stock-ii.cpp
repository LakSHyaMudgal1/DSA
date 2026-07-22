class Solution {
public:
    int f(int idx, bool canBuy, vector<int>& arr, vector<vector<int>> &dp){
        if(idx == arr.size()-1){
            if(!canBuy) return arr[idx];
            else return 0;
        }
        if(dp[idx][canBuy] != -1) return dp[idx][canBuy] ;
        int pro = 0;
        if(canBuy){
            int pick = -arr[idx] + f(idx + 1, 0, arr, dp);
            int notPick = f(idx + 1, 1, arr, dp);
            pro = max(pick, notPick);
        }else{
            int sell = +arr[idx] + f(idx+1, 1, arr,dp);
            int notSell = f(idx + 1, 0, arr,dp);
            pro = max(sell, notSell);
        }
        return dp[idx][canBuy] = pro;
        
    }
    int maxProfit(vector<int>& arr) {
        bool canBuy = true;
        vector<vector<int>> dp(arr.size(),vector<int>(2,-1));
        return f(0,canBuy,arr,dp);
    }
};