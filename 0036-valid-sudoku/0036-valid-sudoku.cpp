class Solution {
public:

    bool isValid(unordered_map<char, int> m) {
        for(auto i:m) {
            if(i.second >= 2) return false;
        }
        return true;
    }

    bool isValidSudoku(vector<vector<char>>& board) {
        bool rowValid = true;
        bool colValid = true;
        for(int i=0; i<9; i++) {
            
            unordered_map<char, int> m1;
            unordered_map<char, int> m2;

            for(int j=0; j<9; j++) {
                if(board[i][j] != '.') m1[board[i][j]]++; // row
                if(board[j][i] != '.') m2[board[j][i]]++; // col
            }

            rowValid = isValid(m1);
            colValid = isValid(m2);
            
            if(rowValid == false || colValid == false) return false;
        }
        
        bool grid1, grid2, grid3 = true;
        unordered_map<char, int> m1, m2, m3;

        for(int i=0; i<9; i++) {
            
            for(int j=0; j<9; j++) {
                if(0<=j && j<=2) {
                    if(board[i][j] != '.') 
                        m1[board[i][j]]++;
                }
                else if(3<=j && j<=5) {
                    if(board[i][j] != '.') 
                        m2[board[i][j]]++;
                }
                else if(6<=j && j<=8) {
                    if(board[i][j] != '.') 
                        m3[board[i][j]]++;
                }
            }            

            grid1 = isValid(m1); 
            grid2 = isValid(m2); 
            grid3 = isValid(m3);
            
            if(grid1 == false || grid2 == false || grid3 == false) 
                return false;

            if(i==2 || i==5 || i==8) {
                m1.clear(); m2.clear(); m3.clear();
            }
        }

        return true;
    }

};