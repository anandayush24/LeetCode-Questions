//{ Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template for C++

class Solution{
public:
    int remove_duplicate(int a[],int n){
        // code here
        int count=1;
        vector<int> ans;
        int temp= a[0];
        ans.push_back(a[0]);
        for(int itr=1; itr<n; itr++){
            if(a[itr]!=temp){
                count++;
                temp= a[itr];
                ans.push_back(temp);
            }
        }
        for(int itr=0; itr<n; itr++){
            a[itr]=ans[itr];
        }
        return count;
    }
};

//{ Driver Code Starts.
int main()
{
    int T;
    cin>>T;
    while(T--)
    {
        int N;
        cin>>N;
        int a[N];
        for(int i=0;i<N;i++)
        {
            cin>>a[i];
        }
    Solution ob;
    int n = ob.remove_duplicate(a,N);

    for(int i=0;i<n;i++)
        cout<<a[i]<<" ";
    cout<<endl;
    }
}
// } Driver Code Ends