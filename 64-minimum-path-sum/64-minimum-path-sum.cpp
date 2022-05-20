class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        
        vector<vector<int>> dp(m,vector<int>(n,-1));
        
        for(int i = 0;i<m;i++){
            for(int j = 0;j<n;j++){
                if(i == 0 && j == 0) dp[i][j] = grid[i][j];
                else{
                    int u = grid[i][j];
                    if(i>0){
                        u += dp[i-1][j];
                    }
                    else u = 1e9;
                    
                    int l = grid[i][j];
                    if(j>0){
                        l += dp[i][j-1];
                    }
                    else l = 1e9;
                    
                    dp[i][j] = min(u,l);
                }
            }
        }
        
        return dp[m-1][n-1];
    }
  
};