class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int n= nums.size();
        int ans=INT_MIN, temp=0;
        for(int itr=0; itr<n; itr++){
            temp+= nums[itr];
            if(temp>ans){
                ans= temp;
            }
            
            if(temp<0){
                temp=0;
            }
        }
        return ans;
    }
};