class Solution {
public:
    bool solution(vector<int>& nums, int index, vector<int>& dp){
        if(index>=nums.size()-1){
            return true;
        }
        if(nums[index]==0){
            return false;
        }
        if(dp[index]!= -1){
            return dp[index];
        }
        
        int jump= index+nums[index];
        for(int itr=index+1; itr<= jump; itr++){
            if(solution(nums, itr, dp)==true){
                return dp[index]= true;
            }
        }
        
        return dp[index]= false;
    }
    bool canJump(vector<int>& nums) {
        int n= nums.size();
        vector<int> dp(n+1, -1);
        return solution(nums, 0, dp);
    }
};

// class Solution {
// public:
//     bool solution(vector<int>&nums, int index, vector<int>&dp){
//         if(index>=nums.size()-1){ return true; }
//         if(nums[index]==0){ return false; }
        
//         if(dp[index] != -1){ return dp[index]; }
//         for(int itr=index+1; itr<=(index + nums[index]); itr++){
//             if(solution(nums,itr,dp)){
//                 return dp[index]=true;
//             }
//         }
//         return dp[index]=false;
//     }
//     bool canJump(vector<int>& nums) {
//         int n=nums.size();
//         vector<int> dp(n+1, -1);
//         bool k=solution(nums,0,dp);
//         return k;
//     }
// };