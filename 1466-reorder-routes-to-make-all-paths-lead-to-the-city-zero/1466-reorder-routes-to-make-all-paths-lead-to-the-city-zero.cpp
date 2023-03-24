class Solution {
public:

    void dfs(int par, int curr, vector<vector<pair<int,int>>>& graph, int& count) {

        for (int i = 0; i < graph[curr].size(); i++) {
            int node = graph[curr][i].first;
            if (node != par) {
                int pathType = graph[curr][i].second;
                if (pathType == 0) {
                    count++;
                }
                dfs(curr, node, graph, count);
            }
        }
    }

    int minReorder(int n, vector<vector<int>>& connections) {
        int count = 0;
        vector<vector<pair<int,int>>> graph(n, vector<pair<int,int>>());
        for (int i = 0; i < connections.size(); i++) {
            int first = connections[i][0];
            int second = connections[i][1];
            graph[first].push_back({second, 0});
            graph[second].push_back({first, 1});
        }
        dfs(-1, 0, graph, count);
        return count;
    }
};