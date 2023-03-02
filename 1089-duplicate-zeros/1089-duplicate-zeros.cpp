class Solution {
public:
    void duplicateZeros(vector<int>& arr) {
        queue<int> q;
        for(auto itr: arr){
            q.push(itr);
        }
        vector<int> ans;
        while(!q.empty()){
            int temp= q.front();
            if(temp==0){
                ans.push_back(0);
                ans.push_back(0);
            }
            else{
                ans.push_back(temp);
            }
            q.pop();
        }
        
        int n= arr.size();
        arr.resize(n);
        for(int i=0; i<n; i++){
            arr[i]= ans[i];
        }
    }
};