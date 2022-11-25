class Solution {
public:
    vector<int> nextSmaller(vector<int> &a){
        int n = a.size();
        stack<pair<int,int>> s;
        vector<int> ans(n,0);
        for(int i = n-1 ; i >= 0 ; i--){
            while(s.size()>0 and s.top().first >= a[i]){
                s.pop();
            }
            if(s.size()==0){
                ans[i] = n;
            }
            else{
                ans[i] = s.top().second;
            }
            s.push({a[i],i});
        }
        return ans;
    }
    vector<int> prevSmaller(vector<int> &a){
        int n = a.size();
        stack<pair<int,int>> s;
        vector<int> ans(n,0);
        for(int i = 0 ; i < n ; i++){
            while(s.size()>0 and s.top().first > a[i]){
                s.pop();
            }
            if(s.size()==0){
                ans[i] = -1;
            }
            else{
                ans[i] = s.top().second;
            }
            s.push({a[i],i});
        }
        return ans;
    }
    long long mod_mul(long long a, long long b, int mod){
        return (((a%mod)*(b%mod))+mod)%mod;
    }
    int sumSubarrayMins(vector<int>& a) {
        vector<int> next = nextSmaller(a);
        vector<int> prev = prevSmaller(a);
        long long ans = 0; int mod = 1e9+7;
        int n = a.size();
        for(int i = 0 ; i < n; i ++){
            int right = next[i]-i;
            int left = i-prev[i];
            ans += mod_mul(mod_mul(left,right,mod),a[i],mod);
            ans%=mod;
        }
        return ans;
    }
};  