//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution 
{
    public:
    //Function to find distance of nearest 1 in the grid for each cell.
	vector<vector<int>>nearest(vector<vector<int>>grid){
	    // Code here
	    int n= grid.size();
	    int m= grid[0].size();
	    queue<pair<pair<int, int>, int>> q;
	    vector<vector<int>> vis(n, vector<int>(m, -1));
	    vector<vector<int>> ans(n, vector<int>(m, 0));
	    
	    for(int row=0; row<n; row++){
	        for(int col=0; col<m; col++){
	            if(grid[row][col]==1){
	                q.push({{row, col}, 0});
	                vis[row][col]= 1;
	            }
	            else{
	                vis[row][col]= 0;
	            }
	        }
	    }
	    
	    vector<int> rowDir= {0, -1, 0, 1};
	    vector<int> colDir= {-1, 0, 1, 0};
	    while(!q.empty()){
	        int row= q.front().first.first;
	        int col= q.front().first.second;
	        int step= q.front().second;
	        q.pop();
	        
	        ans[row][col]= step;
	        for(int i=0; i<4; i++){
	           int newRow= row+rowDir[i];
	           int newCol= col+colDir[i];
	           
	           if(newRow>=0 && newCol>=0 && newRow<n && newCol<m && vis[newRow][newCol]==0){
	               vis[newRow][newCol]= 1;
	               q.push({{newRow, newCol}, step+1});
	           }
	        }
	    }
	    
	    return ans;
	}
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n, m;
		cin >> n >> m;
		vector<vector<int>>grid(n, vector<int>(m, -1));
		for(int i = 0; i < n; i++){
			for(int j = 0; j < m; j++){
				cin >> grid[i][j];
			}
		}
		Solution obj;
		vector<vector<int>> ans = obj.nearest(grid);
		for(auto i: ans){
			for(auto j: i){
				cout << j << " ";
			}
			cout << "\n";
		}
	}
	return 0;
}
// } Driver Code Ends