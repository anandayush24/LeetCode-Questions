class Solution {
public:
    int solution(vector<pair<int, int>>& players, int index, int temp, vector<vector<int>>& dp){
        if(index==players.size()){
            return 0;
        }
        if(dp[index][temp]!=-1){
            return dp[index][temp];
        }
        if(players[index].second>=temp){
            //if the player is selected
            int take= players[index].first + solution(players, index+1, players[index].second, dp);
            //if the player is not selected
            int notTake= solution(players, index+1, temp, dp);
            return dp[index][temp]= max(take, notTake);
        }
        else{
            return solution(players, index+1, temp, dp);
        }
    }
    int bestTeamScore(vector<int>& scores, vector<int>& ages) {
        int n= scores.size();
        vector<pair<int, int>> players;
        for(int itr=0; itr<n; itr++){
            players.push_back({scores[itr], ages[itr]});
        }
        vector<vector<int>> dp(1001, vector<int>(1001, -1));
        sort(players.begin(), players.end());
        return solution(players, 0, 0, dp);
    }
};