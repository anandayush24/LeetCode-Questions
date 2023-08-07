class Solution {
private:
    bool rowSearch(vector<vector<int>>& matrix, int target, int row){
        int start=0, end=matrix[row].size()-1;
        while(start <= end){
            int mid = (start+end)/2;
            if(matrix[row][mid] == target){ return true; }
            if(matrix[row][mid] > target){ end = mid-1; }
            if(matrix[row][mid] < target){ start = mid+1; }   
        }
        return false;
    }
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        if (!matrix.size() || !matrix[0].size()) return false;
        int start=0, end=matrix.size()-1;
        
        while(start < end){
            int mid = (start+end)/2;
            if(matrix[mid].front() == target) return true;
            else if(matrix[mid].back() < target){ start = mid+1; }
            else if(matrix[mid].front() > target){ end = mid-1;}
            else{
                start = mid;
                break;
            }
        }
        
        bool k = rowSearch(matrix, target, start);
        return k;
    }
};