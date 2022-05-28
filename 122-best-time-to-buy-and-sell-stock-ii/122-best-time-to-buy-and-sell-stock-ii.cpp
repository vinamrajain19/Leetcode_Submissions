class Solution {
public:
    
   /* int help(vector<int> &p,int idx,int buy,vector<vector<int>> &dp){
        if(idx == p.size()) return 0;
        
        if(dp[idx][buy] != -1) return dp[idx][buy];
        
        //buy -> buy or not buy -> in buy -> p -> negative -> add in profit
        if(buy){
            return dp[idx][buy] = max(-p[idx] + help(p,idx+1,0,dp), help(p,idx+1,1,dp));
        }
        
        //sell -> sell it or not sell -> sell -> positive -> add in profit
        else{
            return dp[idx][buy] = max(p[idx] + help(p,idx+1,1,dp), help(p,idx+1,0,dp));
        }
    }
    */
    int maxProfit(vector<int>& p) {
        int n = p.size();
        
       vector<int> prev(2,0),curr(2,0);
        
        for(int i = n-1;i>=0;i--){
            
            curr[1] = max(-p[i] + prev[0],prev[1]);
            curr[0] =  max(p[i] + prev[1],prev[0]);
            prev = curr;
        }
        
        return prev[1];
    }
};