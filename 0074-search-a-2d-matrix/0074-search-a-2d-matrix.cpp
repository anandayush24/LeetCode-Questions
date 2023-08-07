class Solution {
public:
    bool solution(vector<int>& arr, int target){
        int n= arr.size();
        int low=0, high= n-1;
        
        while(low<=high){
            int mid= (low+high)/2;
            
            if(arr[mid]==target){
                return true;
            }
            else if(arr[mid]>target){
                high= mid-1;
            }
            else{
                low= mid+1;
            }
        }
        
        return false;
    }
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m= matrix.size();
        int left=0, right= m-1;
        
        while(left<=right){
            int mid= (left+right)/2;
            
            if(matrix[mid].front()<=target && matrix[mid].back()>= target){
                return solution(matrix[mid], target);
            }
            else if(matrix[mid].front()> target){
                right= mid-1;
            }
            else{
                left= mid+1;
            }
        }
        
        return false;
    }
};