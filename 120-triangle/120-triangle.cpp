class Solution {
public:
    int minimumTotal(vector<vector<int>>& t) {
        vector<vector<int>> dp(t.size(),vector<int>(t.size(),-1));
        return help(0,0,t.size(),t.size(),t,dp);
    }
    
    int help(int i,int j,int n,int m,vector<vector<int>>& t,vector<vector<int>> &dp){
        if(i == m-1) return dp[i][j] = t[i][j];
        
        if(i>=m or j>=n) return 1e9;
        
        if(dp[i][j] != -1) return dp[i][j];
        
        int d = t[i][j] + help(i+1,j,m,n,t,dp);
        int dia = t[i][j] + help(i+1,j+1,m,n,t,dp);
        
        return dp[i][j] = min(d,dia);
    }
};