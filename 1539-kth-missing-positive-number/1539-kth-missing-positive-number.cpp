class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {
        map<int,int> mp;
        for(auto itr: arr){
            mp[itr]++;
        }
        
        int i=1, count=0;
        while(count!=k){
            if(mp[i]!=1){ 
                count++; 
            }
            if(count!=k){ 
                i++; 
            }
        }
        return i;
    }
};