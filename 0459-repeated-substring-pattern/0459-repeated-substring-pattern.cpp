class Solution {
public:
    bool repeatedSubstringPattern(string s) {
        int n= s.size();
        string temp= "";
        for(int itr=0; itr<n/2; itr++){
            temp+= s[itr];
            if(temp+s==s+temp){
                return true;
            }
        }
        
        return false;
    }
};