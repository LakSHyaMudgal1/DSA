class Solution {
public:
    void nextPermutation(vector<int>& arr) {
        int idx = -1;
        int n = arr.size();
        for(int i = n - 2; i >= 0; i--){
            if(arr[i] < arr[i + 1]){
                idx = i;
                break;
            }
        }
        if(idx == -1){
            reverse(arr.begin(), arr.end());
            return ;
        }
        for(int i = n - 1; i >= 0; i--){
            if(arr[idx] < arr[i]){
                swap(arr[idx], arr[i]);
                break;
            }
        }
        reverse(arr.begin() + idx + 1, arr.end());

    }
};