class Solution {
public:
    
    int dp[101][101];
    
    bool f(string &s1,string &s2,string &s3,int i,int j){
        int k = i + j;
        
        if(k == s3.size() and i == s1.size() and j == s2.size()) return true;
        
        if(k >= s3.size()) return false;
        
        if(dp[i][j] != -1) return dp[i][j];
        
        
        bool a = false,b=false;
        
        if(s3[k] == s1[i]){
            a = f(s1,s2,s3,i+1,j);
        }
        
        if(s3[k] == s2[j]) b = f(s1,s2,s3,i,j+1);
        
        return dp[i][j] =  a or b;
        
    }
    
    bool isInterleave(string s1, string s2, string s3) {
        if(s1.size() + s2.size() != s3.size()) return false;
        memset(dp,-1,sizeof(dp));
        return f(s1,s2,s3,0,0);
    }
};