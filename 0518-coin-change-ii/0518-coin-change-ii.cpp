class Solution {
public:
    
    int dp[301][5001];
    
    int f(int i,vector<int> &c,int amt){
        if(amt < 0) return 0;
        if(amt == 0) return 1;
        if(i>=c.size()) return 0;
        
        if(dp[i][amt] != -1) return dp[i][amt];
        
        int a = f(i,c,amt-c[i]);
        int b = f(i+1,c,amt);
        return dp[i][amt] = a+b;
    }
    
    int change(int amount, vector<int>& coins) {
        memset(dp,-1,sizeof(dp));
        return f(0,coins,amount);
    }
};