class Solution {
public:
    int minimumDeviation(vector<int>& nums) {
        priority_queue<int> maxheap;
        int minelement=INT_MAX;
        for(int x:nums) {
            int y=x;
            if(y&1) y=y*2;
            minelement=min(minelement,y);
            maxheap.push(y);
        }
        int diff=INT_MAX;
        while(!maxheap.empty()){
            int maxvaluetillnow=maxheap.top();
            diff=min(diff,maxvaluetillnow-minelement);
            maxheap.pop();
            if(maxvaluetillnow&1) break;  // max value cannot be decreased further
            maxheap.push(maxvaluetillnow/2);
            minelement=min(minelement,maxvaluetillnow/2);
        }
        return diff;
    }
};