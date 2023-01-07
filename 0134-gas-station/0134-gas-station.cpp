class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int totalcost = 0;
        int totalgas= 0;
        int len = gas.size();
        for(int i = 0; i < len; i++){
            totalcost += cost[i];
            totalgas += gas[i];
        }
        if(totalcost > totalgas){
            return -1;
        }
        int start = 0;
        int fuel = 0;
        for(int i = 0; i < len; i++){
           if(fuel < 0){
               fuel = 0;
               start = i;
           }
           fuel += (gas[i] - cost[i]);
        }
        return start;
    }
};