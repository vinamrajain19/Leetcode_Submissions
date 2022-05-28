class Solution {
public:
    int maxProfit(int k, vector<int>& p) {
        int n = p.size();
        vector<vector<int>> after(2,vector<int>(k+1,0));
         vector<vector<int>> curr(2,vector<int>(k+1,0));
        
        
        for(int idx = n-1;idx>=0;idx--){
            
            for(int buy = 0;buy<=1;buy++){
                
                for(int cap = 1;cap<=k;cap++){
                    
                    if(buy){
                      curr[buy][cap] = max(-p[idx] + after[0][cap], after[1][cap]);
                     }
        
        //sell -> sell it or not sell -> sell -> positive -> add in profit
                    else{
                        curr[buy][cap] = max(p[idx] + after[1][cap-1],after[0][cap]);
                    }
                    
                }
            }
            after = curr;
        }
        
        return after[1][k];
    }
};