class Solution {
public:
    int findNumberOfLIS(vector<int>& arr) {
        int n = arr.size();
        vector<int> dp(n, 1);
        vector<int> cnt(n, 1);
        int maxi = 0;
        for(int i = 0; i < n; i++){
            for(int last = 0; last < i; last++){
                if(arr[i] > arr[last] && dp[last] + 1 > dp[i]){
                    dp[i] = dp[last] + 1;
                    cnt[i] = cnt[last];
                }else if(arr[i] > arr[last] && dp[last] + 1 == dp[i]){
                    cnt[i] += cnt[last];
                }
            }
            maxi = max(maxi, dp[i]);
        }
        int ans = 0;
        for(int i = 0; i < n; i++){
            if(dp[i] == maxi) ans += cnt[i];
        }
        return ans;
    }
};