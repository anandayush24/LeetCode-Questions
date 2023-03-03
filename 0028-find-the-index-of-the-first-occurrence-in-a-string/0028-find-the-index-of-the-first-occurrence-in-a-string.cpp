class Solution {
public:
    int strStr(string haystack, string needle) {
        int n= needle.size(), h= haystack.size();
        if(n>h){
            return -1;
        }
        int low= 0, high= n-1;
        string temp= haystack.substr(0, n);
        while(high<h){
            if(temp==needle){
                return low;
            }
            low++; high++;
            temp.erase(temp.begin());
            temp+= haystack[high];
        }
        
        return -1;
    }
};