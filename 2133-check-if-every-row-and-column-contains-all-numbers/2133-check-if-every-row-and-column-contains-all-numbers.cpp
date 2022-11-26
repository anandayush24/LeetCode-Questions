class Solution {
public:
    bool solution(vector<vector<int>>& matrix, int n){
        unordered_map<int, int> row, col;
        
        for(int i=0; i<matrix.size(); i++){
            row[matrix[n][i]]++;
        }
        int k=1;
        while(k<=matrix.size()){
            if(row.find(k)==row.end()){
                return false;
            }
            k++;
        }
        
        for(int i=0; i<matrix.size(); i++){
            col[matrix[i][n]]++;
        }
        k=1;
        while(k<=matrix.size()){
            if(col.find(k)==col.end()){
                return false;
            }
            k++;
        }
        
        return true;
    }
    bool checkValid(vector<vector<int>>& matrix) {
        for(int itr=0; itr<matrix.size(); itr++){
            if(solution(matrix, itr)==false){
                return false;
            }
        }
               
        return true;
    }
};