class Solution {
public:
    int dp[301][11];
    int f(vector<int> &j,int d,int idx){
        
        if(idx == j.size() and d == 0) return 0;
        if(d < 0) return 1e9;
        
        if(dp[idx][d] != -1) return dp[idx][d];
        
        int mx = -1e9;
        int ans = 1e9;
        
        for(int i = idx;i<j.size();i++){
            mx = max(mx,j[i]);
            ans = min(ans,mx + f(j,d-1,i+1));
        }
        
        return dp[idx][d] = ans;
    }
    
    int minDifficulty(vector<int>& j, int d) {
        if(d > j.size()) return -1;
        memset(dp,-1,sizeof(dp));
        return f(j,d,0);
    }
};