class Solution {
public:
    
    long long dp[105][105];
    
    long long f(int n,vector<int> &cuts,int i,int j){
        
        if(i > j) return 0;
        
        if(dp[i][j] != -1) return dp[i][j];
        
        
        long long ans = INT_MAX;
        for(int k = i;k<=j;k++){
            long long temp = cuts[j+1] -  cuts[i-1] + f(n,cuts,i,k-1) + f(n,cuts,k+1,j);
            ans = min(ans,temp);
        }
        
        return dp[i][j] =  ans;
    }
    
    int minCost(int n, vector<int>& cuts) {
        memset(dp,-1,sizeof(dp));
        int x = cuts.size();
         cuts.push_back(n);
        cuts.insert(cuts.begin(),0);
        sort(cuts.begin(),cuts.end());
        return f(n,cuts,1,x);
    }
};