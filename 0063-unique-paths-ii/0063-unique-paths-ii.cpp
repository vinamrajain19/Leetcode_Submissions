class Solution {
public:
    
    
    int dp[101][101];
    int f(vector<vector<int>>& o,int i,int j){
        int m = o.size(),n=o[0].size();
        
        if(i >= m or j>= n) return 0;
        
        if(o[i][j] == 1) return 0;
        
        if(i == m-1 and j == n-1) return 1;
        
        if(dp[i][j] != -1) return dp[i][j];
        
        
        
        int a = f(o,i+1,j);
        int b = f(o,i,j+1);
        
        return dp[i][j] =  a+b;
        
    }
    
    int uniquePathsWithObstacles(vector<vector<int>>& o) {
        memset(dp,-1,sizeof(dp));
        return f(o,0,0);
    }
};