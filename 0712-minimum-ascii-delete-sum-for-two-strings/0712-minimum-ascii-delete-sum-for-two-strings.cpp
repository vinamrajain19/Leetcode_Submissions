class Solution {
public:
    
    
    int dp[1001][1001];
    
    int f(string &s1,string &s2,int i,int j){
        if(i >= s1.size() or j>= s2.size()) return 0;
        
        if(dp[i][j] != -1) return dp[i][j];
        
        if(s1[i] == s2[j]){
            return dp[i][j] = s1[i] + f(s1,s2,i+1,j+1);
        }
        else{
            return dp[i][j] =  max(f(s1,s2,i+1,j),f(s1,s2,i,j+1));
        }
    }
    
    int minimumDeleteSum(string s1, string s2) {
        int fi = 0;
        int s = 0;
        
        for(auto it : s1) fi += it;
        for(auto it : s2) s += it;
        
        memset(dp,-1,sizeof(dp));
        int lcs = f(s1,s2,0,0);
        
        return fi + s - 2 * lcs;
    }
};