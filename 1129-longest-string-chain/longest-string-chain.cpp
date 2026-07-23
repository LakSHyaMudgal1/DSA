class Solution {
public:
    bool compare(string &a, string &b){
        int n = a.size(), m = b.size();
        if(m - n != 1) return false;

        int i = 0, j = 0;

        while(i < n && j < m){
            if(a[i] == b[j]){
                i++;
                j++;
            } else {
                j++;
            }
        }

        return i == n;
    }

    int longestStrChain(vector<string>& words) {
        int n = words.size();

        sort(words.begin(), words.end(), [](string &a, string &b){
            return a.size() < b.size();
        });

        vector<int> dp(n, 1);
        int maxi = 1;

        for(int i = 0; i < n; i++){
            for(int last = 0; last < i; last++){
                if(compare(words[last], words[i])){
                    dp[i] = max(dp[i], 1 + dp[last]);
                }
            }
            maxi = max(maxi, dp[i]);
        }

        return maxi;
    }
};