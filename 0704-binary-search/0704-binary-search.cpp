class Solution {
public:
    int search(vector<int> &nums, int target, int low, int high){
        int mid = (low + high)/2;
        
        if(nums[mid] == target){
            return mid;
        }
        if(nums[mid] > target){
            high = mid - 1;
            return search(nums, target, low, high);
        }
        if(nums[mid] < target){
            low = mid + 1;
            return search(nums, target, low, high);
        }
        
        return -1;
    }
public:
    int search(vector<int>& nums, int target) {
        int n = nums.size();
        int low = 0;
        int high = n-1;
        set<int> s;
        for(int i=0;i<n;i++){
            s.insert(nums[i]);
        }
        
        if(s.find(target) == s.end()){
            return -1;
        }
        
        int ans = search(nums, target, low, high);
        return ans;
    }
};