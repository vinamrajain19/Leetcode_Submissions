int matrixMultiplication(vector<int> &arr, int N)
{
    vector<vector<int>> dp(N,vector<int>(N,0));
    
    for(int i = N-1;i >= 1;i--){
        for(int j = i + 1;j<=N-1;j++){
            int mn = 1e9;
            for(int k = i;k<=j-1;k++){
                int temp = arr[i-1] * arr[k]  * arr[j] + dp[i][k] + dp[k+1][j];
                mn = min(mn,temp);
            }
            dp[i][j] = mn;
        }
    }
    return dp[1][N-1];
}
