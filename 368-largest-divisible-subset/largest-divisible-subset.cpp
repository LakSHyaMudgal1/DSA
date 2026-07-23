class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans(n, 0);
        vector<int> hash(n, 0);
        sort(nums.begin(), nums.end());

        for (int i = 0; i < n; i++) {
            hash[i] = i;
            for (int prev = 0; prev < i; prev++) {
                if (nums[i] % nums[prev] == 0 && ans[i] < 1 + ans[prev]) {
                    ans[i] = 1 + ans[prev];
                    hash[i] = prev;
                }
            }
        }

        int maxi = INT_MIN, idx = -1;
        for (int i = 0; i < n; i++) {
            if (ans[i] > maxi) {
                maxi = ans[i];
                idx = i;
            }
        }
        vector<int> res;
        while (hash[idx] != idx) {
            res.push_back(nums[idx]);
            idx = hash[idx];
        }
        res.push_back(nums[idx]);

        return res;
    }
};