class Solution {
public:
    
    int dp[201][201];
    
    int f(vector<vector<int>> &d,int i,int j){
        if(i < 0 or j < 0 or i >= d.size() or j >= d[0].size()) return 1e9;
        
        
        if(i == d.size()-1 and j == d[0].size()-1) return d[i][j] < 0 ? 1 - d[i][j] : 1;
        
        if(dp[i][j] != -1) return dp[i][j];
        
        int a =  f(d,i+1,j);
        int b =  f(d,i,j+1);
        
        int t = min(a,b) - d[i][j];
        
        return dp[i][j] = t <= 0 ? 1 : t;
        
    }
    
    
    int calculateMinimumHP(vector<vector<int>>& d) {
        memset(dp,-1,sizeof(dp));
        return f(d,0,0);
    }
};