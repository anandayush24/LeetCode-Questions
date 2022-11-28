class Solution {
public:
    vector<vector<int>> findWinners(vector<vector<int>>& matches) {
        vector<int> non, one;
        unordered_map<int, int> lost, won;
        for(int itr=0; itr<matches.size(); itr++){
            won[matches[itr][0]]++;
            lost[matches[itr][1]]++;
        }
        
        for(auto itr: won){
            if(lost.find(itr.first)==lost.end()){
                non.push_back(itr.first);
            }
        }
        
        for(auto itr: lost){
            if(itr.second==1){
                one.push_back(itr.first);
            }
        }
        sort(non.begin(), non.end());
        sort(one.begin(), one.end());
        
        return {non, one};
    }
};