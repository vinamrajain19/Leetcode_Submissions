class Solution {
public:
    
    int dp[501][502];
    int f(vector<int> &s,int idx,int time){
        
        if(idx >= s.size()) return 0;
        
        if(dp[idx][time] != -1) return dp[idx][time];
        
        
        int a = (s[idx] * time) + f(s,idx+1,time+1);
        int b = f(s,idx+1,time);
        
        return dp[idx][time] =  max(a,b);
    }
    
    
    int maxSatisfaction(vector<int>& s) {
        memset(dp,-1,sizeof(dp));
        sort(s.begin(),s.end());
        return f(s,0,1);
    }
};