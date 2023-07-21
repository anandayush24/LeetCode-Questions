class Solution {
public:
    int greatest(vector<int>& arr){
        int ans= -1e9+7;
        for(int itr=0; itr<arr.size(); itr++){
            if(arr[itr]>ans){
                ans= arr[itr];
            }
        }
        return ans;
    }
    vector<bool> kidsWithCandies(vector<int>& candies, int extraCandies) {
        int n= candies.size();
        int maxi= greatest(candies);
        vector<bool> ans(n);
        
        for(int itr=0; itr<n; itr++){
            if(candies[itr]+extraCandies >= maxi){
                ans[itr]= true;
            }
            else{
                ans[itr]= false;
            }
        }
        
        return ans;
    }
};