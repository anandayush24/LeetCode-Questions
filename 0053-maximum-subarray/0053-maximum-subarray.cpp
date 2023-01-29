class Solution {
public:
    void solution(vector<int>& nums, int index, int &temp, int &ans){
        if(index==nums.size()){
            return;
        }
        temp+= nums[index];
        if(temp>ans){
            ans= temp;
        }
        if(temp<0){
            temp=0;
        }
        
        solution(nums, index+1, temp, ans);
    }
    int maxSubArray(vector<int>& nums) {
        int temp=0, ans= INT_MIN;
        solution(nums, 0, temp, ans);
        
        return ans;
    }
};