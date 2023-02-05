class Solution {
public:
    bool solution(string str1, string str2){
        vector<int> vec1(26, 0), vec2(26, 0);
        for(int i=0; i<str1.size(); i++){
            vec1[str1[i]-'a']++;
            vec2[str2[i]-'a']++;
        }
        
        return vec1==vec2;
    }
    vector<int> findAnagrams(string s, string p) {
        int i=0, j=p.size()-1;
        int n= p.size();
        vector<int> ans;
        while(j<s.size()){
            if(solution(p, s.substr(i, n))){
                ans.push_back(i);
            }
            i++; j++;
        }
        
        return ans;
    }
};