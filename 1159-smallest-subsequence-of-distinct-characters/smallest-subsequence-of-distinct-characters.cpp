class Solution {
public:
    string smallestSubsequence(string s) {
        stack<char> st;
        unordered_map<int, int> mp;
        string ans = "";
        unordered_map<int, int> vis;
        for(auto ch : s) mp[ch]++;

        for(auto ch : s) {
            mp[ch]--;
            if(vis[ch]) continue;
            
            while(!st.empty() && ch < st.top() && mp[st.top()] > 0) {
                vis[st.top()] = 0;
                st.pop();
            }

            st.push(ch);
            vis[ch] = 1;
        }
        while(!st.empty()) {
            ans += st.top();
            st.pop();
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};