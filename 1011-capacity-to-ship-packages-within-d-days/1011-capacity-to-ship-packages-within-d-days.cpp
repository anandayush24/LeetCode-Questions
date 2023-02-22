class Solution {
public:
    bool can(vector<int>& a,int days, int weight){
        int d = 1, cur = 0;
        for(int i=0; i<a.size(); i++){
            if(a[i] > weight) return false;
            if(cur + a[i] <= weight) cur+= a[i];
            else{
                cur = a[i];
                d++;
            }
        }
        return d<=days;
    }
    int shipWithinDays(vector<int>& a, int days) {
        int low = 1, high = 0, ans = 0;
        for(int x:a) high += x; 
        while(low<=high){
            int mid = high - (high-low)/2;
            if(can(a,days,mid)==true){
                //if this weight can be taken, more weight obviously will be taken easily
                ans = mid;
                high = mid - 1; //trying less weight to be taken within days 
            }else low = mid + 1;
        }
        return ans;
    }
};