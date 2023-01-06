//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++
long long int dp[100001];
long long int m=1e9+7;
class Solution {
  public:
    
    long long int topDown(int n) {
        // code here
         if(n==0 || n==1){
            return n;
        }
        if(dp[n]!=-1){
            return dp[n]%m;
        }
        return dp[n]=(topDown(n-2)+topDown(n-1))%m;
    }
    long long int bottomUp(int n) {
        // code here
        long long int f[n+1];
        f[0]=0;
        if(n>=1){
            f[1]=1;
        }
        for(int i=2;i<=n;i++){
            f[i]=(f[i-1]+f[i-2])%m;
            f[i]%=m;
        }

        return f[n];
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        for (int i = 0; i < 100001; i++) dp[i] = -1;
        int n;
        cin >> n;
        Solution obj;
        long long int topDownans = obj.topDown(n);
        long long int bottomUpans = obj.bottomUp(n);
        if (topDownans != bottomUpans) cout << -1 << "\n";
        cout << topDownans << "\n";
    }
}
// } Driver Code Ends