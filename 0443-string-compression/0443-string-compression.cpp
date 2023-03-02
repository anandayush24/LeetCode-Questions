class Solution {
public:
    int compress(vector<char>& chars) {
        int n=chars.size();
        int st=0;
        int end=0;
        int cnt=0;
        string res="";
        while(end<n){
            if(chars[st]==chars[end]){
                cnt++;
                 end++;
            }
            else {
                if(cnt==1){
                    res+=chars[st];
                    st=end;
                    cnt=0;
                }
                else{
                    res+=chars[st];
                    string temp=to_string(cnt);
                    res+=temp;
                    st=end;
                    cnt=0;
                }
            }
        }
        
        res+=chars[st];
        string temp;
        if(cnt!=1){
            temp=to_string(cnt);
        }
        res+=temp;
        chars.clear();
        for(char ch: res){
            chars.push_back(ch);
        }
        
        return res.size();
    }
};