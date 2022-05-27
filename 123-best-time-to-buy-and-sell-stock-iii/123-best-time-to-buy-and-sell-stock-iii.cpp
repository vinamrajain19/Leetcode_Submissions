class Solution {
public:
    int help(vector<int> &p,int idx,int buy,vector<vector<vector<int>>> &dp,int count){
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
    }
        
    int maxProfit(vector<int>& p) {
        int n = p.size();
        vector<vector<vector<int>>> dp(n+1,vector<vector<int>>(2,vector<int>(3,0)));
        
        for(int idx = n-1;idx>=0;idx--){
            
            for(int buy = 0;buy<=1;buy++){
                
                for(int cap = 1;cap<=2;cap++){
                    
                    if(buy){
                      dp[idx][buy][cap] = max(-p[idx] + dp[idx+1][0][cap], dp[idx+1][1][cap]);
                     }
        
        //sell -> sell it or not sell -> sell -> positive -> add in profit
        else{
          dp[idx][buy][cap] = max(p[idx] + dp[idx+1][1][cap-1],dp[idx+1][0][cap]);
        }
                    
                }
            }
        }
        
        return dp[0][1][2];
    }
};