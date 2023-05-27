class Solution {
public:
    
    int dp[100001][3][3];
int f(const vector<int> &A,int idx,int buy,int cnt){
    
    if(cnt == 2) return 0;
    
    if(idx >= A.size()) return 0;
    
    if(dp[idx][buy][cnt] != -1) return dp[idx][buy][cnt];
    
    
    if(buy){
        return dp[idx][buy][cnt] =  max(-A[idx] + f(A,idx+1,0,cnt),f(A,idx+1,1,cnt));
    }
    else return dp[idx][buy][cnt] = max(A[idx] + f(A,idx+1,1,cnt+1),f(A,idx+1,0,cnt));
}
    int maxProfit(vector<int>& prices) {
        memset(dp,-1,sizeof(dp));
        return f(prices,0,1,0);
    }
};