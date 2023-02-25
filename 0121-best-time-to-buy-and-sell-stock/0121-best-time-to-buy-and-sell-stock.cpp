class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int ans=0;
        int ele=prices[0];
        for(int i=1;i<prices.size();i++){
            ele = min(ele, prices[i]);
            ans = max(ans, (prices[i] - ele));
        }
        return ans;
    }
};