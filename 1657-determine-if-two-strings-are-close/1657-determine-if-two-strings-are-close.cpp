class Solution {
public:
    bool closeStrings(string word1, string word2) {
        vector<int> freq1(26,0), present1(26,0);
        for(auto ch: word1){
            freq1[ch-'a']++;
            present1[ch-'a']=1;
        }
        
        vector<int> freq2(26,0), present2(26,0);
        for(auto ch: word2){
            freq2[ch-'a']++;
            present2[ch-'a']=1;
        }
        
        sort(freq1.begin(), freq1.end());
        sort(freq2.begin(), freq2.end());
        
        return (freq1==freq2) && (present1==present2);
    }
};