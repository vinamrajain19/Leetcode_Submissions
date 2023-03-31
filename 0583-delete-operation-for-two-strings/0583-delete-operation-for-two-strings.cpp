class Solution {
public:
    int dp[501][501];
    int f(string s,string t,int i,int j){
        if(i == 0 or j == 0) return 0;
        
        if(dp[i][j] != -1) return dp[i][j];
        
        if(s[i-1] == t[j-1]){
            return dp[i][j] =  1 + f(s,t,i-1,j-1);
        }
        
        return dp[i][j] =  max(f(s,t,i-1,j),f(s,t,i,j-1));
    }
    int minDistance(string word1, string word2) {
        memset(dp,-1,sizeof(dp));
        
        int l = f(word1,word2,word1.size(),word2.size());
        
        return (word1.size() - l) + (word2.size() - l);
    }
};