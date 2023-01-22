class Solution {
public:
    bool isPalindrome(string& s, int from, int length){
        for (int i = from; i < length / 2; i++){
            if (s[i] != s[length - 1 - i]) return false;
        }
        return true;
    }
    void backtrack(vector<vector<string>>& res, vector<string>& candidate){
        string last = candidate[candidate.size() - 1];
        if (isPalindrome(last, 0, last.size())){
            res.push_back(candidate);
        }
        candidate.pop_back();
        for (int i = 1; i < last.size(); i++){
            if (isPalindrome(last, 0, i)){
                candidate.push_back(last.substr(0, i));
                candidate.push_back(last.substr(i, last.size() - i));
                backtrack(res, candidate);
                candidate.pop_back();
                candidate.pop_back();
            }
        }
        candidate.push_back(last);
    }
    vector<vector<string>> partition(string s) {
        vector<vector<string>> res;
        vector<string> start;
        start.push_back(s);
        backtrack(res, start);
        return res;
    }
};