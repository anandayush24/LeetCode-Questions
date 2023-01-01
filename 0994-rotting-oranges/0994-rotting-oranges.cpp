class Solution {
public:
    bool checkone(vector<vector<int>>& vis){
        for(int i=0; i<vis.size(); i++){
            for(int j=0; j<vis[0].size(); j++){
                if(vis[i][j]== -1){
                    return true;
                }
            }
        }
        return false;
    }
    int solution(vector<vector<int>>& grid, vector<vector<int>>& vis){
        int maxtime=-1;
        queue<pair<pair<int,int>, int>> q;
        for(int i=0; i<grid.size(); i++){
            for(int j=0; j<grid[0].size(); j++){
                if(grid[i][j]==2){
                    q.push({{i,j}, 0});
                    vis[i][j]= 2;
                }
                else if(grid[i][j]==0){
                    vis[i][j]= 0;
                }
            }
        }
        if(q.empty() && !checkone(vis)){
            return 0;
        }
        int dcol[]= {-1, 0, 1, 0};
        int drow[]= {0, -1, 0, 1};
        while(!q.empty()){
            int row= q.front().first.first;
            int col= q.front().first.second;
            int curtime= q.front().second; 
            maxtime= max(maxtime, curtime);
            q.pop();
            
            for(int itr=0; itr<4; itr++){
                int nrow= row+ drow[itr];
                int ncol= col+ dcol[itr];
                
                if((nrow>=0 && nrow<grid.size() && ncol>=0 && ncol<grid[0].size()) 
                    && grid[nrow][ncol]== 1 && vis[nrow][ncol]== -1){
                        q.push({{nrow, ncol}, curtime+1});
                        vis[nrow][ncol]= 2;
                }
            }
        }
        if(checkone(vis)){
            return -1;
        }
        return maxtime;
    }
    
    int orangesRotting(vector<vector<int>>& grid) {
        int m= grid.size();
        int n= grid[0].size();
        vector<vector<int>> vis(m, vector<int>(n,-1));
        
        return solution(grid, vis);
    }
};