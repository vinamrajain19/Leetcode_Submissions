class Solution {
public:
    
    bool allstars(string s,int i){
        for(int k = 0;k<=i;k++){
            if(s[k] != '*') return false;
        }
        return true;
    }
    
    bool help(string &s,string  &p,int i,int j,vector < vector < int >> & dp){
        
        //base cases
        
        // p -> exhausted and s -> exhausted
        if(i<0 and j<0) return true;
        
        // p -> exhausted and s -> not exhausted
        if(j<0 and i>=0) return false;
        
        // if p -> not exhausted and s -> exhausted
        if(j>=0 and i<0) return allstars(p,j);
        
        if(dp[i][j] != -1) return dp[i][j];
        
        
        //match
        if(p[j] == s[i] || p[j] == '?') return dp[i][j] = help(s,p,i-1,j-1,dp);
        
        //not match
        
        if(p[j] == '*'){
            return  dp[i][j] = help(s,p,i-1,j,dp) or help(s,p,i,j-1,dp);
        }
        
        else return false;
    
    }
    bool isMatch(string s, string p) {
        int n = s.size();
        int m = p.size();
        vector < vector < int >>  dp(n,vector<int>(m,-1));
        return help(s,p,n-1,m-1,dp);
    }
};