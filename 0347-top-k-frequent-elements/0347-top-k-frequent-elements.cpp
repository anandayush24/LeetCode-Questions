class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> mp;
        for(auto itr: nums){
            mp[itr]++;
        }
        
        priority_queue<pair<int, int>> pq;
        for(auto itr: mp){
            pq.push({itr.second, itr.first});
        }
        
        vector<int> ans;
        while(k--){
            ans.push_back(pq.top().second);
            pq.pop();
        }
        
        return ans;
    }
};