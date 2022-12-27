class Solution {
public:
    int maximumBags(vector<int>& capacity, vector<int>& rocks, int additionalRocks) {
        int n = rocks.size();
        vector<int> temp(n);
        for(int i=0;i<n;i++){ temp[i] = capacity[i] - rocks[i]; }
        sort(temp.begin(),temp.end());
        int ans=0, i=0;
        while(additionalRocks>0 && i<n && temp[i]<=additionalRocks){
            if(temp[i]==0){ 
                ans++; i++; }
            else if(additionalRocks>=temp[i]){
                ans++;
                additionalRocks = additionalRocks-temp[i];
                i++;
            }
        }
        return ans;
    }
};