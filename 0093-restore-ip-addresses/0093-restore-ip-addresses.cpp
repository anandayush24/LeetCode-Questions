class Solution {
public:
    vector<string>res;
    void backtrack(int i,int dots,string curIP,string s){
        if(dots==4 && i==s.size()) {
            curIP.pop_back();
            res.push_back(curIP);
            return;
        }
        if(dots>4) return;
        int count=0;
        for(int j=i;j<s.size();j++){
            if(count==3) break;
            string t="";
            for(int k=i;k<=j;k++)  t+=s[k];
            if(stoi(t)<256 && (i==j || s[i]!='0')) {
            backtrack(j+1,dots+1,curIP+t+"." ,s);
            }
            count++;
            
        }

    }
    vector<string> restoreIpAddresses(string s) {
        if(s.size()>12) return {};
        backtrack(0,0,"",s);
        return res;
    }
};