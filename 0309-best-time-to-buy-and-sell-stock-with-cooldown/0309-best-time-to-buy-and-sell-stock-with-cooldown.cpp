class Solution {
public:
    
    int dp[5001][3];
    int f(vector<int> &p,int idx,int buy){
        if(idx >= p.size()) return 0;

        if(dp[idx][buy] != -1) return dp[idx][buy];

        if(buy == 1){
            return dp[idx][buy] = max(-p[idx] + f(p,idx+1,0), f(p,idx+1,1));
        }
        else{
            return dp[idx][buy]=  max(p[idx] + f(p,idx+2,1),f(p,idx+1,0));
        }
    }
    int maxProfit(vector<int>& prices) {
        memset(dp,-1,sizeof(dp));
        return f(prices,0,1);
    }
};