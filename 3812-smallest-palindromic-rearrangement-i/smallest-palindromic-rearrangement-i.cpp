class Solution {
public:
    string smallestPalindrome(string s) {
        map<char, int> mp;
        for(auto it : s) mp[it]++;

        string ans = "", temp = "";
        char mid = '#';

        for(auto it : mp) {
            int ch = it.first;
            int cnt = it.second;
            if(cnt % 2 == 1) mid = ch;
            int h = cnt / 2;
            while(h != 0) {
                ans += ch;
                temp += ch;
                h--;
            }
        }
        if(mid != '#') ans += mid;
        reverse(temp.begin(), temp.end());
        ans += temp;
        return ans;
    }
};