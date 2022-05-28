class Solution {
public:
    int maxProfit(vector<int>& p, int fee) {
        int n = p.size(); 
        vector<int> prev(2,0),curr(2,0);
        
        for(int i = n-1;i>=0;i--){
            for(int j = 0;j<=1;j++){
                if(j){
                    curr[j] = max(-p[i] + prev[0],prev[1]);
                }
                else{
                    curr[j] =  max(p[i] + prev[1]-fee,prev[0]);
                }
            }
            prev = curr;
        }
        
        return prev[1];
    }
};