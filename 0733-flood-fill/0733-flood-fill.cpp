class Solution {
public:
    void solution(vector<vector<int>>& grid, int sr, int sc, int color, vector<vector<int>>& temp, int currColor){
        int drow[]= {0, -1, 0, 1};
        int dcol[]= {-1, 0, 1, 0};
        for(int itr=0; itr<4; itr++){
            int nrow= sr+ drow[itr];
            int ncol= sc+ dcol[itr];
            if(nrow>=0 && nrow<grid.size() && ncol>=0 && ncol<grid[0].size()){
                if(grid[nrow][ncol]==currColor && temp[nrow][ncol] !=color){
                    temp[nrow][ncol]= color;
                    solution(grid, nrow, ncol, color, temp, currColor);
                }
            }
        }
    }
    vector<vector<int>> floodFill(vector<vector<int>>& grid, int sr, int sc, int color) {
        vector<vector<int>> temp= grid;
        int currColor= grid[sr][sc];
        temp[sr][sc]= color;
        solution(grid, sr, sc, color, temp, currColor);
        
        return temp;
    }
};