class Solution {
public:
    bool check(vector<vector<char>>& b,string word,int r,int c,int cnt){
        if(cnt==word.size())return true;
        if(r<0||c<0||r>=b.size()||c>=b[0].size()||word[cnt]!=b[r][c]){
            return false;
        }
        char ch=b[r][c];
        b[r][c]='.';
        bool ans=check(b,word,r+1,c,cnt+1)||check(b,word,r,c+1,cnt+1)||check(b,word,r,c-1,cnt+1)||check(b,word,r-1,c,cnt+1);
        b[r][c]=ch;//backtrack
       return ans;
    }
    bool exist(vector<vector<char>>& board, string word) {
          for(int i=0;i<board.size();i++){
            for(int j=0;j<board[0].size();j++){
                if(board[i][j]  == word[0] && check(board,word,i,j,0)){
                    return true;
                }
            }
        }
        return false;
    }
};