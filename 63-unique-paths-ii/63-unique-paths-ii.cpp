class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& g) {
        vector<vector<int>> dp(g.size(),vector<int>(g[0].size(),-1));
        return helper(g,g.size(),g[0].size(),0,0,dp);
    }
    
    int helper(vector<vector<int>>& g,int m,int n,int i,int j,vector<vector<int>> &dp){
        if(i == m-1 and j == n-1 and g[i][j] == 0) return 1;
        
        if(i>=m or j>=n) return 0;
        
        if(g[i][j] == 1) return 0;
        
        if(dp[i][j] != -1) return dp[i][j];
        
        return dp[i][j] = helper(g,m,n,i+1,j,dp)+helper(g,m,n,i,j+1,dp);
        
    
    }
};