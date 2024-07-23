class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int totalgas = 0 ,totalcost = 0;

        for(int i = 0; i < gas.size(); i++){
            totalgas += gas[i];
            totalcost += cost[i];
        }

        if(totalcost > totalgas){
            return -1 ;
        }

        int initialtankgas = 0, start = 0;

        for(int i = 0; i < gas.size(); i++){
            initialtankgas += gas[i];
            initialtankgas -= cost[i];
            if(initialtankgas < 0){
                start = i+1;
                initialtankgas = 0;
            }
        }
        return start ;
    }
};