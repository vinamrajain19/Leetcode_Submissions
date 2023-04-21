class Solution {
public:
    
    int dp[101][101][101];
    
    int mod = 1e9+7;
    
    int f(int n,int mp,vector<int> &g,vector<int> &p,int i,int cnt,int sum){
        if(i == g.size() and cnt <= n and sum >= mp) return 1;
        
        if(i == g.size() or cnt > n) return 0;
        
        if(dp[i][cnt][sum] != -1) return dp[i][cnt][sum];
        
        
        int ans = 0;
        if(cnt + g[i] <= n){
            ans = (f(n,mp,g,p,i+1,cnt+g[i],min(mp,sum+p[i]))) % mod;
        }
        
        int b = f(n,mp,g,p,i+1,cnt,sum) % mod;
        
        return dp[i][cnt][sum] =  (ans+b) % mod;
        
    }
    
    
    int profitableSchemes(int n, int mp, vector<int>& g, vector<int>& p) {
        memset(dp,-1,sizeof(dp));
        return f(n,mp,g,p,0,0,0);
    }
};