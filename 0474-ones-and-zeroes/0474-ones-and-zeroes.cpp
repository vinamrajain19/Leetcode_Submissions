class Solution {
public:
    
    int dp[601][101][101];
    int f(int i,vector<string> &sts,int m,int n){
        if(m < 0 or n < 0) return -1e9;
        
        if(m == 0 and n == 0) return 0;
        
        if(i >= sts.size()) return 0;
        
        if(dp[i][m][n] != -1) return dp[i][m][n];
        
        int z = 0;
        int o = 0;
        for(auto it : sts[i]){
            if(it == '0') z++;
            else o++;
        }
        
        int a = 1 + f(i+1,sts,m-z,n-o);
        int b = f(i+1,sts,m,n);
        
        return dp[i][m][n] =  max(a,b);
    }
    
    int findMaxForm(vector<string>& strs, int m, int n) {
        memset(dp,-1,sizeof(dp));
        return f(0,strs,m,n);
    }
};