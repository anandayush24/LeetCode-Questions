class Solution {
public:
    set<vector<int>> st;
    vector<int> temp;
    void solution(vector<int>& nums, int index){
        if(index>=nums.size()){
            if(temp.size()>=2){
                st.insert(temp);
            }
            return;
        }
        //take
        if(temp.empty()==true || nums[index]>=temp.back()){
            temp.push_back(nums[index]);
            solution(nums, index+1);
            temp.pop_back();
        }
        //not take
        solution(nums, index+1);
    }
    vector<vector<int>> findSubsequences(vector<int>& nums) {
        solution(nums, 0);
        return vector(st.begin(), st.end());
    }
};