class Solution {
public:
    int dijkstra(int src, int tar, vector<int>& a){
        vector<int>dis(tar + 2, 1e5);
        priority_queue<pair<int, int>, vector< pair<int, int>>, greater< pair<int, int>>>pq;
        dis[src] = 0;
        pq.push({ 0,src });
        while (!pq.empty()){
            int u = pq.top().second;
            int c = pq.top().first;
            pq.pop();
            if (u == tar){
                return c;
            }
            
            for (int i = 1; i <= 6; i++){
                if (i + u > tar)
                    break;
                int v;
                if (a[i + u] != -1)
                    v = a[i + u];
                else
                    v = i + u;
                if (dis[v] > dis[u] + 1){
                    dis[v] = dis[u] + 1;
                    pq.push({ dis[v],v });
                }
            }
        }
        return -1;
    }
    int snakesAndLadders(vector<vector<int>>& board) {
        reverse(board.begin(), board.end());
        vector<int>a;
        a.push_back(0);
        int n = board.size();
        n *= n;
        int m = 0;
        for (auto i : board){
            if (m & 1)
                reverse(i.begin(), i.end());
            for (auto j : i)
                a.push_back(j);
            m++;
        }

        int ret = dijkstra(1, n, a);
        
        return ret;
    }
};