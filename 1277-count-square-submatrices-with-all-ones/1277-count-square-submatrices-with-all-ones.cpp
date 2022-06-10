class Solution {
public:
    int countSquares(vector<vector<int>>& mat) {
        int m = mat.size();
        int n = mat[0].size();
        vector<vector<int>> dp(m,vector<int>(n,0));
        
        for(int i = 0;i<m;i++){
            dp[i][0] = mat[i][0];
        }
        for(int j = 0;j<n;j++){
            dp[0][j] = mat[0][j];
        }
        
        for(int i = 1;i<m;i++){
            for(int j = 1;j<n;j++){
                
                if(mat[i][j]){
                    
                    int u = dp[i-1][j];
                    int l = dp[i][j-1];
                    int ud = dp[i-1][j-1];
                
                    dp[i][j] = 1 + min({u,l,ud});
                }
            }
        }
        
        int cnt =  0;
        for(int  i = 0;i<m;i++){
            for(int j = 0;j<n;j++){
                cnt += dp[i][j];
            }
        }
        return cnt;
    }
};