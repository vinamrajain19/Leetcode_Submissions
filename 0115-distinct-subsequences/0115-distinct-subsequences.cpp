class Solution {
public:
    
    int dp[1001][1001];
    int f(string s,string t,int i,int j){
        if(j < 0) return 1;
        if(i < 0) return 0;
        if(dp[i][j] != -1) return dp[i][j];
        
        int a = 0;
        
        if(s[i] == t[j]){
            a = f(s,t,i-1,j-1);
        }
        int b = f(s,t,i-1,j);
        
        return dp[i][j] = a+b;
    }
    
    int numDistinct(string s, string t) {
        memset(dp,-1,sizeof(dp));
        return f(s,t,s.size()-1,t.size()-1);
    }
};