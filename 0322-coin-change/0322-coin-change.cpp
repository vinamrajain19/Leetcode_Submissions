class Solution {
public:
    
    int dp[13][10001];
    int f(vector<int> &c,int t,int i){
        
        if(t < 0) return 1e9;
        
        if(t == 0) return 0;
        
        if(i == c.size()-1){
            if(t%c[i] == 0) return t/c[i];
            return 1e9;
        }
        
        if(dp[i][t] != -1) return dp[i][t];
        
        int a = 1 + f(c,t-c[i],i);
        int b = f(c,t,i+1);
        
        return dp[i][t] =  min(a,b);
    }
    
    int coinChange(vector<int>& coins, int amount) {
        memset(dp,-1,sizeof(dp));
        
        int ans =  f(coins,amount,0);
        return ans >= 1e9 ? -1 : ans;
    }
};