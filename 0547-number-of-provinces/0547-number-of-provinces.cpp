class Solution {
public:
    void dfs(vector<vector<int>>& adjList, vector<int>& vis, int start){
        stack<int> st;
        vis[start]= 1;
        for(auto node: adjList[start]){
            st.push(node);
        }
        while(!st.empty()){
            int node= st.top();
            st.pop();
            
            if(vis[node]==0){
                vis[node]= 1;
                dfs(adjList, vis, node);
            }
            
        }
    }
    int findCircleNum(vector<vector<int>>& adj) {
        int V= adj.size();
        vector<vector<int>> adjList(V);
        for(int i=0; i<V; i++){
            for(int j=0; j<V; j++){
                if(adj[i][j]==1){
                    adjList[i].push_back(j);
                    adjList[j].push_back(i);
                }
            }
        }
        vector<int> vis(V,0);
        int count= 0;
        
        for(int itr= 0; itr<V; itr++){
            if(vis[itr]==0){
                count++;
                dfs(adjList, vis, itr);
            }
        }
        
        return count;
    }
};