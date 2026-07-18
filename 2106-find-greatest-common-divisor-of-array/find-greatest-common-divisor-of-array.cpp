class Solution {
public:
    int findGCD(vector<int>& nums) {
        int s = INT_MAX;
        int l = INT_MIN;

        for(int i = 0; i < nums.size(); i++) {
            s = min(s, nums[i]);
            l = max(l, nums[i]);
        }

        return __gcd(s, l);
    }
};