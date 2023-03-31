class Solution {
public:
    
    int mod = 1e9+7;
    
    bool valid(vector<string> &pizza,int rs,int re,int cs,int ce){
        for(int i = rs;i<=re;i++){
            for(int j = cs;j<=ce;j++){
                if(pizza[i][j] == 'A') return true;
            }
        }
        
        return false;
    }
    
    
    
    int dp[51][51][11];
    
    long long f(vector<string> &pizza,int i,int j,int k){
        
        int m = pizza.size();
        int n = pizza[0].size();
        
        if(k == 0) return 1;
        
        if(dp[i][j][k] != -1) return dp[i][j][k];
        
        
        long long ans = 0;
        for(int x = i;x < m - 1;x++){
            int upper = valid(pizza,i,x,j,n-1);
            int lower = valid(pizza,x+1,m-1,j,n-1);
            
            if(upper and lower){
                ans = (ans + f(pizza,x+1,j,k-1)) % mod;
            }
        }
        
        for(int y = j;y<n-1;y++){
            int left = valid(pizza,i,m-1,j,y);
            int right = valid(pizza,i,m-1,y+1,n-1);
            
            if(left and right){
                ans = (ans + f(pizza,i,y+1,k-1)) % mod;
            }
        }
        
        return dp[i][j][k] = (int)ans % mod;
    }
    
    
    
    
    int ways(vector<string>& pizza, int k) {
        memset(dp,-1,sizeof(dp));
        return f(pizza,0,0,k-1);
    }
};