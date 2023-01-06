class Solution {
public:
    int maxIceCream(vector<int>& costs, int coins) {
        int ans=0;
        sort(costs.begin(), costs.end());
        for(int itr=0; itr<costs.size(); itr++){
            if(costs[itr]<=coins){
                ans++;
                coins-= costs[itr];
            }
            else{
                break;
            }
        }
        return ans;
    }
};