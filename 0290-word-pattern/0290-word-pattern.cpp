class Solution {
public:
    bool wordPattern(string pattern, string s) {
        vector<string> arr;
        string word;
        stringstream sst(s);
        while(sst >> word){
            arr.push_back(word);
        }
        
        if(arr.size() != pattern.length())
            return false;
        
        set<string> S;
        map<char, string> mp;
        for(int i=0;i<pattern.length();i++){
            char ch = pattern[i];
            if(mp.find(ch) != mp.end()){
                if(mp[ch] != arr[i])
                    return false;
            }
            else{
                if(S.count(arr[i]) > 0)
                    return false;
                
                mp[ch] = arr[i];
                S.insert(arr[i]);
            }
        }
        
        return true;
    }
};