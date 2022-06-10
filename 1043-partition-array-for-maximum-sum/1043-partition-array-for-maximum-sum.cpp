class Solution {
public:
    int min(int a,int b){
        if(a>b) return b;
        return a;
    }
    
    int f(int idx,vector<int> &arr,int k,vector<int> &dp){
        int n = arr.size();
        if(idx == n) return 0;
        
        if(dp[idx] != -1) return dp[idx];
        
        int len = 0;
        int maxi = -1e9;
        int ans = -1e9;
        for(int j = idx;(j<idx+k and j<n);j++){
            len++;
            maxi = max(maxi,arr[j]);
            int sum = (len*maxi) + f(j+1,arr,k,dp);
            ans = max(ans,sum);
        }
        return dp[idx] = ans;
    }
    
    int maxSumAfterPartitioning(vector<int>& arr, int k) {
        vector<int> dp(arr.size(),-1);
        return f(0,arr,k,dp);
    }
};