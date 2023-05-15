class Solution {
public:
    
    int dp1[501][171];
    int dp2[501][171];
    
    int f(vector<int> &slices,int idx,int cnt,int end,int dp[501][171]){
        
        int n = slices.size();
        
        if(idx >= end) return 0;
        
        if(cnt == (n/3)) return 0;
        
        if(dp[idx][cnt] != -1) return dp[idx][cnt];
        
        
        int a = max(slices[idx] + f(slices,idx+2,cnt+1,end,dp),f(slices,idx+1,cnt,end,dp));
        
        return dp[idx][cnt] = a;
    }
    
    
    int maxSizeSlices(vector<int>& slices) {
        memset(dp1,-1,sizeof(dp1));
        memset(dp2,-1,sizeof(dp2));
        return max(f(slices,0,0,slices.size()-1,dp1),f(slices,1,0,slices.size(),dp2));
    }
};