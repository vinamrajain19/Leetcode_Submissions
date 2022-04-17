class Solution {
public:
    int dp[1001][1001];
    int solve(int m,int n,int row,int col){
        if(row >= m || col >= n) return 0;
        if(row == m-1 and col == n-1) return 1;
        if(dp[row][col] != -1) return dp[row][col];
        
        return dp[row][col] = solve(m,n,row+1,col) + solve(m,n,row,col+1);
    }
    
    int uniquePaths(int m, int n) {
        memset(dp,-1,sizeof(dp));
        return solve(m,n,0,0);
    }
};