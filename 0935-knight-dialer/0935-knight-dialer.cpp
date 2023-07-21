class Solution {
public:
   long long mod = 1e9+7;
   int dp[5001][4][3];
   int f(int n,int i,int j){
        if(i < 0 or j < 0 or i >= 4 or j >= 3 or (i == 3 and j==0) or (i == 3 and j== 2)) return 0;
        
        //base case when my n is 1 
        if(n == 1) return 1;
        
        if(dp[n][i][j] != -1) return dp[n][i][j];
        
        int ans = 0;
        ans = (ans % mod + f(n-1,i-2,j-1) % mod) % mod;
        ans = (ans % mod + f(n-1,i-2,j+1) % mod) % mod;
        ans = (ans % mod + f(n-1,i-1,j-2) % mod) % mod;
        ans = (ans % mod + f(n-1,i+1,j-2) % mod) % mod;
        ans = (ans % mod + f(n-1,i+2,j-1) % mod) % mod;
        ans = (ans % mod + f(n-1,i+2,j+1) % mod) % mod;
        ans = (ans % mod + f(n-1,i-1,j+2) % mod) % mod;
        ans = (ans % mod + f(n-1,i+1,j+2) % mod) % mod;
        
        return dp[n][i][j] = ans % mod;
    }
    
    int knightDialer(int n) {
        long long int ans = 0;
        memset(dp,-1,sizeof(dp));
        
        for(int i  = 0;i<4;i++){
            for(int j = 0;j<3;j++){
                ans = (ans % mod + f(n,i,j) % mod) % mod;
            }
        }
        
        return ans % mod; 
    }
};