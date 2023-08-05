class Solution {
public:
    int help(int i,int j,string s,string t,vector<vector<unsigned int>> &dp){
        
        if(j<0) return 1;
        if(i<0) return 0;
        
        if(dp[i][j] != -1) return dp[i][j];
        
        if(s[i] == t[j]) return dp[i][j] = help(i-1,j-1,s,t,dp) + help(i-1,j,s,t,dp);
        else return dp[i][j] =  help(i-1,j,s,t,dp);
    }
    int numDistinct(string s, string t) {
        int n = s.size();
        int m = t.size();
        vector<vector<unsigned int>> dp(n,vector<unsigned int>(m,-1));
        return help(n-1,m-1,s,t,dp);
    }
};