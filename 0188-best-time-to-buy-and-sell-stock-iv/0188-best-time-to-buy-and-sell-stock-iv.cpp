class Solution {
public:
    int dp[1001][101][3];
    int f(int k,vector<int> &p,int idx,int buy){
        
        if(idx >= p.size() or k == 0) return 0;
        if(dp[idx][k][buy]!=-1) return dp[idx][k][buy];
        
        int ans  = 0;
        if(buy){
            ans = max(f(k,p,idx+1,1),-p[idx]+f(k,p,idx+1,0));
        }
        else{
            ans = max(f(k,p,idx+1,0),p[idx]+f(k-1,p,idx+1,1));
        }
        return dp[idx][k][buy] = ans;
    }
    int maxProfit(int k, vector<int>& p) {
        memset(dp,-1,sizeof(dp));
        return f(k,p,0,1);
    }
};