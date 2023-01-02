//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
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

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n, m;
		cin >> n >> m;
		vector<vector<int>>image(n, vector<int>(m,0));
		for(int i = 0; i < n; i++){
			for(int j = 0; j < m; j++)
				cin >> image[i][j];
		}
		int sr, sc, newColor;
		cin >> sr >> sc >> newColor;
		Solution obj;
		vector<vector<int>> ans = obj.floodFill(image, sr, sc, newColor);
		for(auto i: ans){
			for(auto j: i)
				cout << j << " ";
			cout << "\n";
		}
	}
	return 0;
}
// } Driver Code Ends