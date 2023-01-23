//{ Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function template for C++

class Solution{
  public:
    int solution(string &str, int index, int &ans){
        if(index==str.size()){
            return ans;
        }
        if(str[index]-'0'>=0 && str[index]-'0'<=9){
            ans= 10*ans + (str[index]-'0');
        }
        else{
            return -1;
        }
        return solution(str, index+1, ans);
    }
    /*You are required to complete this method */
    int atoi(string str) {
        //Your code here
        int ans=0;
        if(str[0]=='-'){
            int temp= solution(str, 1, ans);
            if(temp!=-1){
                return -1*temp;
            }
            else{
                return -1;
            }
        }
        return solution(str, 0, ans);
    }
};

//{ Driver Code Starts.
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		string s;
		cin>>s;
		Solution ob;
		cout<<ob.atoi(s)<<endl;
	}
}
// } Driver Code Ends