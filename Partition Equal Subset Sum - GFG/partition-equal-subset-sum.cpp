//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    bool solution(int arr[], int n, int sum, int index, vector<vector<int>>& dp){
        if(sum==0){
            return true;
        }
        if(index==(n-1)){
            return (arr[index]==sum);
        }
        if(dp[index][sum]!=-1){
            return dp[index][sum];
        }
        //if the index is not taken
        bool notTaken= solution(arr, n, sum, index+1, dp);
        //if the index is taken
        bool taken= false;
        if(arr[index]<=sum){
            taken= solution(arr, n, sum-arr[index], index+1, dp);
        }
        
        return dp[index][sum]= notTaken || taken;
    }
    int equalPartition(int n, int arr[])
    {
        // code here
        int sum=0;
        for(int i=0; i<n; i++){
            sum+= arr[i];
        }
        if(sum&1){
            return 0;
        }
        int target= sum/2;
        vector<vector<int>> dp(n, vector<int>(target+1, -1));
        bool ans= solution(arr, n, target, 0, dp);
        if(ans){
            return 1;
        }
        return 0;
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        int arr[N];
        for(int i = 0;i < N;i++)
            cin>>arr[i];
        
        Solution ob;
        if(ob.equalPartition(N, arr))
            cout<<"YES\n";
        else
            cout<<"NO\n";
    }
    return 0;
}
// } Driver Code Ends