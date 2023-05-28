class Solution {
public:
    unordered_map<string,int> m;
   
    int f(string &s,int idx,vector<int> &dp){
        
        if(idx>=s.size()){
            return 0;
        }
        
        
        if(dp[idx]!=-1){
            return dp[idx];
        }      
       
        string t="";
        int ans=f(s,idx+1,dp);
        
        for(int i=idx ; i<s.size() ; i++){
            t+=s[i];
            if(m[t]){
                ans=max(ans,(int)t.size()+(int)f(s,i+1,dp));
            }
        }
        return dp[idx]=ans;
    }
    
    int minExtraChar(string s, vector<string>& dictionary) {
        int n=s.size();
        
        vector<int> dp(n+1,-1);
        for(auto it : dictionary) m[it]++;
        return n-f(s,0,dp);
    }
};