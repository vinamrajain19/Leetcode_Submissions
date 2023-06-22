class Solution
{
    public:
    int dp[50001][3];
    int f(vector<int> &p,int fee,int idx,int buy){
        if(idx >= p.size()) return 0;
        
        if(dp[idx][buy] != -1) return dp[idx][buy];
        
        if(buy){
            return dp[idx][buy]=  max(-p[idx] + f(p,fee,idx+1,0),f(p,fee,idx+1,1));
        }
        return dp[idx][buy] =  max(p[idx] - fee + f(p,fee,idx+1,1),f(p,fee,idx+1,0));
    }
        int maxProfit(vector<int> &prices, int fee) {
            memset(dp,-1,sizeof(dp));
            return f(prices,fee,0,1);
        }
};