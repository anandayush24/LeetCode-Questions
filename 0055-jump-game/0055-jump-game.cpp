class Solution {
public:
    bool canJump(vector<int>& nums) {
        int n=nums.size();
        vector<bool> dp(n,false);
        
        dp[n-1]=true;
        for(int itr1=n-2;itr1>=0;itr1--){
            for(int itr2=1;itr2<=nums[itr1];itr2++){
                if((itr1+itr2)<n && dp[itr1+itr2]==true ){
                    dp[itr1]=true;
                    break;
                }
            }
        }
        return dp[0];
    }
};