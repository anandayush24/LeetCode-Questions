class Solution {
public:
    long long maxKelements(vector<int>& nums, int k) {
        long long ans=0;
        sort(nums.begin(), nums.end());
        priority_queue<int> pq;
        for(int i=nums.size()-1; i>=0; i--){
            pq.push(nums[i]);
            if(pq.size()==k){
                break;
            }
        }
        
        while(k--){
            int temp= pq.top();
            pq.pop();
            ans+= temp;
            
            if(temp%3==0){
                pq.push(temp/3);
            }
            else{
                pq.push((temp/3)+1);
            }
        }
        
        return ans;
    }
};