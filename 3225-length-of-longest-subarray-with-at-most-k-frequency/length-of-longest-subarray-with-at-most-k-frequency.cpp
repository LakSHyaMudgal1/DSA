class Solution {
public:
    int maxSubarrayLength(vector<int>& nums, int k) {
        int l = 0;
        int r = 0;
        int n = nums.size();
        int ans = 0, maxi = 0;
        unordered_map<int, int> mp;
        while(r < n) {
            mp[nums[r]]++;
            maxi = max(maxi, mp[nums[r]]);
            while(l <= r && maxi > k) {
                if(mp[nums[l]] == maxi) maxi--;
                mp[nums[l]]--;
                l++;
            }
            ans = max(ans, r - l + 1);
            r++;
        }
        return ans;
    }
};