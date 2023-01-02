class Solution {
public:
    void dfs(vector<vector<char>>& grid, vector<vector<int>>& vis, int row, int col){
        int drow[]= {0, -1, 0, 1};
        int dcol[]= {-1, 0, 1, 0};
        for(int itr=0; itr<4; itr++){
            int nrow= row+ drow[itr];
            int ncol= col+ dcol[itr];
            
            if(nrow>=0 && nrow<grid.size() && ncol>=0 && ncol<grid[0].size()){
                if(grid[nrow][ncol]=='1' && vis[nrow][ncol]==-1){
                    vis[nrow][ncol]=1;
                    dfs(grid, vis, nrow, ncol);
                }
            }      
        }
    }
    int numIslands(vector<vector<char>>& grid) {
        int m= grid.size();
        int n= grid[0].size();
        int ans=0;
        vector<vector<int>> vis(m, vector<int>(n, -1));
        for(int  i=0; i<m; i++){
            for(int j=0; j<n; j++){
                if(grid[i][j]=='1' && vis[i][j]==-1){
                    ans++;
                    dfs(grid, vis, i, j);
                }
                else{
                    vis[i][j]=1;
                }
            }
        }
        
        return ans;
    }
};