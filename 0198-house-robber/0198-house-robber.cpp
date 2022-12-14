class Solution {
public:
    int rob(vector<int>& nums) {
        int in=0, ex=0;
        for(int i=0;i<nums.size();i++){
            int include = ex + nums[i];
            int exclude = max(in, ex);
            
            in = include;
            ex = exclude; 
        }
        
        return max(in,ex);
    }
};