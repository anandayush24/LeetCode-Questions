class Solution {
public:
    vector<int> shortestAlternatingPaths(int n, vector<vector<int>>& redEdges, vector<vector<int>>& blueEdges) {
        vector<vector<pair<int,int>>> adjList(n);
        for(auto it: redEdges) {
            adjList[it[0]].push_back({it[1], 0});
        }
        for(auto it: blueEdges) {
            adjList[it[0]].push_back({it[1], 1});
        }
        vector<int> res(n, -1);
        res[0] = 0;
        queue<pair<int,pair<int,int>>> q;
        vector<vector<int>> visited(n, vector<int> (2, 0));
        q.push({0,{-1, 0}});
        visited[0][0] = 1; visited[0][1] = 1;
        while(!q.empty()) {
            int n = q.front().first, color = q.front().second.first, dist = q.front().second.second;
            q.pop();
            for(auto v:adjList[n]) {
                if(!visited[v.first][v.second] && v.second != color) {
                    visited[v.first][v.second] = 1;
                    q.push({v.first,{v.second, dist+1}});
                    if(res[v.first] == -1) res[v.first] = dist+1;
                }
            }
        }
        return res;
    }
};