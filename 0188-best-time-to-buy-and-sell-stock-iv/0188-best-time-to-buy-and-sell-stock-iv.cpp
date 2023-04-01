class Solution {
public:
    
    int dp[1001][3][101];
    int f(vector<int> &prices,int idx,int buy,int cnt,int k){

        if(idx >= prices.size()) return 0;
        if(cnt == k) return 0;

        if(dp[idx][buy][cnt] != -1) return dp[idx][buy][cnt];

        int a = 0;
        int b = 0;
        if(buy){
            a = -prices[idx] + f(prices,idx+1,0,cnt,k);
            b = f(prices,idx+1,1,cnt,k);
        }
        else{
            a = prices[idx] + f(prices,idx+1,1,cnt+1,k);
            b = f(prices,idx+1,0,cnt,k);
        }

        return dp[idx][buy][cnt] = max(a,b);
    }
    int maxprofit(vector<int>& prices,int k) {
        memset(dp,-1,sizeof(dp));
        return f(prices,0,1,0,k);
    }
    
    
    int maxProfit(int k, vector<int>& prices) {
        return maxprofit(prices,k);
    }
};