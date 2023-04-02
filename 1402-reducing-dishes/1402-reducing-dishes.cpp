class Solution {
public:
    int maxSatisfaction(vector<int>& satisfaction) {
        sort(satisfaction.begin(), satisfaction.end());
        int n = satisfaction.size();
        int tmp = 0, ans = 0;

        int prev = 0;
        for (int i=n-1; i>=0; i--) {
            tmp = tmp + satisfaction[i];
            prev = prev + tmp;
            ans = max(ans, prev);
        }

        return ans;
    }
};