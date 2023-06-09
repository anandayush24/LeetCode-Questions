class Solution {
public:
    char nextGreatestLetter(vector<char>& letters, char target) {
        int low=0,high = letters.size()-1;
        char ans = letters[0];
        while(low<=high){
            int mid = low + (high-low)/2;
            int t = target-'a';
            int val = letters[mid] - 'a';
            if(t==val){
                low=mid+1;
            }
            else if(t<val){
                ans = val + 'a';
                high = mid - 1;
            }
            else{
                low = mid +1;
            }
        }
        return ans;
    }
};