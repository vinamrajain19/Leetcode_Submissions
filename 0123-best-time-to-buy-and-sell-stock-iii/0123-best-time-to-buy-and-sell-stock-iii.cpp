class Solution {
public:
    
    int dp[100001][3][3];
    int f(vector<int> &prices,int idx,int buy,int cnt){

        if(idx >= prices.size()) return 0;
        if(cnt == 2) return 0;

        if(dp[idx][buy][cnt] != -1) return dp[idx][buy][cnt];

        int a = 0;
        int b = 0;
        if(buy){
            a = -prices[idx] + f(prices,idx+1,0,cnt);
            b = f(prices,idx+1,1,cnt);
        }
        else{
            a = prices[idx] + f(prices,idx+1,1,cnt+1);
            b = f(prices,idx+1,0,cnt);
        }

        return dp[idx][buy][cnt] = max(a,b);
    }
    int maxProfit(vector<int>& prices) {
        memset(dp,-1,sizeof(dp));
        return f(prices,0,1,0);
    }
};