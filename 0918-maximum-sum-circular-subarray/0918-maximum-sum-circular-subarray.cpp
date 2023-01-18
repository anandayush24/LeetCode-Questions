class Solution {
private:
    int maxSubArraySum(vector<int>& nums){
        int sum=0;
        int maxim=nums[0];
        
        for(int i=0; i<nums.size(); i++){
            sum=sum+nums[i];
            maxim=max(maxim,sum);
            if(sum<0){
                sum=0;
            }
        }
        return maxim;
    }
public:
    int maxSubarraySumCircular(vector<int>& nums){
        int n=nums.size();
        int maxim=nums[0];
        maxim=max(maxim,maxSubArraySum(nums));
        
        int sum=accumulate(nums.begin(),nums.end(),0);
        int minim=nums[0];
        
        for(auto &x:nums){
            x=x*-1;
        }
        
        minim=maxSubArraySum(nums)*-1;
        if(sum-minim!=0){
            maxim=max(maxim,sum-minim);
        }
        
        return maxim;
    }
};