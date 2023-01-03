class Solution {
public:
    bool toDelete(vector<string>& strs, int n){
        string str;
        for(int i=0; i<strs.size(); i++){
            str.push_back(strs[i][n]);
        }
        string temp= str;
        sort(temp.begin(), temp.end());
        return str==temp;
    }
    int minDeletionSize(vector<string>& strs) {
        int n= strs[0].size();
        int count=0;
        for(int itr=0; itr<n; itr++){
            if(!(toDelete(strs, itr))){
                count++;
            }
        }
        return count;
    }
};