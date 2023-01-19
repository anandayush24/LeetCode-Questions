class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int sum=nums[0] , temp=0;
        int n = nums.size()-1;
        
        for(int i=0; i<=n ; i++){
            temp = temp + nums[i];
            sum = max(sum,temp);
        
        if(temp<0)
            temp = 0;
        }
        return sum;
        
    }
};