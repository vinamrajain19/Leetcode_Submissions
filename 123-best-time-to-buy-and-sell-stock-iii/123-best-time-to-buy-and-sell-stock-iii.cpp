class Solution {
public:
  /*  int help(vector<int> &p,int idx,int buy,vector<vector<vector<int>>> &dp,int count){
        if(idx == p.size() || count == 0) return 0;
        
        if(dp[idx][buy][count] != -1) return dp[idx][buy][count];
        
        //buy -> buy or not buy -> in buy -> p -> negative -> add in profit
        if(buy){
            return dp[idx][buy][count] = max(-p[idx] + help(p,idx+1,0,dp,count), help(p,idx+1,1,dp,count));
        }
        
        //sell -> sell it or not sell -> sell -> positive -> add in profit
        else{
            return dp[idx][buy][count] = max(p[idx] + help(p,idx+1,1,dp,count-1), help(p,idx+1,0,dp,count));
        }
    } */
        
    int maxProfit(vector<int>& p) {
        int n = p.size();
        vector<vector<int>> after(2,vector<int>(3,0));
         vector<vector<int>> curr(2,vector<int>(3,0));
        
        
        for(int idx = n-1;idx>=0;idx--){
            
            for(int buy = 0;buy<=1;buy++){
                
                for(int cap = 1;cap<=2;cap++){
                    
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
        
        return after[1][2];
    }
};