class Solution {
public:
    int count(string str, set<char> st){
        int count=0;
        for(auto itr: str){
            if(st.find(itr)!=st.end()){
                count++;
            }
        }  
        return count;
    }
    bool halvesAreAlike(string s) {
        set<char> st={'a', 'e', 'i', 'o', 'u', 'A', 'E', 'I', 'O', 'U'};
        int n= s.size()/2;
        int x= count(s.substr(0,n), st);
        int y= count(s.substr(n,n), st);
        
        return x==y;
    }
};