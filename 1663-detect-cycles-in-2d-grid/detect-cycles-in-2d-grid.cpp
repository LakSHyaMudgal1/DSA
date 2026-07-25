class Solution {
public:
    bool containsCycle(vector<vector<char>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        vector<vector<int>> vis(n, vector<int> (m, 0));

        for(int i = 0; i < n;i++){
            for(int j = 0; j < m; j++){
                if(!vis[i][j]){
                    if(dfs(i, j, -1, -1, grid, vis)) return true;
                }
            }
        }

        return false;
    }

    private:
    bool dfs(int row, int col, int rowp, int colp, vector<vector<char>> &grid,vector<vector<int>> &vis){
        vis[row][col] = 1;
        int n = grid.size();
        int m = grid[0].size();

        for(int i = 0; i < 4; i++){
            int nrow = row + delRow[i];
            int ncol = col + delCol[i];
            char ch = grid[row][col];

            // if(isValid(nrow, ncol, n, m)){
            //     if(nrow == rowp && ncol == colp) continue;
            //     if(ch != grid[nrow][ncol]) continue;

            //     if(!vis[nrow][ncol]){
            //         if(dfs(nrow, ncol, row, col, grid, vis)) return true;
            //     }
            //     else return true;
            // }

            if(isValid(nrow, ncol, n, m) && !vis[nrow][ncol] && grid[nrow][ncol] == ch){
                if(nrow == rowp && ncol == colp) continue;

                if(dfs(nrow, ncol, row, col, grid, vis)) return true;
            }

            else if(isValid(nrow, ncol, n, m) && vis[nrow][ncol] && grid[nrow][ncol] == ch
             && !(nrow == rowp && ncol == colp)) return true;
        }

        return false;
    }



    bool isValid(int i, int j, int n, int m){
        if(i < 0 || i >= n) return false;
        if(j < 0 || j >= m) return false;

        return true;
    }
    vector<int> delRow = {-1, 0, 1, 0};
    vector<int> delCol = {0, 1, 0, -1};
};