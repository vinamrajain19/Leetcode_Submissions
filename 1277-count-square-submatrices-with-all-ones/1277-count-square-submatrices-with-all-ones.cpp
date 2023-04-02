class Solution {
public:
    int countSquares(vector<vector<int>>& mat) {
        int m = mat.size();
        int n = mat[0].size();
        
        
        vector<vector<int>> dp(m,vector<int>(n,0));
        
        int ans = 0;
        
        for(int i = 0;i<m;i++){
            
            for(int j = 0;j<n;j++){
                
                if(i == 0 or j == 0){
                    dp[i][j] = mat[i][j];
                }
                else if(mat[i][j]== 1){
                    dp[i][j] = 1 + min({dp[i-1][j],dp[i][j-1],dp[i-1][j-1]});
                }else{
                    dp[i][j] = 0;
                }
                
                ans += dp[i][j];
            }
        }
        
        return ans;
    }
};