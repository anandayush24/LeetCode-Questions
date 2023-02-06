Brute Force:
```
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
int solution(vector<string>& words, int start, int end){
int ans=0;
for(int itr=start; itr<=end; itr++){
if(valid(words[itr])){
ans++;
}
}
return ans;
}
vector<int> vowelStrings(vector<string>& words, vector<vector<int>>& queries) {
vector<int> ans;
for(int itr=0; itr<queries.size(); itr++){
int temp= solution(words, queries[itr][0], queries[itr][1]);
ans.push_back(temp);
}
return ans;
}
};
```