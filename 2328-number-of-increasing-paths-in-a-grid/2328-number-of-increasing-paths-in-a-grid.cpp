class Solution {
public:
    int mod = 1e9 + 7;
    
    long long f(int i,int j,int prev,vector<vector<int>> &grid,vector<vector<int>> &dp){
        if(i< 0 or j< 0 or i >= grid.size() or  j >= grid[i].size() or grid[i][j] <= prev){
            return 0;
        }
        
        if(dp[i][j] != -1) return dp[i][j];
        
        int u = f(i-1,j,grid[i][j],grid,dp) % mod;
        int d = f(i+1,j,grid[i][j],grid,dp) % mod;
        int l = f(i,j-1,grid[i][j],grid,dp) % mod;
        int r = f(i,j+1,grid[i][j],grid,dp) % mod;
        
        return dp[i][j] = (1LL + u + d + l + r) % mod;
    }
    
    int countPaths(vector<vector<int>>& grid) {
        int ans = 0;
        vector<vector<int>> dp(grid.size(),vector<int>(grid[0].size(),-1));
        for(int i = 0;i<grid.size();i++){
            for(int j = 0;j<grid[i].size();j++){
                ans  = (ans + f(i,j,-1,grid,dp)) % mod;
            }
        }
        
        return ans % mod;
    }
};