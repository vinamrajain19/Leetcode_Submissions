class Solution {
public:
    int help(vector<int> &p,int idx,int buy,vector<vector<int>> &dp){
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
    }
    int maxProfit(vector<int>& p) {
        int n = p.size();
        
        vector<vector<int>> dp(n,vector<int>(2,-1));
        
        return help(p,0,1,dp);
    }
    
};