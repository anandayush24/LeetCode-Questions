class Solution {
public:
    int arraySign(vector<int>& nums) {
        int count=0;
        for(int itr=0; itr<nums.size(); itr++){
            if(nums[itr]==0){
                return 0;
            }
            else if(nums[itr]<0){
                count++;
            }
        }
        
        if(count%2==1){
            return -1;
        }
        return 1;
    }
};