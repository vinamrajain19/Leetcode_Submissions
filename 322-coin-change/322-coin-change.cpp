class Solution {
public:
    int help(int idx,vector<int>& coins, int amt,vector<vector<int>> &dp){
        
        //base case
        
        if(amt == 0) return 0;
        if(idx == 0){
            if(amt % coins[0] == 0) return (amt/coins[0]);
            return 1e9;
        }
        
        if(dp[idx][amt] != -1) return dp[idx][amt];
        
        int nottake = help(idx-1,coins,amt,dp);
        int take = 1e9;
        if(coins[idx] <= amt){
            take =  1 + help(idx,coins,amt-coins[idx],dp);
        }
        
        return dp[idx][amt] = min(nottake,take);
    }
    
    int coinChange(vector<int>& coins, int amt) {
        
        vector<vector<int>> dp(coins.size(),vector<int>(amt+1,-1));
        int ans = help(coins.size()-1,coins,amt,dp);
        
        if(ans >= 1e9) return -1;
        return ans;
    }
};