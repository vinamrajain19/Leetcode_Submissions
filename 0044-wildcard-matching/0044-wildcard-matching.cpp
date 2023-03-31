class Solution {
public:
    
    int dp[2001][2001];
    
    
    int f(string s,string p,int i,int j){
        
        if(i == 0 and j == 0) return true; 
        
        if(i > 0 and j == 0) return false;
        
        if(i == 0 and  j > 0){
            while(j > 0){
                if(p[j-1] != '*') return false;
                j--;
            }
            return true;
        }
        
        if(dp[i][j] != -1) return dp[i][j];
        
        
        if(s[i-1] == p[j-1] or p[j-1] == '?') return dp[i][j] =  f(s,p,i-1,j-1);
        
        if(p[j-1] == '*'){
            return dp[i][j] = f(s,p,i-1,j) or f(s,p,i,j-1);
        }
        
        return dp[i][j] =  false;
       
    }
    
    bool isMatch(string s, string p) {
        vector<bool> prev(p.size()+1,0);
        vector<bool> curr(p.size()+1,0);
        
        prev[0] = 1;
        
       // for(int i = 1;i<=s.size();i++) prev[i] = 0;
        
        for(int j = 1;j<=p.size();j++){
            if(p[j-1] == '*')
                prev[j] = prev[j-1];
        }
        
        
        for(int i = 1;i<=s.size();i++){
            for(int j = 1;j<=p.size();j++){
                
                if(s[i-1] == p[j-1] or p[j-1] == '?'){
                    curr[j] = prev[j-1];
                }
                
                else if(p[j-1] == '*'){
                    curr[j] = prev[j] or curr[j-1];
                }
                else{
                    curr[j] = 0;
                }
            }
            
            prev = curr;
        }
        
        
        return prev[p.size()];
        
        
    }
};