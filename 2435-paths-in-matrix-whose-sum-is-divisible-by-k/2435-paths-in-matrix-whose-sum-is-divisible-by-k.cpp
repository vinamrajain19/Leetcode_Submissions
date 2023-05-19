class Solution {
public:
    int mod = 1e9+7;
    
    int f(vector<vector<int>> &grid,int i,int j,int k,int sum,vector<vector<vector<int>>> &dp
){
        if(i >= grid.size() or j >= grid[0].size()) return 0;
        
        if(i == grid.size()-1 and j == grid[0].size()-1){
            sum = (sum + grid[i][j]) % k;
            if(sum % k == 0) return 1;
            return 0;
        }
        
        if(dp[i][j][sum] != -1) return dp[i][j][sum];
        
        int a = f(grid,i+1,j,k,(sum+grid[i][j]) % k,dp) % mod;
        
        int b = f(grid,i,j+1,k,(sum+grid[i][j]) % k,dp) % mod;
        
        return dp[i][j][sum] = (a + b)%mod;
    }
    
    int numberOfPaths(vector<vector<int>>& grid, int k) {
        
            vector<vector<vector<int>>> dp(grid.size(),vector<vector<int>>(grid[0].size(),vector<int>(k+1,-1)));

        return f(grid,0,0,k,0,dp) % mod;
    }
};