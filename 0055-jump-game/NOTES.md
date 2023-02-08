}
}
return false;
}
bool canJump(vector<int>& nums) {
bool k=solution(nums,0);
return k;
}
};
```
​
Memoization:
​
```
class Solution {
public:
bool solution(vector<int>&nums, int index, vector<int>&dp){
if(index>=nums.size()-1){ return true; }
if(nums[index]==0){ return false; }
if(dp[index] != -1){ return dp[index]; }
for(int itr=index+1; itr<=(index + nums[index]); itr++){
if(solution(nums,itr,dp)){
return dp[index]=true;
}
}
return dp[index]=false;
}
bool canJump(vector<int>& nums) {
int n=nums.size();
vector<int> dp(n+1, -1);
bool k=solution(nums,0,dp);
return k;
}
};
​
Tabulation:
​
class Solution {
public:
bool canJump(vector<int>& nums) {
int n=nums.size();
vector<bool> dp(n,false);
dp[n-1]=true;
for(int itr1=n-2;itr1>=0;itr1--){
for(int itr2=1;itr2<=nums[itr1];itr2++){
if((itr1+itr2)<n && dp[itr1+itr2]==true ){
dp[itr1]=true;
break;
}
}
}
return dp[0];
}
};
​