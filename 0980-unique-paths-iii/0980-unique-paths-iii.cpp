class Solution {
   public:
     int dfs(vector<vector<int>>& grid,int x,int y,int zero){
       if(x< 0 ||y<0||y>=grid[0].size()|| x >= grid.size() || grid[x][y]==-1 )
       return 0;
       if(grid[x][y]==2)
            return zero ==-1 ? 1 : 0;
       grid[x][y]=-1;
       zero--;
       int uniquePaths=dfs(grid,x+1,y,zero)+
       dfs(grid,x,y+1,zero)+
       dfs(grid,x-1,y,zero)+
       dfs(grid,x,y-1,zero);
       //backtracking 
       grid[x][y]=0;
       zero++;
       return uniquePaths;
       
    }
    int uniquePathsIII(vector<vector<int>>& grid) {
        int zero=0,sx=0,sy=0;
        for(int i=0;i<grid.size();++i){
            for(int j=0;j<grid[0].size();++j){
                if(grid[i][j]==0)zero++;
                else if(grid[i][j]==1){
                    sx=i;
                    sy=j;
                }
            }
        }
        return dfs(grid,sx,sy,zero);
    }
};