class Solution {
public:
    
  /*  bool allstars(string p,int j){
        for(int k = 1;k<=j;k++){
            if(p[k-1] != '*') return false;
        }
        return true;
    } */
    
  /*  bool help(string &s,string  &p,int i,int j,vector < vector < int >> & dp){
        
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
    */
    bool isMatch(string s, string p) {
        int n = s.size();
        int m = p.size();
        
        vector<bool> prev(m+1,false),curr(m+1,false);
        
        prev[0] = true;
        
        for(int j = 1;j<=m;j++){
            if(p[j-1] == '*')
                prev[j] = prev[j-1];
        }
        
        for(int i = 1;i<=n;i++){
            
            for(int j = 1;j<=m;j++){
                
                if(p[j-1] == s[i-1] or p[j-1] == '?'){
                    curr[j] = prev[j-1];
                }
                
                else if(p[j-1] == '*'){
                    curr[j] = prev[j] || curr[j-1];
                }
                else{
                    curr[j] = false;
                } 
                
            }
            prev = curr;
        }
        
        return prev[m];
    }
};