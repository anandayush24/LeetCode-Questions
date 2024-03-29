class Solution {
public:
    vector<int> getOrder(vector<vector<int>>& tasks) {
        for(int i=0; i<tasks.size(); i++){
            tasks[i].push_back(i);
        }
        sort(tasks.begin(), tasks.end(), greater<vector<int>>());
        for(auto& p: tasks){
            swap(p[0], p[1]); 
            swap(p[1], p[2]);
        }
        priority_queue<vector<int>, vector<vector<int>>, greater< vector<int> > > que;
        vector<int> ans;
        long curTime = 0;
        while(!tasks.empty() || !que.empty()){
            if(que.empty())
                curTime = tasks.back()[2];
            else{
                curTime += que.top()[0];
                ans.push_back(que.top()[1]); que.pop();
            }
            while(!tasks.empty() && tasks.back()[2] <= curTime) {
                que.push(tasks.back()); 
                tasks.pop_back();
            }
        }
        return ans;   
    }
};