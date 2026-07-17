class Solution {
public:
    int f(int idx, vector<int>& nums, int sum, int target,
          vector<vector<int>> &dp, int offset){
        
        if(idx < 0) return sum == target;

        if(dp[idx][sum + offset] != -1)
            return dp[idx][sum + offset];

        int plus = f(idx - 1, nums, sum + nums[idx], target, dp, offset);
        int minus = f(idx - 1, nums, sum - nums[idx], target, dp, offset);

        return dp[idx][sum + offset] = plus + minus;
    }

    int findTargetSumWays(vector<int>& nums, int target) {
        int sum = 0;
        for(auto it : nums) sum += it;

        int offset = sum;
        int n = nums.size();

        vector<vector<int>> dp(n, vector<int>(2 * sum + 1, -1));

        return f(n - 1, nums, 0, target, dp, offset);
    }
};