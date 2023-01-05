//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    //BFS
    bool bfs(vector<int> adj[], vector<int>& vis, int start){
        queue<pair<int, int>> q;
        q.push({start,-1});
        vis[start]= 1;
        while(!q.empty()){
            int node= q.front().first;
            int parent= q.front().second;
            q.pop();
            
            for(auto itr: adj[node]){
                if(vis[itr]==-1){
                    q.push({itr, node});
                    vis[itr]= 1;
                }
                else if(vis[itr]==1 && itr!= parent){
                    return true;
                }
            }
        }
        
        return false;
    }
    //DFS
    bool dfs(vector<int> adj[], vector<int>& vis, int start){
        stack<pair<int, int>> st;
        st.push({start,-1});
        vis[start]= 1;
        
        while(!st.empty()){
            int node= st.top().first;
            int parent= st.top().second;
            st.pop();
            
            for(auto itr: adj[node]){
                if(vis[itr]==-1){
                    st.push({itr, node});
                    vis[itr]=1;
                }
                else if(vis[itr]==1 && itr!= parent){
                    return true;
                }
            }
        }
    }
    // Function to detect cycle in an undirected graph.
    bool isCycle(int V, vector<int> adj[]) {
        // Code here
        vector<int> vis(V, -1);
        for(int node=0; node<V; node++){
            if(vis[node]==-1){
                if(dfs(adj, vis, node)){
                    return true;
                }
            }
        }
        return false;
    }
};

//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int V, E;
        cin >> V >> E;
        vector<int> adj[V];
        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        Solution obj;
        bool ans = obj.isCycle(V, adj);
        if (ans)
            cout << "1\n";
        else
            cout << "0\n";
    }
    return 0;
}
// } Driver Code Ends