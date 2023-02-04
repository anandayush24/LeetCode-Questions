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
    bool checkInclusion(string s1, string s2) {
        int n= s1.size();
        int i=0, j=n-1;
        while(j<s2.size()){
            if(solution(s1, s2.substr(i, n))){
                return true;
            }
            i++; j++;
        }
        
        return false;
    }
};