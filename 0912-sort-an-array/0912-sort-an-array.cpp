class Solution {
public:
    vector<int> sortArray(vector<int>& nums) {
        priority_queue<int, vector<int>, greater<int>> pq;
        for(auto itr: nums){
            pq.push(itr);
        }
        vector<int> ans;
        while(!pq.empty()){
            int temp= pq.top();
            ans.push_back(temp);
            pq.pop();
        }
        
        return ans;
    }
};