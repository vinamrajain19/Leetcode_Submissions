class Solution {
public:
    
    // for every pile we have -> take 0 to k coins from it
    int dp[1001][2001];
    
    int f(int idx,int k,vector<vector<int>> &piles){
        if(k == 0) return 0;
        if(idx == piles.size()) return -1e9;
     
        if(dp[idx][k] != -1) return dp[idx][k];
        
        int no = f(idx+1,k,piles);
        
        int take = -1e9;
        int sum = 0;
        for(int i = 0;i<piles[idx].size() and i < k;i++){
            sum += piles[idx][i];
            take = max(take,sum+f(idx+1,k-i-1,piles));
        }
        return dp[idx][k] = max(take,no);
                    
    }
    
    int maxValueOfCoins(vector<vector<int>>& piles, int k) {
        memset(dp,-1,sizeof(dp));
        return f(0,k,piles);
    }
};