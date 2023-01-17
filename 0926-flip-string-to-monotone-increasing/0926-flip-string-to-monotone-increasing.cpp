class Solution {
public:
    
    int dp[100001][2];
    
    int f(string &s,int idx,char prev){
        
        if(idx >= s.size()) return 0;
        
        if(dp[idx][prev-'0'] != -1) return dp[idx][prev-'0'];
        
        int ans = 1e9;
        
        if(prev == '0'){
            if(s[idx] == '0'){
                ans = min({ans,f(s,idx+1,s[idx]),1+f(s,idx+1,'1')});
            }
            else{
                ans = min(ans,1+f(s,idx+1,'0'));
                ans = min(ans,f(s,idx+1,s[idx]));
            }
        }
                          
        else{
            if(s[idx] == '1'){
                ans = min(ans,f(s,idx+1,s[idx]));
            }
            else{
                ans = min(ans,1+f(s,idx+1,'1'));
            }
        }
        
        return dp[idx][prev-'0'] = ans;
        
    }
    
    int minFlipsMonoIncr(string s) {
        memset(dp,-1,sizeof(dp));
        
        return f(s,0,'0');
    }
};