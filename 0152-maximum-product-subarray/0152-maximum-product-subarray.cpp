class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int maxProd1=-1e9, res=1;
        for(int itr=0; itr<nums.size(); itr++){
            res= res* nums[itr];
            if(res>maxProd1){
                maxProd1= res;
            }
            if(res==0){
                res=1;
            }
        }
        
        int maxProd2=-1e9;
        res=1;
        for(int itr= nums.size()-1; itr>=0; itr--){
            res*= nums[itr];
            if(res>maxProd2){
                maxProd2= res;
            }
            if(res==0){
                res=1;
            }
        }
        
        return max(maxProd1, maxProd2);
    }
};