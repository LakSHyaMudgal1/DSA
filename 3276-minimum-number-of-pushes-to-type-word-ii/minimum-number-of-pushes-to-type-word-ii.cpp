class Solution {
public:
    int minimumPushes(string word) {
        vector<int> hash(26, 0);
        for(auto it : word) hash[it - 'a']++;

        sort(hash.rbegin(), hash.rend());
        int ans = 0;
        for(int i = 0; i < 26; i++) {
            if(i + 1 <= 8) {
                ans += hash[i];
            }
            else if(i + 1 <= 16) {
                ans += 2 * hash[i];
            }
            else if(i + 1 <= 24) {
                ans += 3 * hash[i];
            }
            else {
                ans += 4 * hash[i];
            } 
        }
        return ans;
    }
};