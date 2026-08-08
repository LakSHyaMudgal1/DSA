class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        queue<pair<int,int>> q;

        int n = image.size();
        int m = image[0].size();

        vector<vector<int>> vis(n,vector<int>(m,0));

        int oColor = image[sr][sc] ;

        vis[sr][sc] = 1;
        image[sr][sc] = color;

        q.push({sr,sc});

        int drow[] = {-1, 0, 1, 0};
        int dcol[] = {0, -1, 0, 1};


        while(!q.empty()){

            auto it = q.front();
            q.pop();

            int row = it.first;
            int col = it.second;
            image[row][col] = color;

            for(int i = 0; i < 4; i++){

                int nrow = row + drow[i];
                int ncol = col + dcol[i];


                if(nrow >= 0 && nrow < n && ncol >= 0 && ncol < m
                        && vis[nrow][ncol] == 0 && image[nrow][ncol] == oColor){

                    q.push({nrow,ncol});
                    vis[nrow][ncol] = 1;

                }
            }
        }
        
        return image;
    }
};