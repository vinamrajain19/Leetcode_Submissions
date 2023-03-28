class Solution {
public:
    
    int dp[101][101];
    
    int f(vector<vector<int>> &mat,int i,int j){
        
        if(j < 0 or i >= mat.size() or j >= mat[0].size()) return 1e5;
        
        if(i == mat.size()-1) return mat[i][j];
        
        if(dp[i][j] != -1) return dp[i][j];
         
        int a = mat[i][j] + f(mat,i+1,j);
        int b = mat[i][j] + f(mat,i+1,j-1);
        int c = mat[i][j] + f(mat,i+1,j+1);
        
        return dp[i][j] =  min({a,b,c});
    }
    
    
    int minFallingPathSum(vector<vector<int>>& mat) {
        
        memset(dp,-1,sizeof(dp));
        int ans = 1e9;
        
        for(int i = 0;i<mat[0].size();i++){
            ans = min(ans,f(mat,0,i));
        }
        
        return ans;
    }
};