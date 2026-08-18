class Solution {
public:
    int largestInteger(vector<int>& nums, int k) {
        unordered_map<int, int> freq;
        int n = nums.size();
        for(int i=0;i<=n-k;i++){
            unordered_set<int> covered;
            for(int j=i;j<i+k;j++){
                covered.insert(nums[j]);
            }
            for(int i:covered){
                freq[i]++;
            }
        }
        int res = -1;
        for (auto& [num, count]:freq) {
            if (count == 1) {
                res = max(res, num);
            }
        }
        
        return res;
    }
};