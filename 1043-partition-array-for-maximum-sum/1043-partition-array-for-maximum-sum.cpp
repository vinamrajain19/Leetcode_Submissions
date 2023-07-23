class Solution {
public:
    
    int dp[501];
        
    int f(vector<int> &arr,int k,int idx){
        if(idx >= arr.size()) return 0;
        
        if(dp[idx] != -1) return dp[idx];
        
        
        int mx = -1e9;
        int size = 0;
        int ans = -1e9;
        int n = arr.size();
        
        
        for(int i = idx;i<min(n,idx+k);i++){
            size++;
            mx = max(mx,arr[i]);
            int t = size * mx + f(arr,k,i+1);
            ans = max(ans,t);
        }
        
        return dp[idx] =  ans;
    }
    
    int maxSumAfterPartitioning(vector<int>& arr, int k) {
        memset(dp,-1,sizeof(dp));
        return f(arr,k,0);
    }
};