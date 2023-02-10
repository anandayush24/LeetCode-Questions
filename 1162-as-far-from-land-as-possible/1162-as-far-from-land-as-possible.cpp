class Solution {
public:
    int maxDistance(vector<vector<int>>& grid) {
        int n= grid.size();
        queue<pair<pair<int, int>, int>> q;
        vector<vector<int>> vis(n, vector<int>(n, -1));
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                if(grid[i][j]==1){
                    q.push({{i,j}, 0});
                    vis[i][j]= 1;
                }
            }
        }
        if(q.size()==0 || q.size()== n*n){
            return -1;
        }
        int ans=0;
        vector<int> rowMat= {-1, 0, 1, 0};
        vector<int> colMat= {0, 1, 0, -1};
        while(!q.empty()){
            auto node= q.front();
            q.pop();            
            int row= node.first.first;
            int col= node.first. second;
            int level= node.second;
            for(int i=0; i<4; i++){
                int newRow= row+ rowMat[i];
                int newCol= col+ colMat[i];
                if(newRow>=0 && newCol>=0 && newCol<n && newRow<n){
                    if(vis[newRow][newCol]==-1 && grid[newRow][newCol]==0){
                        ans= max(ans, level+1);
                        grid[newRow][newCol]=1;
                        q.push({{newRow, newCol}, level+1});
                    }
                }
            }
        }
        return ans;
    }
};