class Solution {
public:
    int maximumBags(vector<int>& capacity, vector<int>& rocks, int additionalRocks) {
        int ans=0, n= capacity.size();
        vector<int> space(n,0);
        for(int itr=0; itr<n; itr++){
            space[itr]= capacity[itr]- rocks[itr];
        }   
        sort(space.begin(), space.end());
        for(auto itr: space){
            if(itr==0){
                ans++;
            }
            else if(additionalRocks>=itr){
                ans++;
                additionalRocks-=itr;
            }
            if(additionalRocks<=0 || additionalRocks<itr){
                break;
            }
        }
        return ans;
    }
};