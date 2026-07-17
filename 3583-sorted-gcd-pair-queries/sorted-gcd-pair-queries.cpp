class Solution {
public:
    long long nCr(long long n) {
        return (n * (n - 1)) / 2;
    }

    vector<int> gcdValues(vector<int>& nums, vector<long long>& queries) {
        int n = nums.size();
        int maxi = *max_element(nums.begin(), nums.end());

        vector<long long> freq(maxi + 1, 0);
        vector<long long> cnt(maxi + 1, 0);
        vector<long long> exact(maxi + 1, 0);
        vector<long long> prefix(maxi + 1, 0);

        for(int i = 0; i < n; i++) {
            freq[nums[i]]++;
        }

        // Count numbers divisible by each value
        for(int i = 1; i <= maxi; i++) {
            for(int j = i; j <= maxi; j += i) {
                cnt[i] += freq[j];
            }
        }

        // Count pairs divisible by each value
        for(int i = 1; i <= maxi; i++) {
            exact[i] = nCr(cnt[i]);
        }

        // Inclusion-Exclusion
        for(int i = maxi; i >= 1; i--) {
            for(int j = 2 * i; j <= maxi; j += i) {
                exact[i] -= exact[j];
            }
        }

        // Prefix sum
        for(int i = 1; i <= maxi; i++) {
            prefix[i] = prefix[i - 1] + exact[i];
        }

        vector<int> ans;

        for(int i = 0; i < queries.size(); i++) {
            int idx = upper_bound(prefix.begin(), prefix.end(), queries[i]) - prefix.begin();
            ans.push_back(idx);
        }

        return ans;
    }
};