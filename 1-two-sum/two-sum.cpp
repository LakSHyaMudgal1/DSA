class Solution {
public:
    vector<int> twoSum(vector<int>& arr, int tar) {
        unordered_map<int, int> mp;
        for(int i = 0; i < arr.size(); i++) {
            int d = tar - arr[i];
            if(mp.count(d) != 0){
                return {i, mp[d]};
            }
            else{
                mp[arr[i]] = i;
            }
        }
        return {};
    }
};