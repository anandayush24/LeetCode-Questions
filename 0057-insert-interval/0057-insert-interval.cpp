class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        vector<vector<int>>answer;
        int left=newInterval[0], right=newInterval[1];
        bool inserted=false;
        for (auto interval:intervals){
            if (interval[1]<newInterval[0]){
                answer.push_back(interval);
            }
            else if (interval[0]>newInterval[1]){
                if (!inserted){
                    answer.push_back({left,right});
                    inserted=true;
                }
                answer.push_back(interval);
            }
            else {
                left=min(left,interval[0]);
                right=max(right,interval[1]);
            }
        }
        if (!inserted){
            answer.push_back({left,right});
        }
        return answer;
    }
};