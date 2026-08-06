class Solution {
public:
    int ncr(int n, int r){
        int val = 1;
        for(int i = 0; i < r; i++){
            val *= n - i;
            val /= (i + 1);
        }
        return val;
    }
    void comb(int idx, vector<int>& part){
        for(int i = 0; i <= idx; i++){
            part.push_back(ncr(idx, i));
        }
    }

    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> ans;
        for(int i = 0; i < numRows; i++){
            vector<int> part;
            comb(i, part);
            ans.push_back(part);
        }

        return ans;
    }
};