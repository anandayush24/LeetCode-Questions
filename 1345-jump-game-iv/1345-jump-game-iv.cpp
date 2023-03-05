class Solution {
public:
    int minJumps(vector<int>& arr) {
        
        int n = arr.size();
        vector<int> dist(n, -1);
        queue<int> que;
        unordered_map<int,vector<int>> M;

        for(int i = 0; i < n; i++){
            M[arr[i]].push_back(i);
        }

        que.push(0);
        dist[0] = 0;

        while(!que.empty()){

            int node = que.front();
            que.pop();

            if(node == n - 1){
                return dist[node];
            }

            int nbr;

            nbr = node - 1;
            if(nbr >= 0 && dist[nbr] == -1){
                dist[nbr] = dist[node] + 1;
                que.push(nbr);
            }

            nbr = node + 1;
            if(nbr < n && dist[nbr] == -1){
                dist[nbr] = dist[node] + 1;
                que.push(nbr);
            }

            for(auto nbr : M[arr[node]]){
                if(dist[nbr] == -1){
                    dist[nbr] = dist[node] + 1;
                    que.push(nbr);
                }
            }

            M[arr[node]].clear();

            if(dist[n - 1] != -1) return dist[n - 1];

        }

        return dist[n - 1];

    }
};