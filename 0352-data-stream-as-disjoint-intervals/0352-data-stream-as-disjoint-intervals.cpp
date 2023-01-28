class SummaryRanges {
public:
    vector<int> temp;
    vector<vector<int>> ans;
    SummaryRanges() {
        
    }
    
    vector<vector<int>> solution(vector<int> &temp){
        int n= temp.size();
        sort(temp.begin(), temp.end());
        vector<vector<int>> res;
        vector<int> arr(2, 0);
        arr[0]= temp[0];
        int itr=1;
        while(itr<n){
            if(temp[itr]==temp[itr-1]){
                itr++;
                continue;
            }
            if(temp[itr] != temp[itr-1]+1){
                arr[1]= temp[itr-1];
                res.push_back(arr);
                arr[0]= temp[itr];
            }
            itr++;
        }
        res.push_back({arr[0], temp[temp.size()-1]});
        return res;
    }
    
    void addNum(int value) {
        temp.push_back(value);
    }
    
    vector<vector<int>> getIntervals() {
        vector<vector<int>> ans= solution(temp);
        return ans;
    }
};

/**
 * Your SummaryRanges object will be instantiated and called as such:
 * SummaryRanges* obj = new SummaryRanges();
 * obj->addNum(value);
 * vector<vector<int>> param_2 = obj->getIntervals();
 */