class Solution {
public:
    int missingInteger(vector<int>& nums) {
        int sum = nums[0];
        unordered_map<int, int> mp;
        for(auto num : nums) mp[num]++;
        for(int i = 1; i < nums.size(); i++) {
            if(nums[i] == 1 + nums[i - 1]) sum += nums[i];
            else break;
        }
        while(mp.count(sum) != 0) {
            sum++;
        }
        return sum;
    }
};