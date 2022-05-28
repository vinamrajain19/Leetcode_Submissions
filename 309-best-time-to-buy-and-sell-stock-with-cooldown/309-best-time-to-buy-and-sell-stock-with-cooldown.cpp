class Solution {
public:
  /*  int help(vector<int> &p,int idx,int buy,vector<vector<int>> &dp){
        if(idx >= p.size()) return 0;
        
        if(dp[idx][buy] != -1) return dp[idx][buy];
        
        //buy -> buy or not buy -> in buy -> p -> negative -> add in profit
        if(buy){
            return dp[idx][buy] = max(-p[idx] + help(p,idx+1,1-buy,dp), help(p,idx+1,buy,dp));
        }
        
        //sell -> sell it or not sell -> sell -> positive -> add in profit
        else{
            return dp[idx][buy] = max(p[idx] + help(p,idx+2,1-buy,dp), help(p,idx+1,buy,dp));
        }
    } */
    
    int maxProfit(vector<int>& p) {
        int n = p.size();
        
        vector<vector<int>> dp(n+2,vector<int>(2,0));
        
        for(int i = n-1;i>=0;i--){
            //buy -> buy -> 1 so we omit that for loop
            dp[i][1] = max(-p[i] + dp[i+1][0],dp[i+1][1]);
            
            //sell -> sell -> 0
            dp[i][0] = max(p[i]+dp[i+2][1],dp[i+1][0]);
        }
        
        return dp[0][1];
    }
    
};