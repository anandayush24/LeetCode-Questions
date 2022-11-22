class Solution {
public:
   int k(vector<int>& v,int m,int n,vector<int>& d){
        if(m==0){
           return 0; 
        } 
        if(d[m]!=-1){
            return d[m];
        }
        int i;
        int res=INT_MAX;
        for(i=0; i<n; i++){
            if(v[i]<=m)
            res=min(res,1+k(v,m-v[i],n,d));
        }
        return d[m]=res;
    }
    int numSquares(int n) {
        vector<int> v;
        int i;
        vector<int> d(n+1,-1);
        for(i=1; i<=101; i++){
            v.push_back(i*i);
        }
        int m=v.size();
        return k(v,n,m,d);
    }
};