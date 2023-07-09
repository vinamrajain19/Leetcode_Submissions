class Solution {
public:
    
    int dp[50001][3];
    int f(vector<int> &p,int i,int buy){
        if(i >= p.size()) return 0;
        
        if(dp[i][buy] != -1) return dp[i][buy];
        
        if(buy){
            return dp[i][buy]  = max(-p[i] + f(p,i+1,0), f(p,i+1,1));
        }
        else return dp[i][buy] =  max(p[i] + f(p,i+2,1),f(p,i+1,0));
    }
    int maxProfit(vector<int>& prices) {
        memset(dp,-1,sizeof(dp));
        return f(prices,0,1);
    }
};