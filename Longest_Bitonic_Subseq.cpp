int longestBitonicSequence(vector<int>& arr, int n) {
    
        vector<int> dp(n,1);
        for(int i = 0;i<n;i++){
            for(int j = 0;j<i;j++){
                if((arr[i] > arr[j]) && dp[j] + 1 > dp[i]){
                    dp[i] = 1 + dp[j];
                }
            }
        }
    
        vector<int> dp2(n,1);
        for(int i = n-1;i>=0;i--){
            for(int j = n-1; j>i;j--){
                if((arr[i] > arr[j]) && dp2[j] + 1 > dp2[i]){
                    dp2[i] = 1 + dp2[j];
                }
            }
        }
       int ans = 0;
       for(int i = 0;i<n;i++){
           ans = max(ans,dp[i] + dp2[i] - 1);
       }
    return ans;
} 
