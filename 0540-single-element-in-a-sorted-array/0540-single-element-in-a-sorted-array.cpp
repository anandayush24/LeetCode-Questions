class Solution {
public:
    bool check(vector<int> &nums , int x ){
        if(nums[x]!=nums[x+1] && nums[x]!=nums[x-1]){
            return true;
        }
        else return false;
    } 

    bool check2(vector<int> &nums , int x){
        if((nums[x]==nums[x+1] && x%2==0) || (nums[x]==nums[x-1] && x%2!=0)){
            return true;
        }
        else return false;
    }
    int singleNonDuplicate(vector<int>& nums) {
        int n =(int)nums.size();
        int ans;
        int low = 0, high= n-1;
        if(n==1){
            return nums[0];
        }
        if(nums[0]!=nums[1]){
            return nums[0];
        }
        if(nums[high]!=nums[high-1]){
            return nums[high];
        }
        while(low<high){
            int mid = (low+high)/2;
            if(check(nums,mid)){
               return nums[mid];
            }
            else if(check2(nums,mid)){
                low = mid+1;
            }
            else{
                high=mid-1;
            }
        }
        return nums[low];
    }
};