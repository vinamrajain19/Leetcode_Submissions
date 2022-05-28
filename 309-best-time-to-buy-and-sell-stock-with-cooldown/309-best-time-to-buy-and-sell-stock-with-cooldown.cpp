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
        
       // vector<vector<int>> dp(n+2,vector<int>(2,0));
       
    // Space optimised using three vector< of size 2
        vector<int> ahead1(2,0);
        vector<int> ahead2(2,0);
        vector<int> curr(2,0);
        
        for(int i = n-1;i>=0;i--){
            //buy -> buy -> 1 so we omit that for loop
            curr[1] = max(-p[i] + ahead1[0],ahead1[1]);
            
            //sell -> sell -> 0
            curr[0] = max(p[i]+ahead2[1],ahead1[0]);
            
            ahead2 = ahead1;
            ahead1 = curr;
        }
        
        return ahead1[1];
    }
    
};