class Solution {
public:
    bool f(string s,int idx,unordered_set<string> &d,vector<int> &dp){
        
        if(idx == s.size()){
            return true;
        }
        
        
        if(dp[idx] != -1) return dp[idx];
        
        
        for(int k = idx;k<s.size();k++){
            if(d.find(s.substr(idx,k-idx + 1)) != d.end()){
                //present
                if(f(s,k+1,d,dp)) return dp[idx] = true;
            }
        }
        
        return dp[idx] = false;
    }
    
    bool wordBreak(string s, vector<string>& word) {
        unordered_set<string> d(word.begin(),word.end());
        vector<int> dp(s.size(),-1);
        return f(s,0,d,dp);
    }
};