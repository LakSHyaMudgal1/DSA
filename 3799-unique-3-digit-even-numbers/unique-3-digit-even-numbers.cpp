class Solution {
public:
    
    int totalNumbers(vector<int>& digits) {
        int n = digits.size();
        vector<int> vis(1001, 0);

        for(int i = 0; i < n; i++) {
            if(digits[i] == 0) continue;
            for(int j = 0; j < n; j++) {
                if(i == j) continue;
                for(int k = 0; k < n; k++) {
                    if(k == i || k == j) continue;
                    int num = digits[k] + 10 * digits[j] + 100 * digits[i];
                    if(num % 2 == 0) vis[num]++;
                }
            }
        }
        int ans = 0;
        for(int i = 0; i < 1001; i++) if(vis[i] != 0) ans++;
        return ans;
    }
};