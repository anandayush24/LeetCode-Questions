class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        vector<int> counts(k);
        int ans = 0;
        int curSum = 0;
        counts[0] = 1;
        for(int i=0; i<nums.size(); i++){
            curSum += nums[i];
            int op1 = curSum%k;
            if (op1 < 0){
                op1 += k;
            }
            ans += counts[op1] ;
            counts[op1]++;
        }
        return ans;
    }
};