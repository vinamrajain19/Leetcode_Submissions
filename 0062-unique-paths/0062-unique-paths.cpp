class Solution {
public:
    
    int dp[101][101];
    
    int f(int m,int n,int i,int j){
        if(i >= m or j >= n) return 0;
        
        if(i == m-1 and  j == n-1) return 1;
        
        if(dp[i][j] != -1) return dp[i][j];
        
        
        int a = f(m,n,i+1,j);
        int b = f(m,n,i,j+1);
        
        return dp[i][j] = a+b;
        
    }
    
    
    int uniquePaths(int m, int n) {
        memset(dp,-1,sizeof(dp));
        return f(m,n,0,0);
    }
};