class Solution {
public:
    int solution(int ptr, int *count){
        while(ptr!=count[ptr]){
            count[ptr] = count[count[ptr]];
            ptr=count[ptr];
        }
        return ptr;
    }
    int minScore(int n, vector<vector<int>>& roads) {
        int temp[n], res[n];
        int result = INT_MAX;
        for(int itr=0; itr<n; itr++){
            temp[itr]=itr;
            res[itr]=INT_MAX;
        }
        for(int itr=0; itr<roads.size(); itr++){
            int x = roads[itr][0]-1;
            int y = roads[itr][1]-1;
            int z = roads[itr][2];
            res[x] = min(res[x], z);  
            res[y] = min(res[y], z);
            
            temp[solution(x,temp)] = solution(y, temp);
        }
        for(int i=0;i<n;i++){
            if(solution(i, temp) == solution(0, temp)){
                result = min(res[i], result);
            }
        }
        
        return result;
    }
};