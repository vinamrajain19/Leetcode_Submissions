class Solution {
public:
    
    int dp[201][201];
    
    int mod = 1e9+7;
    
    int f(string &s,int ind,int curr,vector<int> &vis){
        
        if(ind == s.size()) return 1;
        
        if(dp[ind][curr] != -1) return dp[ind][curr];
        
        
        int ans = 0;
        
        vis[curr] = 1;
        
        if(s[ind] == 'I'){
            for(int i = curr+1;i<=s.size();i++){
                if(vis[i] == 0) ans = (ans + f(s,ind+1,i,vis)) % mod;
            }
        }
        else{
            for(int i = curr-1;i>=0;i--){
                if(vis[i] == 0) ans = (ans + f(s,ind+1,i,vis)) % mod;
            }
        }
        
        vis[curr] = 0;
        return dp[ind][curr] =  ans % mod;
    }
    
    int numPermsDISequence(string s) {
        int ans = 0;
        
        memset(dp,-1,sizeof(dp));
        
        vector<int> vis(s.size()+1,0);
        
        for(int i = 0;i<=s.size();i++){
            ans = (ans + f(s,0,i,vis))% mod;
        }
        
        return ans % mod;
    }
};