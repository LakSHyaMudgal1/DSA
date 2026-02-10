class Solution {
public:
    bool isSafe(int row, int col, vector<string>& board, int& n){
        int r = row;
        int c = col;
        while(r >= 0 && c >= 0 ){
            if(board[r][c] == 'Q') return false;
            r--;
            c--;
        }
        r = row;
        c = col;
        while(r < n && c >= 0 ){
            if(board[r][c] == 'Q') return false;
            r++;
            c--;
        }
        r = row;
        c = col;
        while(c >= 0){
            if(board[r][c] == 'Q') return false;
            c--;
        }
        return true;

    }
    void nQueen(int col, vector<string>& board, int& n, vector<vector<string>>& ans){
        if(col == n){
            ans.push_back(board);
        }

        for(int row = 0; row < n; row++){
            if(isSafe(row, col, board, n)){
                board[row][col] = 'Q';
                nQueen(col + 1, board, n, ans);
                board[row][col] = '.';
            }
        }
    }

    vector<vector<string>> solveNQueens(int n) {
    vector<string> board(n,string(n,'.'));
    vector<vector<string>> ans ;
    nQueen(0, board, n, ans);
    return ans;
        
    }
};