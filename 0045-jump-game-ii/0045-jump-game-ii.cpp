class Solution {
public:
    int jump(vector<int>& nums) {
        vector <int> dp(nums.size(), -1);
        return func(0, nums, dp);
    }

    long long int func(int ind, vector<int> &nums, vector<int> &dp){
        if(ind>=nums.size()-1)
            return 0;

        if(dp[ind] != -1)   return dp[ind];

        long long int steps=INT_MAX;
        for(int i=1; i<=nums[ind]; i++)
            steps=min(steps, 1+func(ind+i, nums, dp));

        return dp[ind]=steps;
    }
};