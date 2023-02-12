class Solution {
public:
    long long res=0;
    long long solve(vector<int>&vis,vector<int>adj[],int node,int seats){
        vis[node]=1;
        long long c=1;
        for(auto it:adj[node]){
            if(!vis[it]){
                c+=solve(vis,adj,it,seats);
            }
        }
        long long x=c/seats;
        if(c%seats){
            x++;
        }
        if(node!=0){
            res+=x;
        }
        return c;
    }
    long long minimumFuelCost(vector<vector<int>>& roads, int seats) {
        int n=roads.size();
        vector<int>vis(n+1),adj[n+1];
        for(auto it:roads){
            adj[it[0]].push_back(it[1]);
            adj[it[1]].push_back(it[0]);

        }
        solve(vis,adj,0,seats);
        return res;
    }
};