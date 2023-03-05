class Solution {
public:
long long int toggle(vector<int>& nums, int minK, int maxK,int in,int jn)
{
    if(in>jn){return 0;}
    // cout<<in<<" "<<jn<<endl;
    int mini=-1,maxi=-1;
    int i=in;
    while(i<=jn&&(mini==-1||maxi==-1))
    {
        if(nums[i]==minK){mini=i;}
        if(nums[i]==maxK){maxi=i;}
        i++;
    }
    // cout<<mini<<" "<<maxi<<endl;
    long long int ans=0;
    if(mini==-1||maxi==-1){return 0;}
    ans+=(min(mini,maxi)-in+1)*(jn-max(mini,maxi)+1);
    return ans+toggle(nums,minK,maxK,min(mini,maxi)+1,jn);
}
    long long countSubarrays(vector<int>& nums, int minK, int maxK) {
        long long int ans=0;
        int start=0;
        nums.push_back(maxK+1);
        for(int i=0;i<nums.size();i++)
        {
          if(nums[i]<minK||nums[i]>maxK){
              ans+=toggle(nums,minK,maxK,start,i-1);
              start=i+1;
          }
        }
        return ans;
    }
};