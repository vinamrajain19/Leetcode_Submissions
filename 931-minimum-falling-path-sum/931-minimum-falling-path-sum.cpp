class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n = matrix.size();
        vector<vector<int>> dp(n,vector<int>(n,-1));
        
        int ans = INT_MAX;
        
        // call for every element in last row and find min of all because it is a variable starting pt and variable ending pt problem
        for(int i = 0;i<n;i++){
            int temp = help(n-1,i,n,matrix,dp);
            ans = min(ans,temp);
        }
        
        return ans;
    }
    
    int help(int i,int j,int n,vector<vector<int>>& matrix,vector<vector<int>>& dp){
        if(i<0 or j<0 or j>=n) return 1e9;
        
        if(i == 0) return matrix[i][j];
        
        if(dp[i][j] != -1) return dp[i][j];
        
        int u = matrix[i][j] + help(i-1,j,n,matrix,dp);
        int ld = matrix[i][j] + help(i-1,j-1,n,matrix,dp);
        int rd = matrix[i][j] + help(i-1,j+1,n,matrix,dp);
        
        return dp[i][j] = min(u,min(ld,rd));
    }
};