class Solution {
public:
    
    int dp[201][201];
    int f(vector<vector<int>> & t,int i,int j){
        
       // if(i >= t.size() or j >= t[0].size()) return 1e9;
        
        if(i == t.size()-1) return t[i][j];
        
        if(dp[i][j] != -1) return dp[i][j];
        
        int a = t[i][j] + f(t,i+1,j);
        int b = t[i][j] + f(t,i+1,j+1);
        
        return dp[i][j] =  min(a,b);
    
    }
    
    int minimumTotal(vector<vector<int>>& t) {
        memset(dp,-1,sizeof(dp));
        return f(t,0,0);
    }
};