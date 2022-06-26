class Solution {
public:
    int f(vector<int> &piles,int i,int j,vector<vector<int>> &dp){
        
        if(i>=j) return 0;
        
        if(dp[i][j] != -1) return dp[i][j];
        
        int fi = piles[i] + max(f(piles,i+2,j,dp) ,f(piles,i+1,j-1,dp));
        int se = piles[j] + max(f(piles,i,j-2,dp) , f(piles,i+1,j-1,dp));
        
        return dp[i][j] = max(fi,se);
    }    
    
    bool stoneGame(vector<int>& piles) {
        vector<vector<int>> dp(piles.size()+1,vector<int>(piles.size()+1,-1));
        int sum = 0;
        for(int i=0;i<piles.size();i++) sum += piles[i];
        int alice = f(piles,0,piles.size()-1,dp);
        int bob = sum - alice;
        
        if(alice > bob) return true;
        return false;
    }
};