class Solution {
public:
    vector<vector<int>> shiftGrid(vector<vector<int>>& grid, int k) {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<int>> ans = grid;
        while(k != 0) {
            for(int i = 0; i < m; i++) {
                for(int j = 0; j < n; j++) {
                    int col = j + 1;
                    int row = i;
                    if(col == n){
                        row++;
                        col = 0;
                    }
                    if(row == m){
                        row = 0;
                    }

                    ans[row][col] = grid[i][j];
                }
            }
            grid = ans;
            k--;
        }
        return ans;
    }
};