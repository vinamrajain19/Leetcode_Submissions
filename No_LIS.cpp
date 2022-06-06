int findNumberOfLIS(vector<int> &arr)
{
    int n = arr.size();
    vector<int> dp(n,1),cnt(n,1);
    int ans = INT_MIN;
    for(int i = 0;i<n;i++){
        for(int j = 0;j<i;j++){
            if(arr[j] < arr[i] and 1 + dp[j] > dp[i]){
                dp[i] = 1 + dp[j];
                //inherit
                cnt[i] = cnt[j];
            }
            else if (arr[j] < arr[i] and 1 + dp[j] == dp[i]){
                //increase the count
                cnt[i] += cnt[j];
            }
        }
        ans = max(ans,dp[i]);
    }
    int no = 0;
    for(int i = 0;i<n;i++){
        if(dp[i] == ans){
            no += cnt[i];
        }
    }
    return no;
}
