class Solution {
public:
    vector<int> shuffle(vector<int>& nums, int n) {
        int count = nums.size();
        vector<int> ans;
        
        for(int i=0;i<n;i++){
            int x = nums[i];
            ans.push_back(x);
            int xn = nums[n+i];
            ans.push_back(xn);
        }
        
        return ans;
    }
};