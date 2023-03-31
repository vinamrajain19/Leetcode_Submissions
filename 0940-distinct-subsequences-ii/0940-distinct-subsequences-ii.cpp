class Solution {
public:
    
    int dp[2001];
    int mod = 1e9+7;
    
    int f(string &s,int idx){
        if(idx == s.size()) return 0;
        
        if(dp[idx] != -1) return dp[idx];
        
        
        vector<int> v(26,0);
        
        int ans = 0;
        for(int i = idx;i<s.size();i++){
            if(v[s[i] - 'a'] == 1) continue;
            
            v[s[i] - 'a'] = 1;
            ans = (ans + 1 + f(s,i+1)) % mod;
        }
        
        return dp[idx] = ans % mod;
    }
    
    int distinctSubseqII(string s) {
        memset(dp,-1,sizeof(dp));
        return f(s,0);
        
    }
};