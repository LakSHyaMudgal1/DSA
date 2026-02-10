class Solution {
public:
vector<string> ans;
    void f(int idx ,string &arr,string part , unordered_map<char, string >&mp){
        if(idx >= arr.size()){
            ans.push_back(part);
            return;
        }

        char ch = arr[idx];
        string str = mp[ch];
        
        for(int i = 0; i < str.size(); i++){
            part.push_back(str[i]);
            f(idx + 1, arr, part, mp);
            part.pop_back();
        }


    }

   vector<string> letterCombinations(string arr) {
        if (arr.size() == 0) return {};

        unordered_map<char, string> mp;
        mp['2'] = "abc";
        mp['3'] = "def";
        mp['4'] = "ghi";
        mp['5'] = "jkl";
        mp['6'] = "mno";
        mp['7'] = "pqrs";
        mp['8'] = "tuv";
        mp['9'] = "wxyz";

        string part;
        f(0, arr, part, mp);
        return ans;
    }

};