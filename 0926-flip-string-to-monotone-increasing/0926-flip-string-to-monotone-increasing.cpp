class Solution {
    vector<int> zeroCount;
    int helper(int idx, string& s){
        if (idx == s.size()){
            return 0;
        }
        if (s[idx] == '1'){
            int posOp1 = zeroCount[idx+1];
            int posOp2  = 1 + helper(idx+1, s);
            return min(posOp1, posOp2);
        }else{
            return helper(idx+1, s);
        }
    }
public:
    int minFlipsMonoIncr(string s) {
        int n = s.size();
        zeroCount.resize(n+1, 0);
        for(int i=n-1; i>=0; i--){
            zeroCount[i] = zeroCount[i+1];
            if (s[i] == '0'){
                zeroCount[i] += 1;
            } 
        }
        return helper(0, s);
    }
};