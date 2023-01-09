class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int total_gas=0;
        int total_cost=0;
        int currentcost=0;
        int start=0;
        for(int i=0;i<gas.size();++i){   //total gas amount available
          total_gas+=gas[i];
        }
        for(int i=0;i<cost.size();++i){   //total coast of travel
          total_cost+=cost[i];
        }
        if( total_gas<total_cost){    /*if available gas amount is less than the total required gas amount 
then journey is not possible as we cant not reach to our starting point ,at that time simply return -1. */
            return -1;
        }
        for(int i=0;i<gas.size();++i){  /*if currentcost is negative then that cant be our starting point as that
 time increment starting point by one unit ans reset currentcost to 0 ans check for next value of i */
          currentcost+=(gas[i]-cost[i]);
              if(currentcost<0){
                start=i+1;
                currentcost=0;
              }
          
        }
        return start;
    }
};