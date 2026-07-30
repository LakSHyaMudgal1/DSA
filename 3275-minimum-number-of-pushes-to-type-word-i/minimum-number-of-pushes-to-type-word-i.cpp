class Solution {
public:
    int minimumPushes(string word) {
        unordered_map<char, int> mp;
        for(int i = 0; i < word.size(); i++) {
            mp[word[i]]++;
        }

        priority_queue<pair<int, char>> pq;
        for(auto it : mp) {
            pq.push({it.second, it.first});
        }

        int cnt = 0;
        int ans = 0;
        while(!pq.empty()) {
            auto val = pq.top();
            int freq = val.first;
            char ch = val.second;
            pq.pop();
            cnt++;
            if (cnt <= 8)
                ans += freq;
            else if (cnt <= 16)
                ans += 2 * freq;
            else if (cnt <= 24)
                ans += 3 * freq;
            else
                ans += 4 * freq;
        }

        return ans;
    }
};