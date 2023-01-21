```
class Solution {
public:
void solution(vector<string>& ans, vector<string>& temp, string& s, int index){
if(index==s.size() && temp.size()==4){
string x= temp[0] + '.' + temp[1] + '.' + temp[2] + '.' + temp[3];
cout<<x<<endl;
ans.push_back(x);
return;
}
string tempStr="";
for(int itr=index; itr<s.size() && temp.size()<4; itr++){
tempStr+= s[itr];
int num= stoi(tempStr);
if(num>=0 && num<=255){
cout<<tempStr<<endl;
temp.push_back(tempStr);
solution(ans, temp, s, index+1);
temp.pop_back();
}
if(num<=0 || num>255){
break;
}
}
}
vector<string> restoreIpAddresses(string s) {
vector<string> ans;
vector<string> temp;
solution(temp, ans, s, 0);
return ans;
}
};
```