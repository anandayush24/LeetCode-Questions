class Solution {
public:
    string reverseWords(string s) {
        string ans;
        stack<char> st;
        int i=s.size()-1;
        bool flag=false;
        while(i>=0){
            flag=false;
            if(s[i]!=' '){
                st.push(s[i]);
                i--;
                continue;
            }
        
            while(!st.empty()){
                ans+=st.top();
                st.pop();
                flag=true;
            }
            
            while(i>=0 && s[i]==' '){
                i--;
            }
            if(flag && i>=0){
                ans+=' ';
            }
        }
        while(!st.empty()){
            ans+=st.top();
            st.pop();
        }
        return ans;
    }
};