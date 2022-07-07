class Solution {
public:
     bool f(string s1,string s2,string s3,int i,int j,vector<vector<int>> &dp){
        if(i+j == s3.size() and i == s1.size() and j == s2.size()) return true;
        
        if(i+j == s3.size()) return false;
       
        if(dp[i][j] != -1) return dp[i][j];
        
        bool first = false;
        bool sec = false;
        
        if(s1[i] == s3[i+j]){
            first = f(s1,s2,s3,i+1,j,dp);
        }
        
        if(s2[j] == s3[i+j]){
            sec = f(s1,s2,s3,i,j+1,dp);
        }
        
        return dp[i][j] = first or sec;
    }
    
    bool isInterleave(string s1, string s2, string s3) {
        vector<vector<int>> dp(s1.size() + 1,vector<int>(s2.size() + 1,-1));
        return f(s1,s2,s3,0,0,dp);
    }
};