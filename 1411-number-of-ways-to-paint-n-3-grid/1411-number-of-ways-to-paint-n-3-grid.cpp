class Solution {
public:
    
    int dp[5001][4][4][4];
    int mod = 1e9+7;
    
    int f(int n,int i,int j1,int j2,int j3){
        if(i == n) return 1;
        
        if(dp[i][j1][j2][j3] != -1) return dp[i][j1][j2][j3];
        
        int ans = 0;
        
        for(int col1 = 1;col1<=3;col1++){
            
            if(col1 == j1) continue;
            
            for(int col2 = 1;col2<=3;col2++){
                
                if(col2 == j2 or col2 == col1) continue;
                
                for(int col3 = 1;col3 <= 3;col3++){
                    
                    if(col3 == j3 or col3 == col2) continue;
                    
                    ans = (ans+f(n,i+1,col1,col2,col3)) % mod;
                }
            }
        }
        
        return dp[i][j1][j2][j3] = ans % mod;
    }
    
    int numOfWays(int n) {
        memset(dp,-1,sizeof(dp));
        return f(n,0,0,0,0)%mod;
    }
};