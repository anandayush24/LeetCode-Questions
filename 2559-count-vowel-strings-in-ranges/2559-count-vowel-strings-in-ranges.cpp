class Solution {
public:
    bool valid(string str){
        int n= str.size();
        set<char> st= {'a','e','i','o','u'};
        if(st.find(str[0])!=st.end() && st.find(str[n-1])!=st.end()){
            return true;
        }
        
        return false;
    }
    vector<int> vowelStrings(vector<string>& words, vector<vector<int>>& queries) {
        int n= words.size();
        vector<int> res(n, -1);
        for(int itr=0; itr<n; itr++){
            if(valid(words[itr])){
                res[itr]=1;
            }
            else{
                res[itr]=0;
            }
        }
        vector<int> prefixSum(n+1, 0);
        prefixSum[0]= res[0];
        for(int itr=1; itr<n; itr++){
            prefixSum[itr]= prefixSum[itr-1] + res[itr];
        }
        prefixSum[n]= prefixSum[n-1];
        vector<int> ans;
        for(int itr=0; itr<queries.size(); itr++){
            int temp=0;
            if(queries[itr][0]!=0)
                temp= prefixSum[queries[itr][1]] - prefixSum[queries[itr][0]-1];
            else{
                temp= prefixSum[queries[itr][1]];
            }
            ans.push_back(temp);
        }
        
        return ans;
    }
};