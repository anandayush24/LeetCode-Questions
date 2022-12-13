class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n=matrix.size();
        
        vector<vector<int>> dp(n, vector<int>(n,-1));
        //filling first row of dp with first row of matrix
        for(int itr=0;itr<n;itr++){
            dp[0][itr]=matrix[0][itr];
        }
        
        for(int rows=1;rows<n;rows++){
            for(int cols=0;cols<n;cols++){
                int up=1e9, left=1e9, right=1e9;
                up = matrix[rows][cols] + dp[rows-1][cols];
                if(cols-1>=0){
                    left = matrix[rows][cols] + dp[rows-1][cols-1];
                }
                if(cols+1<n){
                    right = matrix[rows][cols] + dp[rows-1][cols+1];
                }
                
                dp[rows][cols] = min(up, min(left,right));
            }
        }
        int temp=1e9;
        for(int itr=0;itr<n;itr++){
            temp = min(temp, dp[n-1][itr]);
            cout<<dp[n-1][itr]<<" "<<temp<<endl;
        }
        
        return temp;
    }
};