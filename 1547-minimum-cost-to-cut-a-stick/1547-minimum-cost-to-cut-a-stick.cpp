class Solution {
public:
    int f(int n, vector<int>& cuts,int i,int j,vector<vector<int>> &dp){
        if(i>j) return 0;
        
        if(dp[i][j] != -1) return dp[i][j];
        
        int mn = 1e9;
        for(int k = i;k<=j;k++){
            
            int temp = cuts[j+1] - cuts[i-1] + f(n,cuts,i,k-1,dp) + f(n,cuts,k+1,j,dp);
            mn = min(mn,temp);
        }
        
        return dp[i][j] = mn;
    }
    
    int minCost(int n, vector<int>& cuts) {
        
        int x = cuts.size();
        
        cuts.push_back(0);
        cuts.push_back(n);
        sort(cuts.begin(),cuts.end());
        
        vector<vector<int>> dp(x+1,vector<int>(x+1,-1));
        
        return f(n,cuts,1,x,dp);
    }
};