class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        vector<vector<int>> dp(grid.size(),vector<int>(grid[0].size(),-1));
        return help(grid,grid.size()-1,grid[0].size()-1,dp);
    }
    int help(vector<vector<int>>& grid,int i,int j,vector<vector<int>> &dp){
        
        if(i<0 or j<0) return 1e9;
        
        if(i == 0 and j == 0) return dp[i][j] = grid[0][0];
        
        if(dp[i][j] != -1) return dp[i][j];
        
        int u = grid[i][j] + help(grid,i-1,j,dp);
        int l = grid[i][j] + help(grid,i,j-1,dp);
        
        return dp[i][j] = min(u,l);
    }
};