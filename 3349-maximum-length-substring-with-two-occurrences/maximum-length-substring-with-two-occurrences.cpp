class Solution {
public:
    int maximumLengthSubstring(string s) {
        unordered_map<int, int> mp;

        int n = s.size();
        int maxi = 0;
        int ans = 0;
        int l = 0, r = 0;
        while(r < n) {
            mp[s[r]]++;
            maxi = max(maxi, mp[s[r]]);
            while(maxi > 2) {
                if(mp[s[l]] == maxi) maxi--;
                mp[s[l]]--;
                l++;
            }
            ans = max(ans, r - l + 1);
            r++;
        }
        return ans;
    }
};