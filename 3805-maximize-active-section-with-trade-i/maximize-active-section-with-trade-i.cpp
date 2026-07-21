class Solution {
public:
    int maxActiveSectionsAfterTrade(string s) {

        int ones = 0;
        for(char ch : s) {
            if(ch == '1') ones++;
        }

        vector<pair<char,int>> runs;

        int i = 0;
        while(i < s.size()) {
            int j = i;
            while(j < s.size() && s[j] == s[i]) {
                j++;
            }

            runs.push_back({s[i], j - i});
            i = j;
        }

        int gain = 0;

        for(int i = 1; i + 1 < runs.size(); i++) {
            if(runs[i].first == '1' &&
               runs[i - 1].first == '0' &&
               runs[i + 1].first == '0') {

                gain = max(gain,
                           runs[i - 1].second + runs[i + 1].second);
            }
        }

        return ones + gain;
    }
};