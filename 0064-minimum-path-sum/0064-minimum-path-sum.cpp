class Solution {
public:
    
    int dp[201][201];
    
    int f(vector<vector<int>> &grid,int i,int j){
        if(i >=grid.size() or j >= grid[0].size()) return 1e9;
        
        if(i == grid.size()-1 and j == grid[0].size()-1) return grid[i][j];
        
        if(dp[i][j] != -1) return dp[i][j];
        
        int a = grid[i][j] + f(grid,i+1,j);
        int b = grid[i][j] +  f(grid,i,j+1);
        
        return dp[i][j] = min(a,b);
    }
    
    int minPathSum(vector<vector<int>>& grid) {
        memset(dp,-1,sizeof(dp));
        return f(grid,0,0);
    }
};