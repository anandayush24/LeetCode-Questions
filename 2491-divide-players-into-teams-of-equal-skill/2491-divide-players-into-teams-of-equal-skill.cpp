class Solution {
public:
    long long dividePlayers(vector<int>& skills) {
        sort(skills.begin(),skills.end());
        int front=0,back=skills.size()-1;
        long long result= skills[front]*skills[back];
        long long temp= skills[front++] + skills[back--];
       
        while(front<back){
            if(temp!=skills[front]+skills[back]){
                return -1;
            }
            else{
                result += skills[front]*skills[back];
            }
            front++;
            back--;
        }
        
        return result;
    }
};