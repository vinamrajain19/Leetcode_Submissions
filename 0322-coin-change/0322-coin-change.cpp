class Solution {
public:
    
    
    
    int f(vector<int> &c,int amt,int idx,vector<vector<int>> &dp){
        
        if(amt < 0) return 1e9;
        
        if(amt == 0) return 0;
        
        if(idx == c.size()-1){
            if(amt % c[idx] == 0) return (amt/c[idx]);
            return 1e9;
        }
        
        if(dp[idx][amt] != -1) return dp[idx][amt];
        
        int t = 1e9;
        
        if(c[idx] <= amt){
            t = 1 + f(c,amt-c[idx],idx,dp);
        }

        int no = f(c,amt,idx+1,dp);
        
        return dp[idx][amt] =  min(t,no);
    }
     
    int coinChange(vector<int>& c, int amt) {
        vector<vector<int>> dp(c.size(),vector<int>(amt+1,-1));
        int ans = f(c,amt,0,dp);
        
        if(ans >= 1e9) return -1;
        return ans;
    }
};