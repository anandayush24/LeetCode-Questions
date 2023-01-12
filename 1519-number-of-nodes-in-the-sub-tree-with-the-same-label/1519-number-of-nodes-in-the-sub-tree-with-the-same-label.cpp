class Solution {
private:
    vector<int> dfs(int i, vector<int> adjList[], string &labels, vector<int> &visited, vector<int> &res) {
        vector<int> count(26);
        visited[i] = 1;
        for(auto v:adjList[i]) {
            if(!visited[v]) {
                vector<int> subCount = dfs(v, adjList, labels, visited, res);
                for(int k = 0; k < 26; k++) {
                    count[k] += subCount[k];
                }
            }
        }
        count[labels[i]-'a']++;
        res[i] = count[labels[i]-'a'];
        return count;
    }
public:
    vector<int> countSubTrees(int n, vector<vector<int>>& edges, string labels) {
        vector<int> visited(n, 0);
        vector<int> adjList[n];
        vector<int> res(n, 0);
        for(auto it:edges) {
            adjList[it[0]].push_back(it[1]);
            adjList[it[1]].push_back(it[0]);
        }
        dfs(0, adjList, labels, visited, res);
        return res;
    }
};