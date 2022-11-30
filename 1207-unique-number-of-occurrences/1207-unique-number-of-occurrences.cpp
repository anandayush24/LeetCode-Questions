class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        unordered_map<int, vector<int>> mp;
        unordered_map<int, int> freq;
        for(auto itr: arr){
            freq[itr]++;
        }
        for(auto itr: freq){
            mp[itr.second].push_back(itr.first);
            if(mp[itr.second].size()>1){
                return false;
            }
        }
        
        return true;
    }
};