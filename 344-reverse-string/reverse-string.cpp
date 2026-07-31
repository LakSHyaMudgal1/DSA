class Solution {
public:
    void solve(vector<char>& s, int i, int j) {
        if(i >= j) return;

        swap(s[i], s[j]);
        solve(s, i + 1, j - 1);
    }
    void reverseString(vector<char>& s) {
        int n = s.size();
        return solve(s, 0, n - 1);
    }
};