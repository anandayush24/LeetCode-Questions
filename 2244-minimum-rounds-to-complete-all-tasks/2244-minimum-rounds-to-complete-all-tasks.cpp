class Solution {
public:
    int minimumRounds(vector<int>& tasks) {
        unordered_map<int, int> mp;
        for(auto itr: tasks){
            mp[itr]++;
        }
        
        int ans=0;
        for(auto itr: mp){
            int count= itr.second;
            if(count==1){
                return -1;
            }
            while(count){
                ans++;
                if(count>=3){
                    count-= 3;
                }
                else if(count>=2){
                    count-= 2;
                }
                else{
                    count=0;
                }
            }
        }
        
        return ans;
    }
};