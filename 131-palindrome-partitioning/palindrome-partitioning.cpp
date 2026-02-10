class Solution {
public:
    bool isPalindrome(string &s, int l, int r){
        while(l < r){
            if(s[l++] != s[r--]) return false;
        }
        return true;
    }

    void f(int idx, string s, vector<string> part, vector<vector<string>> &ans){
        if(idx == s.size()){
            ans.push_back(part);
            return;
        }

        for(int i = idx; i < s.size(); i++){
            if(isPalindrome(s, idx, i)){
                part.push_back(s.substr(idx, i - idx + 1));
                f(i + 1, s, part, ans);
                part.pop_back();
            }
        }
    }
    vector<vector<string>> partition(string s) {
        vector<vector<string>> ans;
        vector<string> part;
        f(0, s, part, ans);
        return ans;
    }
};