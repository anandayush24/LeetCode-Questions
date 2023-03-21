class Solution {
public:
    long long zeroFilledSubarray(vector<int>& nums) {
        long long ans=0, temp=0;
        int n= nums.size();
        for(int itr=0; itr<n; itr++){
            if(nums[itr]==0){
                temp++;
                ans+= temp;
            }
            else{
                temp=0;
            }
        }
        return ans;
    }
};