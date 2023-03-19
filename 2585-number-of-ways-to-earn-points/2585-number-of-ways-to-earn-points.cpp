class Solution {
public:
    int mod = 1e9+7;
    
    int dp[51][1001];
    
    int f(vector<vector<int>> &types,int target,int idx){
        
        if(target == 0) return 1;
        if(target < 0 or idx  >= types.size()) return 0;
        
        if(dp[idx][target] != -1) return dp[idx][target];
        
        int take = 0;
        
        for(int i = 0;i<=types[idx][0];i++){
            
            int temp = i * types[idx][1];
            take = (take +  f(types,target-temp,idx+1))%mod;
            
        }
        
        return dp[idx][target] = take%mod;
    }
    
    int waysToReachTarget(int target, vector<vector<int>>& types) {
        memset(dp,-1,sizeof(dp));
        return f(types,target,0);
    }
};