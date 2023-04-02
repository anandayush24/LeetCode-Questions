class Solution {
public:
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        int n = days.size();
        int dp[n+1];
        dp[0]=0;
        for(int i =1;i<=n;i++){
            int ind7 = upper_bound(days.begin(),days.end(),days[i-1]-7) - days.begin();
            int ind15 = upper_bound(days.begin(),days.end(),days[i-1]-30) - days.begin();
            dp[i]= min (costs[0]+dp[i-1], min ( costs[1]+ dp[ind7] , costs[2] + dp[ind15]) );
        }
        
        return dp[n];
    }
};