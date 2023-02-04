class Solution {
public:
    map<pair<int, int>, int> mp;
    int row=0, col=0;
    Solution(int m, int n) {
        row=m;
        col=n;
    }
    
    vector<int> flip() {
        int i, j;
        while(true){
            i= rand()%row;
            j= rand()%col;
            
            if(mp[{i,j}]==0){
                mp[{i,j}]=1;
                break;
            }
        }
        
        vector<int> ans= {i,j};
        return ans;
    }
    
    void reset() {
        mp.clear();
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(m, n);
 * vector<int> param_1 = obj->flip();
 * obj->reset();
 */