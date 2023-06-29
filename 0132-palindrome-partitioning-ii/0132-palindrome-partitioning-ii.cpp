class Solution {
public:
    
    bool ispalindrome(string &s,int i,int j){
        while(i<j){
            if(s[i] != s[j]) return false;
            i++;
            j--;
        }
        return true;
    }
    
    int f(string &s,int i,vector<int> &dp){
        
        if(i == s.size()) return 0;
        if(dp[i] != -1) return dp[i];
    
        int mn = 1e9;
        for(int j = i;j<s.size();j++){
            if(ispalindrome(s,i,j)){
                int cost = 1 + f(s,j+1,dp);
                mn  = min(mn,cost);
            }
        }
        return dp[i] = mn;
    }
    


    int minCut(string s) {
        vector<int> dp(s.size(),-1);
        return f(s,0,dp)-1;
    }
};